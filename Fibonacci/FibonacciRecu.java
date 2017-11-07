/* Program to find fibnacci number and then mod 100. F(n) = (F(n-1) + F(n-2)) % 100. Exponential time and Linear space.*/

import java.util.*;
public class FibonacciRecu
{
	public static void main(String args[])
	{
		Scanner s = new Scanner(System.in);
		
		System.out.println("Enter the number to get Fibonacci Series");
		int n = s.nextInt();
		
		int x = fibrec(n);
		System.out.println(x);
		
	}
	
	public static int fibrec(int a)
	{
		
		if(a == 0)
			return 0;
		else if(a ==  1)
			return 1;
		else 
		return (fibrec(a-1) + fibrec(a-2))%100;
	}
}
