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

public class Q4 extends Application
{
	public void start(Stage mainStage)
	{
		mainStage.setTitle("GCD of 2 nos.");
		GridPane grid = new GridPane();
		Label l1 = new Label("Enter a no.:");
		Label l2 = new Label("Enter a no.:");
		Text t1 = new Text();
		l1.setFont(new Font(15));
		l2.setFont(new Font(15));
		t1.setFont(new Font(15));
		TextField tf1 = new TextField();
		tf1.setText("");
		TextField tf2 = new TextField();
		tf2.setText("");
		Button b1 = new Button("Calc");
		Button b2 = new Button("Reset");
		grid.addRow(0,l1,tf1);
		grid.addRow(1,l2,tf2);
		grid.add(b1,3,3);
		grid.add(b2,3,4);
		grid.add(t1,1,3);
		grid.setVgap(5);
		grid.setHgap(5);
		b1.setOnAction(new EventHandler <ActionEvent>()
		{
			public void handle(ActionEvent ae)
			{
				int x = Integer.parseInt(tf1.getText());
				int y = Integer.parseInt(tf2.getText());
				int gcd = gcd(Math.max(x,y),Math.min(x,y));
				t1.setText("GCD = "+gcd);
			}
		});
		b2.setOnAction(new EventHandler <ActionEvent>(){
			public void handle(ActionEvent ae)
			{
				tf1.setText("0");
				tf2.setText("0");
				t1.setText("");
			}
		});
		Scene s = new Scene(grid, 500, 150);
		mainStage.setScene(s);
		mainStage.show();
	}
	public static void main(String[] args) {
		launch(args);
	}

	public int gcd(int max,int min)
	{
		if(max<=0 || min<=0) return 0;

		if(max%min==0) return min;
		return gcd(min,max%min);
	}
}