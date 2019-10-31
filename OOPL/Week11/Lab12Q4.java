import javafx.application.*;
import javafx.scene.*;
import javafx.scene.layout.*;
import javafx.scene.control.*;
import javafx.event.*;
import javafx.geometry.*;
import javafx.stage.*;
import javafx.scene.paint.Color;
import javafx.scene.image.*;
import javafx.scene.canvas.*;

public class Lab12Q4 extends Application
{
	GraphicsContext gc;
	CheckBox area;
	CheckBox radius;
	CheckBox circumference;
	Label l1;
	Label l2;
	Label l3;
	public static void main(String args[])
	{
		launch(args);
	}
	public void start(Stage myStage)
	{
		GridPane rootNode = new GridPane();
		Scene myScene = new Scene(rootNode,500,400);
		myStage.setScene(myScene);
		
		Canvas myCanvas = new Canvas(300,300);
		radius = new CheckBox("Radius");
		area = new CheckBox("Area");
		circumference = new CheckBox("Circumferece");
		l1 = new Label();
		l2 = new Label();
		l3 = new Label();
		gc = myCanvas.getGraphicsContext2D();
		gc.strokeOval(100,100,100,100);

		rootNode.add(myCanvas,0,0);
		rootNode.addRow(1,radius,l1);
		rootNode.addRow(2,circumference,l2);
		rootNode.addRow(3,area,l3);

		area.setOnAction(new EventHandler<ActionEvent>()
		{
			public void handle(ActionEvent ae)
			{
				if(area.isSelected())
				{
					l3.setText("Area is "+(3.14*100*100));
				}
				else
				{
					l3.setText("");
				}
			}
		});
		circumference.setOnAction(new EventHandler<ActionEvent>()
		{
			public void handle(ActionEvent ae)
			{
				if(circumference.isSelected())
				{
					l2.setText("Circumference is "+(2*3.14*100));
				}
				else
				{
					l2.setText("");
				}
			}
		});
		radius.setOnAction(new EventHandler<ActionEvent>()
		{
			public void handle(ActionEvent ae)
			{
				if(radius.isSelected())
				{
					l1.setText("Radius is "+(100));
				}
				else
				{
					l1.setText("");
				}
			}
		});
		myStage.show();
	}
}
