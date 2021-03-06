import java.io.Serializable;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class User implements Serializable{
	/**
	 * 
	 */
	private static final long serialVersionUID = -231609387047971768L;
	private String username;
	private static final String userRegEx = "[a-zA-Z][a-zA-Z1-9_-]{5,19}";
	private String password;
	private static final String passRegEx = "[a-zA-Z1-9_-]{6,20}";
	
	private boolean check(String str,String regex){
		Pattern pattern = Pattern.compile(regex);
		Matcher matcher = pattern.matcher(str);
		return matcher.matches();
	}
	
	public User(String name,String password) throws UserException {
		if(!this.check(name,userRegEx)){
			throw new UserException("Wrong UserName");
		}
		if(!this.check(password,passRegEx)){
			throw new UserException("Wrong Password");
		}
		this.username = name;
		this.password = password;
	}
	
	@Override
	public String toString(){
		return this.username;
	}
	public boolean equals(User user){
		if(this.username.equals(user.username)){
			if(this.password.equals(user.password)){
				return true;
			}
		}
		return false;
	}
}
