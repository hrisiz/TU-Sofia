package com.example.todoapplication;

import android.Manifest;
import android.app.DatePickerDialog;
import android.content.Context;
import android.content.Intent;
import android.content.pm.PackageManager;
import android.os.Bundle;
import android.support.design.widget.FloatingActionButton;
import android.support.design.widget.TabLayout;
import android.support.v4.app.ActivityCompat;
import android.support.v4.content.ContextCompat;
import android.support.v7.app.AppCompatActivity;
import android.support.v7.widget.LinearLayoutManager;
import android.support.v7.widget.RecyclerView;
import android.support.v7.widget.Toolbar;
import android.view.View;
import android.view.Menu;
import android.view.MenuItem;
import android.widget.Button;
import android.widget.DatePicker;
import android.widget.TextView;

import org.w3c.dom.Text;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.util.ArrayList;
import java.util.Calendar;
import java.util.List;


public class MainActivity extends AppCompatActivity {

    private void reloadTodoList(String date)
    {
        RecyclerView todo_list_view_field = (RecyclerView) findViewById(R.id.todo_list_view);

        TabLayout todo_list_type = (TabLayout) findViewById(R.id.todo_list_type);
        TodoFilter filter;
        switch(todo_list_type.getSelectedTabPosition()) {
            case 0:
                filter = new TodoFilter() {
                    @Override
                    public Boolean filter(Todo todo) {
                        return todo.getStatus();
                    }
                };
                break;

            case 1:
                filter = new TodoFilter() {
                    @Override
                    public Boolean filter(Todo todo) {
                        return !todo.getStatus();
                    }
                };
                break;
            default:
                filter = new TodoFilter() {
                    @Override
                    public Boolean filter(Todo todo) {
                        return false;
                    }
                };
                break;
        }
        TodoListAdapter adapter = new TodoListAdapter(FileSystem.readFromFile(date), date, filter);

        todo_list_view_field.setAdapter(adapter);
        // Set layout manager to position the items
        todo_list_view_field.setLayoutManager(new LinearLayoutManager(this));
    }
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        if (ContextCompat.checkSelfPermission(this, Manifest.permission.WRITE_CALENDAR)
                != PackageManager.PERMISSION_GRANTED) {
            int a = 0;
            ActivityCompat.requestPermissions(this,
                    new String[]{Manifest.permission.WRITE_EXTERNAL_STORAGE}, a);
        }

        setContentView(R.layout.activity_main);
        Toolbar toolbar = findViewById(R.id.toolbar);
        setSupportActionBar(toolbar);


        TabLayout tabs = (TabLayout) findViewById(R.id.todo_list_type);

        tabs.addOnTabSelectedListener(new TabLayout.OnTabSelectedListener() {
            @Override
            public void onTabSelected(TabLayout.Tab tab) {
                reloadTodoList(((TextView)(findViewById(R.id.current_date_list))).getText().toString());
            }

            @Override
            public void onTabUnselected(TabLayout.Tab tab) {

            }

            @Override
            public void onTabReselected(TabLayout.Tab tab) {
                reloadTodoList(((TextView)(findViewById(R.id.current_date_list))).getText().toString());
            }
        });

        final TextView date_field = (TextView) findViewById(R.id.current_date_list);
        final Calendar c = Calendar.getInstance();
        final DatePickerDialog date_picker = new DatePickerDialog(this, new DatePickerDialog.OnDateSetListener() {
            @Override
            public void onDateSet(DatePicker arg0, int year, int month, int day) {
                String date = year + "/" + (month+1) + "/" + day;
                date_field.setText(date);
                reloadTodoList(date);
            }
        }, c.get(Calendar.YEAR), c.get(Calendar.MONTH), c.get(Calendar.DAY_OF_MONTH));
        date_field.setText(c.get(Calendar.YEAR) + "/" + (c.get(Calendar.MONTH)+1) + "/" + Integer.toString(c.get(Calendar.DAY_OF_MONTH)));
        date_field.setOnClickListener(new View.OnClickListener(){
            @Override
            public void onClick(View v) {
                date_picker.show();
            }
        });

        this.reloadTodoList(date_field.getText().toString());

        FloatingActionButton fab = findViewById(R.id.fab);
        fab.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                startActivity(new Intent(getApplicationContext(), CreateTodo.class));
            }
        });

    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        // Inflate the menu; this adds items to the action bar if it is present.
        getMenuInflater().inflate(R.menu.menu_main, menu);
        return true;
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        // Handle action bar item clicks here. The action bar will
        // automatically handle clicks on the Home/Up button, so long
        // as you specify a parent activity in AndroidManifest.xml.
        int id = item.getItemId();

        //noinspection SimplifiableIfStatement
        if (id == R.id.action_settings) {
            return true;
        }

        return super.onOptionsItemSelected(item);
    }

    @Override
    protected void onResume() {
        super.onResume();
        this.reloadTodoList(((TextView)(findViewById(R.id.current_date_list))).getText().toString());
    }
}
