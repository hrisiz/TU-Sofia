

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

public class ReadFromFile {
private static BufferedReader buffReader = null;
public void readFromFile(){
	try {
		buffReader = new BufferedReader(new FileReader("Students.txt"));
		String currLine;
		while((currLine=buffReader.readLine()) != null){
			System.out.println(currLine);
		}
	}catch(IOException e){
		e.printStackTrace();
	}finally{
		try{
			if(buffReader != null)
				buffReader.close();
			}catch (IOException e){
				e.printStackTrace();
			}
		}

}
}
