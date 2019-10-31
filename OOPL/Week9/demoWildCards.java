import java.util.*;
class Gen<T extends Number>
{
	T []data;
	double sum=0;

	Gen (T [] d )
	{
		data=d;
		add();
	}
	void add()
	{
		for(T x: data)
			sum+=x.doubleValue();
	}
	void compareSum(Gen<? extends Number> obj)
	{
		if(this.sum==obj.sum)
			System.out.println("Sums are equal!");
		else
			System.out.println("Sums are not equal!");
	}
}
class demoWildCards
{
	public static void main(String[] args) {
		Integer arr1[]={1,2,3};
		Float arr2[]={2f,0f,3f,0f,1f};
		Double arr3[]={2.0,1.0};
		Gen<Integer> ob1 = new Gen<Integer>(arr1);
		Gen<Float> ob2= new Gen<Float>(arr2);
		Gen<Double> ob3 = new Gen<Double>(arr3);
		ob1.compareSum(ob2);
		ob1.compareSum(ob3);
	}
}