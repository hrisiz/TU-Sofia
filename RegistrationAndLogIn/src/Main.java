import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		//Add User
		System.out.println(args[0]);
		if(args[0].equals("1")){
			System.out.println("Registration");
			List<User> users = new ArrayList<User>();
			Scanner scan = new Scanner(System.in);
			System.out.print("UserName:");
			String name = scan.nextLine();
			System.out.print("Password:");
			String password = scan.nextLine();
			try {
				users.addAll(FileSystem.LoadUsers());
				users.add(new User(name,password));
				FileSystem.SafeUsers(users);
			} catch (UserException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
		//Add User
		
		//LogIn 
		if(args[0].equals("2")){
			System.out.println("LogIn");
			Scanner scan = new Scanner(System.in);
			System.out.print("UserName:");
			String name = scan.nextLine();
			System.out.print("Password:");
			String password = scan.nextLine();
			try {
				System.out.println(FileSystem.LogIn(new User(name,password)));
			} catch (UserException e) {
				e.printStackTrace();
			}
		}
		//LogIn
		
		
	}
}
