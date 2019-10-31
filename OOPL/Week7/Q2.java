import java.util.*;
import java.lang.*;

class InvalidDay extends Exception{
	InvalidDay(){
		System.out.println("Date wrong");
	}
}
class InvalidMonth extends Exception{
	InvalidMonth(){
		System.out.println("Month wrong");
	}
}
class CurrentDate{
	int date, month, year;
	CurrentDate(){}
	public void createDate(int d, int m, int y) throws InvalidMonth, InvalidDay{
		if((m==1||m==3||m==5||m==7||m==8||m==10||m==12)&&(d>31)){
			throw new InvalidDay();
		}
		else if((m==4||m==6||m==9||m==11)&&(d>30)){
			throw new InvalidMonth();
		}
		else if((m==2)&&(y%400==0 || y%4==0)&&(d>29)){
			throw new InvalidDay();
		}
		else if((m==2)&&(y%400!=0)&&(d>28)){
			throw new InvalidDay();
		}
		else if(m>12){
			throw new InvalidMonth();
		}
		else{
			year = y;
			month = m;
			date = d;
		}
	}
	public void Display(){
		System.out.println("The current date is: "+this.date+"/"+this.month+"/"+this.year);
	}
}
public class ExcepTest{
	public static void main(String[] args) {
		int y, m, d;
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter the date month and year: ");
		d = sc.nextInt();
		m = sc.nextInt();
		y = sc.nextInt();
		try{
			CurrentDate dmy = new CurrentDate();
			dmy.createDate(d,m,y);
			dmy.Display();
		}
		catch(InvalidDay ex){
			System.out.println("Exception(day) caught");
		}
		catch(InvalidMonth ex){
			System.out.println("Exception(month) caught");
		}
	}
}
