package com.course.structure;

public class House extends Building
{
	private int bed,bath;
	public int getBedrooms()
	{
		return bed;
	}
	public int getBaths()
	{
		return bath;
	}
	public void setHouse(int x, int y)
	{
		bed=x;
		bath=y;
	}
}