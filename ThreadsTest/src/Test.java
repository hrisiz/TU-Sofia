import java.util.ArrayList;
import java.util.List;

public class Test {
	public static List<Integer> array = null;
	 public static Object lock = new Object();
	public static void main(String[] args){
		array = new ArrayList<Integer>();
		MyTheread add=new  MyTheread();
		MyTheread1 delete=new MyTheread1();
		add.start();
		delete.start();
		try {
			add.join();
		} catch (InterruptedException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		try {
			delete.join();
		} catch (InterruptedException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
}
