import java.util.*;
public class m_sort
{
	public static void sort(int a[],int i,int j)
	{
		if (i<j)
		{
			int k=(i+j)/2;
			sort(a,i,k);
			sort(a,k+1,j);
			merge(a,i,j,k);
		}
	}
	public static int merge(int a[],int i,int j,int m)
	{
		int i,j,k,k=l;
		int n1=m-i+1;
		int n2=j-m+1;
		int left[]=new int[n1];
		int right[]=new int[n2];
		for (int x=0;x<n1;x++)
			left[x]=a[k++];
		for (int y=0;y<n2;y++)
			right[y]=a[k++];
		x=0;
		y=0;
		k=i;
		
		while (x<n1 && y<n2)
		{
			if (left[x]<right[y])
				a[k++]=left[x++];
			else
				a[k++]=right[y++];
		}
		while (i<n1)
			a[k++]=left[x++];
		while (j<n2)
			a[k++]=right[y++];
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