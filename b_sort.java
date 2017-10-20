import java.util.*;
public class b_sort
{
	public static void sort(int a[],int n)
	{
		for (int i=0;i<n;i++)
		{
			for (int j=0;j<n-1-i;j++)
			{
				if (a[j]>a[j+1])
				{
					int temp=a[j];
					a[j]=a[j+1];
					a[j+1]=temp;
				}
			}
		}
	}
	public static void main(String args[])
	{
		Scanner scan=new Scanner(System.in);
		int n=scan.nextInt();
		int a[]=new int[n];
		for (int i=0;i<n;i++)
			a[i]=scan.nextInt();
		sort(a,n);
		for (int i=0;i<n;i++)
			System.out.print(a[i]+" ");
	}
}