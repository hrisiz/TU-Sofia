import java.io.IOException;
import java.io.ObjectInputStream;
import java.net.Socket;

public class Student extends Thread{
	private Socket socket;
	public Student(Socket socket) {
		this.socket = socket;
	}
	//правя си отеделен метод за да го синхронизирам
	private synchronized void saveToArray(Document doc){ 
		Server.documents.addLast(doc); // добавям във списъка
	}
	
	@Override
	public void run() {
		try {
			ObjectInputStream ois = new ObjectInputStream(socket.getInputStream()); //отварям стреам за четене на обекти от клиента
			Document doc = (Document) ois.readObject(); // рета обект от тип документ от клиента
			saveToArray(doc); // записвам процхетение обект в масив.
		} catch (IOException e) {
			e.printStackTrace();
		} catch (ClassNotFoundException e) {
			e.printStackTrace();
		}
	}
}
