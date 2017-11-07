// Fibonacci Series with linear search

import java.util.*;

public class Fibonaccilinear{
	public static void main(String args[])
	{
		Scanner s = new Scanner(System.in);
		
		System.out.println("Enter the number to get Fibonacci Series");
		int n = s.nextInt();
		
		int a = 0;
		int b = 1;
		int temp;
		
		for(int i = a ; a < n ;i++ )
		{
		System.out.println(a);
			temp = a;
			a = temp + b;
			b = temp; 
		}
	}
}