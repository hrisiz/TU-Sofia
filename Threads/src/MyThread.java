import java.io.BufferedReader;
import java.io.EOFException;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintStream;
import java.net.Socket;
import java.util.Scanner;

public class MyThread extends Thread{
	Socket socket;
	
	public MyThread(Socket socket) {
		this.socket = socket;
	}
	
	@Override
	public void run() {
		BufferedReader bf = null;
		try {
			Scanner sc = new Scanner(socket.getInputStream());
			String[] line = sc.nextLine().split(",");
			String username = line[0];
			String password = line[1];
			File fp = new File("users");
			FileReader in = new FileReader(fp);
			bf = new BufferedReader(in);
			while(true){
				try{
					String user = bf.readLine();
					String[] userfields = user.split(",");
					if(userfields[0].equals(username) && userfields[1].equals(password)){
						if(userfields[2].equals("Admin")){
							new Admin(socket).start();
						}
						if(userfields[2].equals("User")){
							new User(socket).start();
						}
						break;
					}
				}catch(EOFException e){
					PrintStream printout = new PrintStream(socket.getOutputStream());
					printout.println("Wring username or password!");
					break;
				}
			}
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}finally{
			try {
				bf.close();
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
	}
}
