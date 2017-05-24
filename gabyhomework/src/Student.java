

import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class Student implements Validator{
	private Pattern p;
	private Matcher m;
	private String name;
	private int age;
	public Student(String name, int age) throws WrongNameException{
		validateName(name);
		this.age=age;
	}
	public String getName() {
		return name;
	}
	public void setName(String name){
		this.name=name;
	}
	public int getAge() {
		return age;
	}
	public void setAge(int age) {
		this.age = age;
	}
	
	
	@Override
	public void validateName(String name) throws WrongNameException {
		p = Pattern.compile("[a-zA-Z]+");
		m = p.matcher(name);
		if (m.matches()){
			this.name=name;
		}
		else {
			throw new WrongNameException();
		}
	}
}



