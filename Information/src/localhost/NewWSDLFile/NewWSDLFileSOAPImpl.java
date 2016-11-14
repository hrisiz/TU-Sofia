/**
 * NewWSDLFileSOAPImpl.java
 *
 * This file was auto-generated from WSDL
 * by the Apache Axis 1.4 Apr 22, 2006 (06:55:48 PDT) WSDL2Java emitter.
 */

package localhost.NewWSDLFile;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;



public class NewWSDLFileSOAPImpl implements localhost.NewWSDLFile.NewWSDLFile_PortType{
    public java.lang.String newOperation(java.lang.String in) throws java.rmi.RemoteException {
    	try {
    		Class.forName("com.mysql.jdbc.Driver");
			Connection conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/test","root","123456");
			String query = "Select * From Users ";
			Statement stmt  = conn.createStatement();
			ResultSet rs = stmt.executeQuery(query);
			String result = "Not Found";
			if(rs.next())
				result = rs.getString(3);
			conn.close();
			return "Име:" + result;
    	} catch (SQLException e) {
        	return e.getMessage();
		} catch (ClassNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
			return e.getMessage();
		}
        
        
    }

}
