import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;
import javafx.application.Application;
import javafx.geometry.Rectangle2D;
import javafx.scene.Scene;
import javafx.scene.control.Alert;
import javafx.scene.control.Button;
import javafx.scene.control.TextArea;
import javafx.scene.control.TextField;
import javafx.scene.image.Image;
import javafx.scene.control.Alert.AlertType;
import javafx.scene.layout.Background;
import javafx.scene.layout.BackgroundImage;
import javafx.scene.layout.BackgroundPosition;
import javafx.scene.layout.BackgroundRepeat;
import javafx.scene.layout.BackgroundSize;
import javafx.scene.layout.VBox;
import javafx.scene.paint.Color;
import javafx.scene.text.Font;
import javafx.scene.text.FontWeight;
import javafx.scene.text.Text;
import javafx.stage.Screen;
import javafx.stage.Stage;
/*TEST DATA:	
samuel pilusa
alan turing
lesli lamport
steve wozniak
kurt godel
margareth humilton
anatoly karpov
victor kochnoi
mikail tal
bobby fischer
Magnus Carlsen
Hikaru Nakamura
 */
/* FUNCTIONS IN THE PUBLIC CLASS MAIN(listed sequencially)
 * 
 * 1.void main(String[] args)
 * 2.void start(Stage stage)
 * 3.void out(int i)
 * 4.void out(String s)
 * 5.void out(char c)
 * 6.void addName(TextField tf,TextArea ta )
 * 7.void removeLast(TextArea ta)
 * 8.void writeToNamesTXT(String s)
 * 9.String readFromNamesTXT()
 * 10.String excludeName(String name)
 * 11.String getLast()
 * 12.boolean isLast()
 * 13.boolean isEqual(String s1,String s2)
 * 14.void removeByName(TextField tf2,TextArea ta1 )
 */
//objective : find a given name and output the the line number of that name on ta1
public class Main extends Application
{

	//void main(String[] args)
	public static void main(String[] args) 
	{
		// TODO Auto-generated method stub
		
		launch(args);

	}
	
	//void start(Stage stage)
	@Override
	public void start(Stage stage) 
	{
		//Texts and their format
		//Text t1 and its formating
		Text t1 =new Text("Add name : ");
		t1.setFont(Font.font(null, FontWeight.BOLD, 100));
		t1.setFont(Font.font("Verdana", 15));
		t1.setFill(Color.WHITE);
		
		//Text t2 and its formating
		Text t2 =new Text("Names are as follows : ");
		t2.setFont(Font.font(null, FontWeight.BOLD, 100));//setting weight and size of the text
		t2.setFont(Font.font("Verdana", 15));//setting the style of the text
		t2.setFill(Color.WHITE); //setting the color of the text
		
		//Text t2 and its formating
		Text t3 =new Text("Enter the name to be removed below : ");
		t3.setFont(Font.font(null, FontWeight.BOLD, 100));//setting weight and size of the text
		t3.setFont(Font.font("Verdana", 15));//setting the style of the text
		t3.setFill(Color.WHITE); //setting the color of the text
		
		//Text used as space
		Text space1=new Text("\n");
		Text space2=new Text("\n");
		Text space3=new Text("\n");
		
		//TextFields
		TextField tf1=new TextField();
		TextField tf2=new TextField();
		
		//Buttons
		Button bt1=new Button("Add Name");
		Button bt2=new Button("Remove last line");
		Button bt3=new Button("Remove the name above");
		Button bt4=new Button("Exit");
		
		//TextAreas
		TextArea ta1 =new TextArea();
		ta1.setText(readFromNamesTXT());  //reading from names.txt and write into TextField ta
		
		//root node
		VBox root =new VBox();
		
		root.getChildren().addAll(t1,tf1,bt1,space1,t2,ta1,bt2,space2,t3,tf2,bt3,space3,bt4);//place in the components needed to the root node
		//creating the scene
		Scene scene=new Scene(root,750,450);
		//make the window to not be resizable
		stage.setResizable(false);

		//setting-up the background************************************
		Screen screen = Screen.getPrimary();
		Rectangle2D bounds = screen.getVisualBounds();
		double width = bounds.getWidth();
		double height = bounds.getHeight();
		
		//make sure to name the filename as file:filename instead of just filename
		//e.g.  file:greatwhiteshark.jpg instead of just greatwhiteshark.jpg
		BackgroundImage bimage= new BackgroundImage(new Image("file:782966.jpg",width,height,false,true),
				BackgroundRepeat.NO_REPEAT, BackgroundRepeat.NO_REPEAT, BackgroundPosition.CENTER,
				BackgroundSize.DEFAULT);
		root.setBackground(new Background(bimage));
		
		//setting the scene to the stage
		stage.setScene(scene);
		
		//creating the title
		stage.setTitle("People Names");
		
		//make the window appear
		stage.show();
		
		//**************** HANDLING EVENTS ************************ 
		bt1.setOnAction(e->
		{
			addName(tf1,ta1);
		
		});
			
		bt2.setOnAction(e->
		{
			removeLast(ta1);
		});
		bt3.setOnAction(e->
		{
			removeByName(tf2,ta1 );
		});
	
		bt4.setOnAction(e->
		{
			Alert alert = new Alert(AlertType.INFORMATION);
			alert.setTitle("Message");
			alert.setHeaderText(null);
			alert.setContentText("Good-Bey! :-)");
			alert.showAndWait();
			stage.close(); //
		});
	}
    //******************************** output functions ***************************************
	
	//void out(int i)
	public static void out(int i)
	{
		System.out.println(i);
	}
	//void out(String s)
	public static void out(String s)
	{
		System.out.println(s);
	}
	//void out(char c)
	public static void out(char c)
	{
		System.out.println(c);
	}
	//***************************************************************************************
	
	//void addName(TextField tf,TextArea ta )
	void addName(TextField tf,TextArea ta)
	{
		String name="";
		name=tf.getText();
		
		String str=readFromNamesTXT();
		
		str+=name+"\n";
		ta.setText(str);
		tf.setText("");
		writeToNamesTXT(str);
	}
	
	//void removeLast(TextArea ta)
	void removeLast(TextArea ta)
	{
			String name=getLast();//getting the last line
			if(isLast())
			{
				Alert alert = new Alert(AlertType.WARNING);
				alert.setTitle("ALERT");
				alert.setHeaderText(null);
				alert.setContentText("This is the last name and surname! , so it can't be removed");
				alert.showAndWait();
			}else
			{
				String str=excludeName(name);//get the string am going write into the external text file
				writeToNamesTXT(str);    //writing into the external text file names.txt
				ta.setText(str);   //writing into the TextArea
			}
			
			
	}
	
	//void writeToNamesTXT(String s)
	void writeToNamesTXT(String s)
	{
		File file=new File("names.txt");
		try
		{
			FileWriter fw=new FileWriter(file);
			fw.write(s);
			fw.flush();
			fw.close();
		}catch(IOException e)
		{
			e.printStackTrace();
		}
	}
	
	//String readFromNamesTXT()
	String readFromNamesTXT()
	{
		File file=new File("names.txt");
		String str="";
		try
		{
			Scanner sc=new Scanner(file);
			while(sc.hasNext())
			{
				str=str+sc.nextLine()+"\n";
			}
			sc.close();
		}catch(IOException e)
		{
			e.printStackTrace();
		}
		return str;
	}
	
	//String excludeName(String name)
	String excludeName(String name)
	{
		File file=new File("names.txt");
		String str="";
		try
		{
			Scanner sc=new Scanner(file);
			String line="";
			int counter=0;
			boolean isEqual=false;
			while(sc.hasNext())
			{
				counter=0;
				isEqual=false;
				line=sc.nextLine();
				if(line.length()!=name.length())
				{
					isEqual=false;
				}else
				{
					for(int i=0;i<name.length();++i)
					{
						if(name.charAt(i)==line.charAt(i))
						{
							++counter;
						}
					}
					if(counter==name.length())
					{
						isEqual=true;
					}
				}
				if(!isEqual)
				{
					str=str+line+"\n";
				}
			}
			sc.close();
		}catch(IOException e)
		{
			e.printStackTrace();
			
		}
		return str;
	}
	
	//String getLast()
	String getLast()
	{
		File file=new File("names.txt");
		String name="";
		try 
		{
			Scanner sc=new Scanner(file);
			while(sc.hasNext())
			{
				name=sc.nextLine();
			}
			sc.close();
		}catch(IOException e)
		{
			e.printStackTrace();
		}
		return name;
	}
	//boolean isLast()
	boolean isLast()
	{
		
		int numOfLines=0;
		
		File file=new File("names.txt");
		
		try
		{
			Scanner sc=new Scanner(file);
			String str="";
			while(sc.hasNext())
			{
				str=sc.nextLine();
				++numOfLines;
			}
			System.out.println(str);
			sc.close();
		}catch(IOException e)
		{
			e.printStackTrace();
		}
		if(numOfLines>1)
		{
			return false;
		}else
		{
			return true;
		}
	}
	//boolean isEqual(String s1,String s2)
	boolean isEqual(String s1,String s2)
	{
		if(s1.length()!=s2.length())
		{
			return false;
		}else
		{
			for(int i=0;i<s1.length();++i)
			{
				if(s1.charAt(i)!=s2.charAt(i))
				{
					return false;
				}
			}
		}
		
		return true;
	}
	//void removeByName(TextField tf2,TextArea ta1 )
	void removeByName(TextField tf2,TextArea ta1 )
	{
		String name =tf2.getText();
		if(isLast())
		{
			Alert alert = new Alert(AlertType.WARNING);
			alert.setTitle("ALERT");
			alert.setHeaderText(null);
			alert.setContentText("This is the last name and surname! , so it can't be removed");
			alert.showAndWait();
		}else
		{
			File file=new File("names.txt");
			try
			{
				Scanner sc=new Scanner(file);
				String line="";
				String nname="";
				String strline="";
				while(sc.hasNext())
				{
					line=sc.nextLine();
					nname="";
					for(int i=0;line.charAt(i)!=' ';++i)
					{
						nname+=line.charAt(i);
					}
					if(!isEqual(nname,name))
					{
						strline+=line+"\n";
					}
					
				}
				sc.close();
				writeToNamesTXT(strline);
				ta1.setText(strline);
				
			}catch(IOException c)
			{
				c.printStackTrace();
			}
		}
		
	}
}

