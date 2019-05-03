package com.example.todoapplication;

import android.app.DatePickerDialog;
import android.graphics.Color;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.DatePicker;
import android.widget.TextView;

import org.w3c.dom.Text;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Calendar;
import java.util.Date;
import java.util.List;

public class CreateTodo extends AppCompatActivity {

    final private List<Todo> getTodoList()
    {
        List<Todo> todo_list = new ArrayList<Todo>();
        try {
            File objects_file = new File(getExternalFilesDir(null),"myObjects.txt");

            FileInputStream fi = new FileInputStream(objects_file);
            ObjectInputStream oi = new ObjectInputStream(fi);

            // Read objects
            while (true){
                try {
                    System.out.println("Hello");
                    Todo new_todo = (Todo) oi.readObject();
                    System.out.println(new_todo.getName());
                    todo_list.add(new_todo);
                } catch (Exception e) {
                    System.out.println("EndOfFile");
                    break;
                }
            }
            oi.close();
            fi.close();

        } catch (FileNotFoundException e) {
            System.out.println("File not found");
            e.printStackTrace();
        } catch (IOException e) {
            System.out.println("Error initializing stream");
            e.printStackTrace();
        }
        return todo_list;
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_create_todo);

        final TextView date_field = findViewById(R.id.date_input);
        final TextView name_field = findViewById(R.id.name_input);
        final TextView description_field = findViewById(R.id.description_input);
        final TextView priority_field = findViewById(R.id.priority_input);
        final Calendar c = Calendar.getInstance();
        final DatePickerDialog date_picker = new DatePickerDialog(this, new DatePickerDialog.OnDateSetListener() {
            @Override
            public void onDateSet(DatePicker arg0, int year, int month, int day) {
                date_field.setText(year + "/" + (month+1) + "/" + day);
                date_field.setError(null);
            }
        }, c.get(Calendar.YEAR), c.get(Calendar.MONTH), c.get(Calendar.DAY_OF_MONTH));
        date_field.setText(c.get(Calendar.YEAR) + "/" + (c.get(Calendar.MONTH)+1) + "/" + Integer.toString(c.get(Calendar.DAY_OF_MONTH)));



        Button create_button = findViewById(R.id.ceate_button);

        date_field.setOnFocusChangeListener(new View.OnFocusChangeListener(){
            @Override
            public void onFocusChange(View v, boolean hasFocus) {
                if(hasFocus) {
                    date_picker.show();
                }
            }
        });
        create_button.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Todo new_todo = new Todo();
                String name = name_field.getText().toString();
                if(name.isEmpty())
                {
                    name_field.setError("This field cannot be empty");
                    return;
                }
                new_todo.setName(name);
                new_todo.setDescription(description_field.getText().toString());
                String date = date_field.getText().toString();
                String priority = priority_field.getText().toString();
                if(!priority.isEmpty()) {
                    new_todo.setPriority(Double.parseDouble(priority));
                }
                else
                {
                    priority_field.setError("This field cannot be empty");
                    return;
                }

                List<Todo> todo_list = FileSystem.readFromFile(date);
                todo_list.add(new_todo);
                FileSystem.writeToFile(todo_list, date);

                finish();
            }
        });

        Button cancel_button = findViewById(R.id.cancel_button);
        cancel_button.setOnClickListener(new View.OnClickListener() {

            @Override
            public void onClick(View v) {
                finish();
            }
        });
    }
}
