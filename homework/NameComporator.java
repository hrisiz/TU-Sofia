package homework;

import java.util.Comparator;

public class NameComporator implements Comparator <Student>{
public int compare(Student o1,Student o2){
	String firstName=o1.getName().toUpperCase();
	String secondName=o2.getName().toUpperCase();
	return firstName.compareTo(secondName);
}
}
