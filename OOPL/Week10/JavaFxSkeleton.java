import javafx.application.*;
import javafx.scene.*;
import javafx.stage.*;
import javafx.scene.layout.*;
import javafx.scene.control.*;
import javafx.event.*;
import javafx.geometry.*;
import javafx.scene.paint.Color;

public class Q1 extends Application
{
	Label response;

	public static void main(String args[])
	{
		launch(args);
	}

	public void start(Stage myStage)
	{
		myStage.setTitle("This is the 1st JavaFX Application");
		FlowPane rootNode = new FlowPane(10,10);
		rootNode.setAlignment(Pos.CENTER);
		Scene myScene = new Scene(rootNode,500,200);

		myStage.setScene(myScene);
		response=new Label("Welcome to JavaFX programming");
		response.setTextFill(Color.MAGENTA);
		rootNode.getChildren().add(response);
		myStage.show();
	}
}