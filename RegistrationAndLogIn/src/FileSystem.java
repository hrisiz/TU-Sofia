import java.io.EOFException;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Date;
import java.util.List;

public class FileSystem {

	private static final File usersFile = new File("DB/users.bin");
	private static final File usersLogFile = new File("Log/users.log");
	public static List<User> LoadUsers(){
		if(!usersFile.exists()){
			return new ArrayList<User>();
		}
		List<User> users = new ArrayList<User>();
		try {
			FileInputStream fin = new FileInputStream(usersFile);
			ObjectInputStream ois = new ObjectInputStream(fin);
			User readUser;
			while(true){
				try {
					readUser = (User)ois.readObject();
					users.add(readUser);
				} catch (EOFException e) {
					break;
				} catch (ClassNotFoundException e) {
					e.printStackTrace();
				}
			}
			ois.close();
		} catch (EOFException e) {
			
		} catch (IOException e) {
			e.printStackTrace();
		}
		return users;
	}
	
	public static void SafeUsers(List<User> users){
		try {
			FileOutputStream fout = new FileOutputStream(usersFile);
			ObjectOutputStream oos = new ObjectOutputStream(fout);
			for (User user : users) {
				oos.writeObject(user);
			}
			oos.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
	
	public static boolean LogIn(User user){
		try {
			FileInputStream fin = new FileInputStream(usersFile);
			ObjectInputStream ois = new ObjectInputStream(fin);
			User readUser;
			while(true){
				try {
					readUser = (User)ois.readObject();
					if(readUser.equals(user)){
						Date date = new Date();
						PrintWriter dateFin = new PrintWriter(usersLogFile);
						dateFin.println(user+"\t"+date);
						dateFin.close();
						return true;
					}
				} catch (EOFException e) {
					break;
				} catch (ClassNotFoundException e) {
					e.printStackTrace();
				}
			}
			ois.close();
		} catch (EOFException e) {
			
		} catch (IOException e) {
			e.printStackTrace();
		}
		return false;
	}
}
