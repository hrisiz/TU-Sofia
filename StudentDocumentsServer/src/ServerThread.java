import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.net.Socket;
import java.util.Scanner;
// това е нишката която ще обработва абсолютно всеки свързал се клиент.
// Тук ще се разбира какъв е този клиент, който се е свързал.
// За целта ще се използва потребителско име и парола, които ще са записани във файл.
public class ServerThread extends Thread{ // създаваме класа и наследяваме Thread за да стане нишка
	private Socket socket; 
	private static final File usersFile = new File("users"); // създавам константа на файлът, който съдържа потребителите
	
	public ServerThread(Socket socket) { //Конструктора приема сокета(порта) за да може да знае класа как ще комуникира със клиента
		this.socket = socket;
	}
	
	private UserType checkUser(String username,String password){ // създавам метод, който ще идентифицира клиента като потребител и ще върне какъв тип е потребителя
		BufferedReader br = null;
		try {
			br = new BufferedReader(new FileReader(usersFile));// отварям файлът с потребителите
		} catch (FileNotFoundException e1) {
			// TODO Auto-generated catch block
			e1.printStackTrace();
		} 
		String row = null;
		try {
			while((row = br.readLine()) != null){ // взимам потребител от файлът
				String[] user = row.split(","); // разделям полетата за да имам име и парола
				if(user[0].equals(username) && user[1].equals(password)){ // проверявам дали потребителя от файлът е еднакъв с подадения
					if(user[2].equals("Student")){ // проверявам дали потребителя е студент 
						return UserType.Student; // връщам че потребителя е студент
					}
					if(user[2].equals("Secretary")){ // проверявам дали потребитя е секретарка
						return UserType.Secretary; // връщам че потребителя е секретарка
					}
					return UserType.Error;
				}
			}
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		return UserType.Error;
	}
	
	@Override
	public void run() {
		try {
			Scanner sc = new Scanner(socket.getInputStream()); // отварям scanner за четене от клиента
			String[] userFields = sc.nextLine().split("/"); // прочитам от клиента един ред
			UserType ut = checkUser(userFields[0],userFields[1]); // провеявам за такъв потребител и връщам типа на потребителя
			if(ut == UserType.Student){ // проверявам дали потребителя е студент 
				new Student(socket).start(); //стартирам нишка за студент 
			}
			if(ut == UserType.Secretary){ // проверявам дали потребитя е секретарка
				new Secretary(socket).start(); //стартирам нишка на секретарка
			}
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
	}
}
