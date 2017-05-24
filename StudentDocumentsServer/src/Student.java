import java.io.IOException;
import java.io.ObjectInputStream;
import java.net.Socket;

public class Student extends Thread{
	private Socket socket;
	public Student(Socket socket) {
		this.socket = socket;
	}
	//����� �� �������� ����� �� �� �� �������������
	private synchronized void saveToArray(Document doc){ 
		Server.documents.addLast(doc); // ������� ��� �������
	}
	
	@Override
	public void run() {
		try {
			ObjectInputStream ois = new ObjectInputStream(socket.getInputStream()); //������� ������ �� ������ �� ������ �� �������
			Document doc = (Document) ois.readObject(); // ���� ����� �� ��� �������� �� �������
			saveToArray(doc); // �������� ����������� ����� � �����.
		} catch (IOException e) {
			e.printStackTrace();
		} catch (ClassNotFoundException e) {
			e.printStackTrace();
		}
	}
}
