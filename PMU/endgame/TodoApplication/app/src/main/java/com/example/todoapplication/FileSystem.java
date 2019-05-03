package com.example.todoapplication;

import android.os.Environment;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.util.ArrayList;
import java.util.List;

public class FileSystem {
    static public void writeToFile(List<Todo> todo_list, String date) {
        date = date.replace("/","_");
        try {
            File objects_file = new File(Environment.getExternalStorageDirectory(), "Todo" + date + ".list");
            objects_file.createNewFile();
            FileOutputStream f = new FileOutputStream(objects_file);
            ObjectOutputStream o = new ObjectOutputStream(f);
            for(Todo element : todo_list)
            {
                o.writeObject(element);
            }

            o.close();
            f.close();

        } catch (FileNotFoundException e) {
            System.out.println("File not found");
            e.printStackTrace();
        } catch (IOException e) {
            System.out.println("Error initializing stream");
            e.printStackTrace();
        }
    }

    static public List<Todo> readFromFile(String date) {
        date = date.replace("/","_");
        List<Todo> todo_list = new ArrayList<Todo>();
        try {
            File objects_file = new File(Environment.getExternalStorageDirectory(),"Todo" + date + ".list");

            FileInputStream fi = new FileInputStream(objects_file);
            ObjectInputStream oi = new ObjectInputStream(fi);

            // Read objects
            while (true){
                try {
                    Todo new_todo = (Todo) oi.readObject();
                    todo_list.add(new_todo);
                } catch (Exception e) {
                    break;
                }
            }
            oi.close();
            fi.close();

        } catch (FileNotFoundException e) {
            System.out.println("Read file not found");
            e.printStackTrace();
        } catch (IOException e) {
            System.out.println("Error initializing read stream");
            e.printStackTrace();
        }
        return todo_list;
    }
}
