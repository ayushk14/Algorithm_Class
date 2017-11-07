import java.util.*;
public class q_sort
{
	public static void sort(int a[],int p,int r)
	{
		if (p<r)
		{
			int q=partition(a,p,r);
			sort(a,p,q-1);
			sort(a,q+1,r);
		}
	}
	public static int partition(int a[],int p,int r)
	{
		int x=a[r];
		int i=p-1;
		for (int j=p;j<=r-1;j++)
		{
			if (a[j]<=x)
			{
				i=i+1;
				int temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
		int temp=a[i+1];
		a[i+1]=a[r];
		a[r]=temp;
		return (i+1);
	}
	public static void main(String args[])
	{
		Scanner scan=new Scanner(System.in);
		int n=scan.nextInt();
		int a[]=new int[n];
		for (int i=0;i<n;i++)
			a[i]=scan.nextInt();
		
		sort(a,0,n-1);
		
		for (int i=0;i<n;i++)
			System.out.print(a[i]+" ");
	}
}