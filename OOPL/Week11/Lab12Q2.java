import javafx.event.*;
import javafx.application.*;
import javafx.event.*;
import javafx.stage.*;
import javafx.scene.*;
import javafx.scene.control.*;
import javafx.scene.input.*;
import javafx.scene.layout.*;
import javafx.scene.canvas.*;
import java.util.*;
public class Lab12Q2 extends Application
{
	String st;
	public static void main(String[] args)
	{
		launch(args);
	}
	public void start(Stage mystage)
	{
		mystage.setTitle("Draw shapes");
		FlowPane rootnode = new FlowPane(10, 10);
		Scene myscene = new Scene(rootnode);
		mystage.setScene(myscene);
		Canvas canvas = new Canvas(300, 500);
		GraphicsContext gc = canvas.getGraphicsContext2D();
		RadioButton rbl = new RadioButton("Line");
		RadioButton rbr = new RadioButton("Rectangle");
		RadioButton rbc = new RadioButton("Circle");
		ToggleGroup tg = new ToggleGroup();
		rbl.setToggleGroup(tg);
		rbr.setToggleGroup(tg);
		rbc.setToggleGroup(tg);
		class MyHandler implements EventHandler<ActionEvent>
		{
			public void handle(ActionEvent ae)
			{
				st = ((RadioButton)ae.getSource()).getText();
			}
		}
		rbl.setOnAction(new MyHandler());
		rbr.setOnAction(new MyHandler());
		rbc.setOnAction(new MyHandler());
		canvas.addEventFilter(MouseEvent.ANY, new EventHandler<MouseEvent>()
			{
				double x, y, x1, y1;
				public void handle(MouseEvent ae)
				{
					if(ae.getEventType()==MouseEvent.MOUSE_PRESSED)
					{
						x = ae.getX();
						y = ae.getY();
						//gc.clearRect(0,0,300,500);
					}
					if(ae.getEventType()==MouseEvent.MOUSE_DRAGGED)
					{
						x1 = ae.getX();
						y1 = ae.getX();
						gc.clearRect(0,0,300,500);
					}
					if(st.equals("Line"))
					{
						gc.strokeLine(x, y, x1, y1);
					}
					else if(st.equals("Rectangle"))
					{
						gc.strokeRect(x, y, x1-x, y1-y);
					}
					else
					{
						gc.strokeOval(x, y, x1-x, y1-y);
					}
				}
			}
		);
		rootnode.getChildren().addAll(rbl, rbr, rbc, canvas);
		mystage.show();
	}
}