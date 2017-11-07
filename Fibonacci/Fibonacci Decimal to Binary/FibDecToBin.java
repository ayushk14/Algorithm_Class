/*Find Fibonacci numbers and mod 100. input a 10^5 digit number stored in integer array and fibonacci mod 100 upto that number. y=x^(ni)*/

import java.util.*;
import java.lang.*;
public class FibDecToBin
{
	//matrix to calculate fibonacci number
	static int A[][] = {{1,1} , {1,0}};

	public static void main(String args[])
	{
		int X[] = new int[100];
		//code to generate ranodom number between 0-9
		  Random rnum = new Random();
		  for(int i = 0 ; i < 100 ; i++)
		  {
						X[i] = rnum.nextInt(10);

			//			System.out.print(X[i] + "\t");
		  }

		int len = (int)Math.ceil(X[0]*Math.log(X.length) / Math.log(2));

		int bin[] = new int[len];
		System.out.println("Length = " + len);
		//decToBinary(X , bin);
		//in matrix value of c is the fibonacci number for n
		int c = power(A , X);
		System.out.println("c = " + c);
	}

	public static void decToBinary(int X[] , int bin[])
	{

	//to divide whole array of integer by 2 and returning the number of 0'x in it.
			int rem = 0;
			int count  = 0;
			int index = 0;
			while(index < 100)
			{
				for(int i = 0 ; i < 100 ; i++)
				{
					if(X[i] == 0)
						index++;
				}


				for(int i = 0 ; i < 100 ; i++)
				{
					rem = rem*10 +  X[i];
					X[i] = rem/2;
					rem = rem%2;
				}
				bin[count] = rem;
				count++;
				//System.out.print(X[i]);
			}
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
		int len = 100;
		int Y[][] = {{1,0}, {0,1}};
		int index = 0;
		while(index < len)
		{
			if((X[len-1] % 2) == 1)
				mult(Y , A);

			mult(A,A);

		}
		return Y[1][0];
	}
}
