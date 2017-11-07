// Code to find the modulus 100 of fibonacci number, using the period method.

/* ---------------------------------concept of Period ----------------------------------
	Modulus of a number(ex 100) on fibonacci series or any other series always have a period.
	Period is the sequence of repeating digits.
	for Example :  0 1 1 2 3 5  - - - - - - - - till 300 ,  after 300 this series will repeat itself
	Our aim is to find the period of that series. After that we would take %modulus of very big array of integer by its Period.
	This modulus will directly give us the desired outcome in (6*m) times where m is modulus.
	-----------------------------------------------------------------------------------------*/

import java.lang.*;
import java.util.*;
public class FibPeriod{
	public static void main(String args[])
	{
		int x[] = new int[600];
		int n[] = new int[100000];
		
		int len = 100000;
		
		
		Random rand = new Random();
		
		for(int i = 0 ; i < len ; i++)
		{
			n[i] = rand.nextInt(10);
			//System.out.print(" " + n[i]);
		}
		
		
		int m = 100;
		int p = 0;
		int rem = 0;
		findFib(x);
		
		for(int i = 2 ; i < ((6*m) - 1) ; i++)
		{
			if((x[i] == x[0]) && (x[i+1] == x[1]))
			p = i;
		}
		
		
		for(int i=0; i < len; i++)
		{
			rem = rem*10+ n[i];
			rem = rem%p;
		}
		
		System.out.println(" \t" + x[rem]);
	}
	
	public static void findFib(int n[])
	{
		n[0] = 0;
		n[1] = 1;
		
		for(int i = 2 ;i < 300 ; i++)
		{
			n[i] = (n[i-1] + n[i-2]) % 100;
		}
	}
}