import javafx.application.*;
import javafx.scene.*;
import javafx.scene.layout.*;
import javafx.scene.control.*;
import javafx.scene.image.*;
import javafx.stage.*;
import javafx.scene.canvas.*;
import javafx.scene.text.Font;
import javafx.geometry.*;
import javafx.event.*;
import javafx.scene.input.MouseEvent;
import javafx.scene.paint.Color;

public class Scroll extends Application implements Runnable{
	String msg;
	Thread t1=null;
	GraphicsContext gc;
	Label l1=new Label("Enter text to scroll");
	TextField tf;
	Canvas canvas;
	public static void main(String args[]){
		launch(args);
	}
	public void start(Stage stage){
		canvas=new Canvas(300,250);
		gc=canvas.getGraphicsContext2D();
		tf=new TextField();
		FlowPane root=new FlowPane(10,10);
		root.getChildren().addAll(l1,tf,canvas);
		Scene scene=new Scene(root);
		stage.setScene(scene);
		stage.setTitle("UI");
		stage.show();
		tf.setOnAction(new EventHandler<ActionEvent>(){
			public void handle(ActionEvent ae){
				startTask();
			}
		});
	}
	public void startTask(){
		t1=new Thread(this);
		t1.setDaemon(true);
		t1.start();
	}
	public void run(){
		msg=tf.getText();
		char ch;
		for(;;){
			try{
				Platform.runLater(new Runnable(){
					public void run(){
						gc.setFill(Color.WHITE);
						gc.fillRect(25,25,200,200);
						gc.setFont(new Font("Arial",20));
						gc.strokeText(msg,50,80);}});
				Thread.sleep(500);
				ch=msg.charAt(0);
				msg=msg.substring(1,msg.length());
				msg+=ch;
					}
			catch(InterruptedException e){
				e.printStackTrace();
				}
			}
			}

		}
