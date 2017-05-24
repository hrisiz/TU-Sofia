import java.io.IOException;
import java.io.PrintStream;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		ServerSocket ss = null;
		try {
			Socket socket = new Socket("127.0.0.1", 1211);
			Scanner scUser = new Scanner(System.in);
			PrintStream printout = new PrintStream(socket.getOutputStream());
			Scanner scServer = new Scanner(socket.getInputStream());
				String read = scUser.nextLine();
				printout.println(read);
				System.out.println(scServer.nextLine());
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
}
