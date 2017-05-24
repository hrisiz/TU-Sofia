
public class MyTheread1 extends Thread {
	 void delete(){
		for(int i = 0; i < 10; i++){
			//synchronized(Test.lock){
				if((Test.array.size() - 1) >= 0){
					System.out.println("Delete ID:"+(Test.array.size() - 1));
					Test.array.remove(Test.array.size() - 1);
				}
			//}
		}
	}
	@Override
	public void run(){
		this.delete();
	}
}
