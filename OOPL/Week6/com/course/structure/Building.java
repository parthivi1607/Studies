package com.course.structure;

public class Building
{
	private int st;
	private double sqft;

	public int getStories()
	{
		return st;
	}
	public double getArea()
	{
		return sqft;
	}
	public void setBuilding(int x, double y)
	{
		st=x;
		sqft=y;
	}
}