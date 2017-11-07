/*Find Fibonacci numbers and mod 100. input a 10^5 digit number stored in integer array having binary values only and fibonacci mod 100 upto that number. y=x^(ni)*/

import java.util.*;
import java.lang.*;
public class FibBinary
{
	//matrix to calculate fibonacci number
	static int A[][] = {{1,1} , {1,0}};
	
	public static void main(String args[])
	{
		int X[] = new int[100000];
		//code to generate ranodom number between 0-1
		  Random rnum = new Random();
		  for(int i = 0 ; i < 100000 ; i++)
		  {
						X[i] = rnum.nextInt(2);
						
						//System.out.print(X[i] + "\t");
		  }
		  
		//in matrix value of c is the fibonacci number for n
		int c = power(A , X);
		System.out.println("c = " + c);
	}
	
	public static void mult(int s[][] , int b[][])
	{
	//code to multiply 2 matrix and store them in first matrix
		int temp [][] = new int[2][2];
		for(int i =0; i< 2; i++)
		{
			for(int j=0; j < 2; j++)
			{
				int sum =0;
				for(int k=0; k < 2; k++)
				{
					sum = sum + (s[i][k] * b[k][j]);
				}
				temp[i][j] = sum%100;
			}
		}
		
		
		for(int i =0; i< 2; i++)
		{
			for(int j=0; j < 2; j++)
			{
				s[i][j] = temp[i][j];
			}
		}
	}
	
	public static int power(int A[][] ,int X[])
	{
	//code to find the fibonacci number using matrix method and x^n[i]
		int len = 100000;
		int Y[][] = {{1,0}, {0,1}};
		int index = len-1;
		while(index >= 0)
		{
			if(X[index] == 1)
				mult(Y , A);
			
			mult(A,A);
			
			index--;
		}
		return Y[1][0];
	}
}