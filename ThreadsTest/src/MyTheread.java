
public class MyTheread extends Thread{
	private void add(){
		for(int i=0;i<10;i++){
			//synchronized(Test.lock){
				Test.array.add((int) (Math.random()*100));
				System.out.println("Creating:"+Test.array.get(Test.array.size()-1));
			//}
		}
	}
	@Override
	public void run(){
		this.add();
	}
}
