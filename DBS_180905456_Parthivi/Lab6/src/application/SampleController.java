package application;

import javafx.application.Platform;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.layout.AnchorPane;
import javafx.stage.Stage;

public class SampleController {

    @FXML
    private Button exitbtn;

    @FXML
    private Button instbtn;

    @FXML
    private Button deptbtn;

    @FXML
    void showins() {
    	try {
			AnchorPane root = (AnchorPane)FXMLLoader.load(getClass().getResource("Sample2.fxml"));
			Stage stg = new Stage();
			Scene scene = new Scene(root,400,400);
			scene.getStylesheets().add(getClass().getResource("application.css").toExternalForm());
			stg.setScene(scene);
			stg.show();
		} catch(Exception e) {
			e.printStackTrace();
		}
    }

    @FXML
    void showdept() {
    	try {
			AnchorPane root = (AnchorPane)FXMLLoader.load(getClass().getResource("Sample1.fxml"));
			Stage stg = new Stage();
			Scene scene = new Scene(root,400,400);
			scene.getStylesheets().add(getClass().getResource("application.css").toExternalForm());
			stg.setScene(scene);
			stg.show();
		} catch(Exception e) {
			e.printStackTrace();
		}
    }

    @FXML
    void exitfn() {
    	Platform.exit();
    	System.exit(0);
    }

}
