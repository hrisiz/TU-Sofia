import java.io.IOException;
import java.io.PrintStream;
import java.net.Socket;
import java.util.Scanner;

public class Admin extends Thread{
	Socket socket;
	public Admin(Socket socket) {
		this.socket = socket;
	}
	
	private void readAndAnswer(){
		try {
			//Scanner sc = new Scanner(socket.getInputStream());
			//String number = sc.nextLine();
			PrintStream printout = new PrintStream(socket.getOutputStream());
			printout.println("You are Admin");
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
	}
	
	@Override
	public void run() {
		this.readAndAnswer();
	}
}
