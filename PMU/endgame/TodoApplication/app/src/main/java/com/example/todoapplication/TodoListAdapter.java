package com.example.todoapplication;

import android.app.AlertDialog;
import android.content.Context;
import android.content.DialogInterface;
import android.graphics.Color;
import android.graphics.Typeface;
import android.support.annotation.NonNull;
import android.support.v7.widget.RecyclerView;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;
import android.widget.TextView;
import android.widget.Toast;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;

public class TodoListAdapter extends RecyclerView.Adapter<TodoListAdapter.ViewHolder> {

    // Store a member variable for the contacts
    private List<Todo> todo_list;
    private String date;
    private TodoFilter filter;
    List<Todo> filtered_list = new ArrayList<Todo>();
    // Pass in the contact array into the constructor
    public TodoListAdapter(List<Todo> todo_list, String date, TodoFilter filter) {
        this.todo_list = todo_list;
        Collections.sort(this.todo_list, new Comparator<Todo>() {
            @Override
            public int compare(Todo o1, Todo o2) {
                if (o1.getPriority() > o2.getPriority()) return -1;
                if (o1.getPriority() < o2.getPriority()) return 1;
                else return 0;
            }
        });
        this.filter = filter;
        this.date = date;
    }

    private void updateList(){
        FileSystem.writeToFile(todo_list, date);
        notifyDataSetChanged();
    }
    private void removeTodoElement(Todo element)
    {
        this.todo_list.remove(element);
        updateList();
    }
    @NonNull
    @Override
    public ViewHolder onCreateViewHolder(@NonNull ViewGroup viewGroup, int i) {
        Context context = viewGroup.getContext();
        LayoutInflater inflater = LayoutInflater.from(context);

        // Inflate the custom layout
        View todoView = inflater.inflate(R.layout.item_todo, viewGroup, false);

        // Return a new holder instance
        ViewHolder viewHolder = new ViewHolder(todoView);
        return viewHolder;
    }

    @Override
    public void onBindViewHolder(@NonNull final ViewHolder viewHolder, int position) {
        // Get the data model based on position
        final Todo todo = filtered_list.get(position);

        viewHolder.todo_name_view.setText(todo.getName());
        viewHolder.todo_name_view.setTextColor(Color.BLACK);
        viewHolder.todo_name_view.setTypeface(null, Typeface.BOLD);
        viewHolder.todo_name_view.setOnClickListener(new View.OnClickListener(){
            private Boolean is_description_set = false;
            @Override
            public void onClick(View v) {
                if(is_description_set) {
                    viewHolder.todo_name_view.setText(todo.getName());
                    viewHolder.todo_name_view.setTextColor(Color.BLACK);
                    viewHolder.todo_name_view.setTypeface(null, Typeface.BOLD);
                }
                else {
                    viewHolder.todo_name_view.setText(todo.getDescription());
                    viewHolder.todo_name_view.setTextColor(Color.BLUE);
                    viewHolder.todo_name_view.setTypeface(null, Typeface.ITALIC);
                }
                is_description_set = !is_description_set;
            }
        });
        if(!todo.getStatus()) {
            viewHolder.done_button.setText("Done");
        }else {
            viewHolder.done_button.setText("Undo");
        }
        viewHolder.todo_id_view.setText(Integer.toString(position+1));
        viewHolder.todo_priority_view.setText(Double.toString(todo.getPriority()));
        viewHolder.delete_button.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                final Button current_button = (Button)v;
                final int todo_id = Integer.parseInt(viewHolder.todo_id_view.getText().toString())-1;
                AlertDialog.Builder delete_check = new AlertDialog.Builder(current_button.getContext()); //
                delete_check.setTitle("Are you sure?");
                delete_check.setMessage("Are you sure you want to delete todo with ID " + todo_id);
                delete_check.setIcon(android.R.drawable.ic_dialog_alert);
                delete_check.setPositiveButton(android.R.string.yes, new DialogInterface.OnClickListener() {

                    public void onClick(DialogInterface dialog, int whichButton) {
                        removeTodoElement(todo);
                        Toast.makeText(current_button.getContext(), "Deleted todo with id " + todo_id, Toast.LENGTH_SHORT).show();
                    }});
                delete_check.setNegativeButton(android.R.string.no, null).show();

            }
        });
        viewHolder.done_button.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                int todo_id = Integer.parseInt(viewHolder.todo_id_view.getText().toString())-1;
                Button current_button = (Button)v;
                if(todo.getStatus()) {
                    current_button.setText("Done");
                    todo.setStatus(false);
                }else {
                    current_button.setText("Undo");
                    todo.setStatus(true);
                }
                updateList();
            }
        });
    }

    @Override
    public int getItemCount() {
        filtered_list = new ArrayList<>(todo_list);
        for(Todo todo : todo_list) {
            if(filter.filter(todo)){
                filtered_list.remove(todo);
            }
        }
        return filtered_list.size();
    }

    public class ViewHolder extends RecyclerView.ViewHolder {
        public TextView todo_id_view;
        public TextView todo_name_view;
        public TextView todo_priority_view;
        public Button delete_button;
        public Button done_button;

        public ViewHolder(View itemView) {
            super(itemView);

            todo_id_view = (TextView) itemView.findViewById(R.id.todo_id_view);
            todo_name_view = (TextView) itemView.findViewById(R.id.todo_name_view);
            todo_priority_view = (TextView) itemView.findViewById(R.id.todo_priority_view);
            delete_button = (Button) itemView.findViewById(R.id.delete_button);
            done_button = (Button) itemView.findViewById(R.id.done_button);

        }
    }
}
