

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class Test {
	public static void main(String[] args){
		try{
			List<Student> listStudent = new ArrayList<Student>();
			listStudent.add(new Student("Georgi1",20));
			listStudent.add(new Student("Dayana", 21));
			listStudent.add(new Student("Desislava",25));
			listStudent.add(new Student("Victor",23));
		
			Collections.sort(listStudent, new NameComporator());
			for(Student s:listStudent){
				System.out.println(s.getName() +" " +s.getAge());
			}
		}catch(WrongNameException e){
			System.out.println(e.getMessage());
		}
	}	
}


