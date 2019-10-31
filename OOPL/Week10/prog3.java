import javafx.application.Application;
import javafx.stage.Stage;
import javafx.scene.*;
import javafx.scene.layout.*;
import javafx.scene.control.*;
import javafx.scene.paint.*;
import javafx.scene.text.*;
import javafx.geometry.*;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;

public class prog3 extends Application
{
	public void start(Stage mainStage)
	{
		mainStage.setTitle("Login Page");
		GridPane grid = new GridPane();
		Label l1 = new Label("Welcome");
		Label l2 = new Label("Username");
		Label l3 = new Label("Password");
		Text t1 = new Text();
		l1.setFont(new Font(20));
		l2.setFont(new Font(15));
		l3.setFont(new Font(15));
		t1.setFont(new Font(15));
		TextField tf = new TextField();
		tf.setText("");
		PasswordField pf = new PasswordField();
		Button b1 = new Button("Submit");
		Button b2 = new Button("Reset");
		grid.addRow(0,l1);
		grid.addRow(1,l2,tf);
		grid.addRow(2,l3,pf);
		grid.add(b1,2,3);
		grid.add(b2,3,3);
		grid.add(t1,1,3);
		grid.setVgap(5);
		grid.setHgap(5);
		b1.setOnAction(new EventHandler <ActionEvent>()
		{
			public void handle(ActionEvent ae)
			{
				String s = tf.getText();
				String p = pf.getText();
				if(s.length()==0)
					t1.setText("Enter username");
				else if(p.length()==0)
					t1.setText("Enter password");
				else if(s.length()!=0 && p.length()!=0)
					t1.setText("Welcome "+s+"!");
			}
		});
		b2.setOnAction(new EventHandler <ActionEvent>()
		{
			public void handle(ActionEvent ae)
			{
				tf.setText("");
				pf.setText("");
				t1.setText("");
			}
		});

		Scene s1 = new Scene(grid, 500, 150);
		mainStage.setScene(s1);
		mainStage.show();
	}
	public static void main(String[] args) {
		launch(args);
	}
}