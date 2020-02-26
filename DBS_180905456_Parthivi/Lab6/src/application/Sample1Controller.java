package application;

import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.TextField;
import java.sql.*;

public class Sample1Controller {

    @FXML
    private Button add;

    @FXML
    private Button modify;

    @FXML
    private Button exit;

    @FXML
    private TextField bldng;

    @FXML
    private Button prev;

    @FXML
    private Button clr;

    @FXML
    private Button del;

    @FXML
    private Button main;

    @FXML
    private Button nxt;

    @FXML
    private TextField deptname;

    @FXML
    private TextField budget;

    @FXML
    void insertrec() {
    	try {
    		Connection conn = dbconnect();
    		String s1 = deptname.getText().toString();
    		String s2 = bldng.getText().toString();
    		int s3 = Integer.parseInt(budget.getText());
    		PreparedStatement ps = conn.prepareStatement("insert into department values ('"+s1+"', '"+s2+"', "+s3+")");
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
    		String s1 = deptname.getText().toString();
    		String s2 = bldng.getText().toString();
    		int s3 = Integer.parseInt(budget.getText());
    		PreparedStatement ps = conn.prepareStatement("update department set building = '"+s2+"', budget = "+s3+" where dept_name = '"+s1+"'");
    		ps.execute();
    		System.out.println("Updated");
    		conn.close();
    	}catch(Exception e)
    	{
    		System.out.println(e);
    	}
    }

    @FXML
    void deleterec() {
    	try {
    		Connection conn = dbconnect();
    		String s1 = deptname.getText().toString();
    		//String s2 = bldng.getText().toString();
    		//int s3 = Integer.parseInt(budget.getText());
    		PreparedStatement ps = conn.prepareStatement("delete from department where dept_name = '"+s1+"'");
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
    	bldng.setText("");
    	deptname.setText("");
    	budget.setText("");
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
