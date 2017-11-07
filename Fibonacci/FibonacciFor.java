/*Fibonacci series of given number. F(n) = (F(n-1) + F(n-2)) mod 100. Using For loop. Linear Time and Linear Space*/


import java.util.*;
public class FibonacciFor{
	public static void main(String args[])
	{
		Scanner s = new Scanner(System.in);
		
		System.out.println("Enter the number till you want the series");

		int n = s.nextInt();
		int arr[] = new int[n];
		
		arr[0] = 0;
		arr[1] = 1;
		for(int i = 2 ; i < n ; i++)
		{
			arr[i] = (arr[i-1] + arr[i-2]) % 100;
			System.out.println(arr[i]);
		}
	}
}