import java.io.IOException;
import java.io.ObjectOutputStream;
import java.net.Socket;
import java.util.LinkedList;
import java.util.Scanner;

public class Secretary extends Thread{
	private Socket socket;
	public Secretary(Socket socket) {
		this.socket = socket;
	}
	//правя си отеделен метод за да го синхронизирам
	public synchronized Document getDocument(){
		return Server.documents.removeFirst(); // взимам и изтривам първия елемент от листа
	}
	//правя си отеделен метод за да го синхронизирам
	public synchronized void addDocument(Document doc,LinkedList<Document> list){
		list.add(doc); // добавям документа в приетите
	}
	@Override
	public void run() {
		Document doc = this.getDocument(); // взимам първия елемент и го записвам в doc

		if((doc.getType() == DocumentType.Normal &&  // проверявам дали е нормална стипендия
			 doc.getProgress() >= 5.50 && //дали е над 5.50 успех
			 doc.getIncome() >= 500)  // и дали има доходи над 500 всичките са заедно с и
				|| // или 
			(doc.getType() == DocumentType.Special && // дали е специална стипендия
			 doc.getProgress() >= 5.30 && //дали е над 5.30 успех
			 doc.getIncome() >= 300) // дали има над 300 доход
		  ){
			addDocument(doc,Server.acceptedDocuments); //  ако е true то тогава е удобрен
		}else{
			addDocument(doc,Server.deniedDocuments); //  ако е false то тогава е отхвърлен
		}
	}

}
