import com.course.structure.*;
import java.util.*;

public class Q4
{
	public static void main(String args[])
	{
		House h = new House();
		School s = new School();
		h.setHouse(3,2);
		h.setBuilding(7,99.99);
		s.setSchool(40,10);
		s.setBuilding(7,99.99);
		System.out.println(h.getStories());
		System.out.println(h.getArea());
		System.out.println(h.getBedrooms());
		System.out.println(h.getBaths());
		System.out.println();
		System.out.println(s.getStories());
		System.out.println(s.getArea());
		System.out.println(s.getClasses());
		System.out.println(s.getGrades());
	}
}