package application;

import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.TextField;
import java.sql.*;

public class Sample2Controller {

    @FXML
    private Button exit;

    @FXML
    private TextField insid;

    @FXML
    private Button prev;

    @FXML
    private TextField name;

    @FXML
    private Button clr;

    @FXML
    private Button insert;

    @FXML
    private Button update;

    @FXML
    private Button main;

    @FXML
    private TextField dept;

    @FXML
    private Button nxt;

    @FXML
    private Button delete;

    @FXML
    private TextField sal;

    @FXML
    void insertrec() {
    	try {
    		Connection conn = dbconnect();
    		int id = Integer.parseInt(insid.getText());
    		String s1 = name.getText().toString();
    		String s2 = dept.getText().toString();
    		int s3 = Integer.parseInt(sal.getText());
    		PreparedStatement ps = conn.prepareStatement("insert into instructor values ("+id+", '"+s1+"', '"+s2+"', "+s3+")");
    		ps.execute();
    		System.out.println("Inserted");
    		conn.close();
    	}catch(Exception e)
    	{
    		System.out.println(e);
    	}
    }

    @FXML
    void updaterec() {
    	try {
    		Connection conn = dbconnect();
    		int id = Integer.parseInt(insid.getText());
    		String s1 = name.getText().toString();
    		String s2 = dept.getText().toString();
    		int s3 = Integer.parseInt(sal.getText());
    		PreparedStatement ps = conn.prepareStatement("update instructor set dept_name = '"+s2+"', name = '"+s1+"', salary = "+s3+" where id = "+id);
    		ps.execute();
    		System.out.println("Updated");
    		conn.close();
    	}catch(Exception e)
    	{
    		System.out.println(e);
    	}
    }

    @FXML
    void delrec() {
    	try {
    		Connection conn = dbconnect();
    		String s1 = insid.getText().toString();
    		//String s2 = bldng.getText().toString();
    		//int s3 = Integer.parseInt(budget.getText());
    		PreparedStatement ps = conn.prepareStatement("delete from instructor where id = '"+s1+"'");
    		ps.execute();
    		System.out.println("Deleted");
    		conn.close();
    	}catch(Exception e)
    	{
    		System.out.println(e);
    	}
    }

    @FXML
    void clrtxt() {
    	insid.setText("");
    	dept.setText("");
    	sal.setText("");
    	name.setText("");
    }
    
    static Connection dbconnect()
    {
    	Connection con = null;
    	try {
    		Class.forName("oracle.jdbc.driver.OracleDriver");
    		con = DriverManager.getConnection("jdbc:oracle:thin:@172.16.57.4:1521:orcl2","b2dbsl28","b2dbsl28");
    	}catch(Exception e)
    	{
    		System.out.println(e);
    	}
    	return con;
    }

}
