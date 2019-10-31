import javafx.event.*;
import javafx.geometry.*;
import javafx.application.*;
import javafx.scene.*;
import javafx.stage.*;
import javafx.scene.layout.*;
import javafx.scene.Scene;
import javafx.scene.text.*;
import javafx.scene.control.*;
import javafx.scene.canvas.*;
import javafx.scene.paint.*;
import javafx.util.*;

public class Lab12Q3 extends Application implements Runnable
{
	String msg;
	Thread t1;
	GraphicsContext gc;
	Label l1 = new Label("Enter text to scroll: ");
	TextField tf;
	Canvas canvas;
	RadioButton ch1;
	RadioButton ch2;
	ToggleGroup tg = new ToggleGroup();

	public static void main(String[] args)
	{
		launch(args);
	}
	public void start(Stage mystage)
	{
		ch1 = new RadioButton("Right to left");
		ch2 = new RadioButton("Left to right");
		ch1.setToggleGroup(tg);
		ch2.setToggleGroup(tg);
		mystage.setTitle("Scroller");
		canvas = new Canvas(300, 250);
		gc = canvas.getGraphicsContext2D();
		tf = new TextField();
		FlowPane rootnode = new FlowPane(10, 10);
		Scene myscene = new Scene(rootnode);
		mystage.setScene(myscene);
		tf.setOnAction
		(
			new EventHandler<ActionEvent>()
			{
				public void handle(ActionEvent ae)
				{
					starttask();
				}
			}
		);
		rootnode.getChildren().addAll(l1,tf, ch1, ch2, canvas);
		mystage.show();
	}
	public void starttask()
	{
		t1 = new Thread(this);
		t1.setDaemon(true);
		t1.start();
	}
	public void run()
	{
		msg = tf.getText();
		char ch;
		while(true)
		{
			try
			{
				if(ch1.isSelected())
				{
					Platform.runLater(new Runnable(){
							public void run()
							{
								gc.setFill(Color.WHITE);
								gc.fillRect(25, 25, 200, 600);
								gc.setFont(new Font("Arial", 20));
								gc.strokeText(msg, 50, 80);
							}
						
					});
					Thread.sleep(1000);
					ch = msg.charAt(0);
					msg = msg.substring(1, msg.length());
					msg += ch;
				}
				else if(ch2.isSelected())
				{
					Platform.runLater(new Runnable(){
							public void run()
							{
								gc.setFill(Color.WHITE);
								gc.fillRect(25, 25, 200, 600);
								gc.setFont(new Font("Arial", 20));
								gc.strokeText(msg, 50, 80);
							}
						
					});
					Thread.sleep(1000);
					ch = msg.charAt(msg.length()-1);
					msg = ch+msg.substring(0, msg.length()-1);
				}
			}
			catch(InterruptedException e)
			{
				System.out.println(e);
			}
		}
	}
}
