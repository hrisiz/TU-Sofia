import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class Main {

	public static void main(String[] args) {
		String str_pattern = "word"; // ^[a-z0-9_-]*a+
		String str = "userwordnamea"; //usernamea
		try{
			Regex reg = new Regex(str_pattern);
			System.out.println("My RegEx Result: " + reg.match(str));
		}catch(RegExException e){
			System.out.println(e.getMessage());
		}
		
		Pattern pattern = Pattern.compile(str_pattern);
		Matcher matcher = pattern.matcher(str);
		
		System.out.println("Real RegEx Result: " + matcher.matches());
	}

}
