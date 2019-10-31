package com.course.structure;

public class School extends Building
{
	private int c,g;
	public int getClasses()
	{
		return c;
	}
	public int getGrades()
	{
		return g;
	}
	public void setSchool(int x, int y)
	{
		c=x;
		g=y;
	}
}