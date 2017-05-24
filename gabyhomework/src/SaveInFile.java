

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;

public class SaveInFile {
	private static FileWriter fileWriter = null;
	private static BufferedWriter buffWriter = null;
	public void saveInFile(Student[] listStudent){
		try{
			fileWriter = new FileWriter(new File("Students.txt"));
			buffWriter = new BufferedWriter(fileWriter);
			
			for(Student s: listStudent){
				String writeToFile = s.getName() + s.getAge();
				buffWriter.write(writeToFile);
				buffWriter.newLine();
			} 
		}catch (IOException e){
			e.printStackTrace();
		}
		finally{
	        try{  
	        	if(buffWriter!=null){
					buffWriter.close();
				} 
	        	
	        	if(fileWriter!=null){
					fileWriter.close();
				}
	        	} catch (IOException e) {
					e.printStackTrace();
				}
	        }
	}
}
	
	
