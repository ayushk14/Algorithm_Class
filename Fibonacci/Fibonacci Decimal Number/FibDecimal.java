/*Find Fibonacci numbers and mod 100. input a 10^5 digit number stored in integer array and fibonacci mod 100 upto that number. y=x^(ni)*/

import java.util.*;
import java.lang.*;
public class FibDecimal
{
	//matrix to calculate fibonacci number
	static int A[][] = {{1,1} , {1,0}};

	public static void main(String args[])
	{
		int X[] = new int[100000];
		//code to generate ranodom number between 0-9
		  Random rnum = new Random();
		  for(int i = 0 ; i < 100000 ; i++)
		  {
						X[i] = rnum.nextInt(10);

						System.out.print(X[i] + "\t");
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


	public static int divideBy2(int X[])
	{
	//to divide whole array of integer by 2 and returning the number of 0'x in it.
		int rem = 0;
		for(int i = 0 ; i < 100000 ;i++)
		{
			rem = rem*10 +  X[i];
			X[i] = rem/2;
			rem = rem%2;
			//System.out.print(X[i]);
		}	
		int index = 0;
		for(int i = 0 ; i < 100000 ; i++)
		{
			if(X[i] == 0)
				index++;
		}
		return index;
	}

	public static int power(int A[][] ,int X[])
	{

	//code to find the fibonacci number using matrix method and x^n[i]
		int len = 100000;
		int Y[][] = {{1,0}, {0,1}};
		int index = 0;
		while(index < len)
		{
			if((X[len-1] % 2) == 1)
				mult(Y , A);

			mult(A,A);

			index = divideBy2(X);
		}
		return Y[1][0];
	}
}
