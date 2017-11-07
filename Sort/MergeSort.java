import java.util.*;
public class MergeSort{
	public static void main(String args[])
	{
		Scanner s = new Scanner(System.in);
		
		System.out.println("Enter the number of elements you want to sort : ");
		int n = s.nextInt();
		
		System.out.println("Enter the elements : ");
		int arr[] = new int[n];
		for(int i = 0; i < n ; i++)
		{
			arr[i] = s.nextInt();
		}
		
		mergeSort(arr , 0 , n-1);
		
		System.out.println("Sorted Array list : ");
		for(int i = 0; i < n ; i++)
		{
			System.out.print(arr[i] + "\t");
		}
		
	}
	
	public static void mergeSort(int a[] , int l , int r)
	{
		
		if(l<r)
		{
			int m = l+(r-l)/2;
			
			mergeSort(a , l , m);
			mergeSort(a , m+1 , r);
			
			merge(a , l , r , m);
		}
		
	}
	
	public static void merge(int a[] , int l , int r , int m)
	{
		    int i, j, k;
			int n1 = m - l + 1;
			int n2 =  r - m;
		
		int left[] = new int[n1];
		int right[] = new int[n2];
		
		for(i = 0; i < n1 ; i++)
			left[i] = a[l+i];
		for(j = 0 ; j < n2 ; j++)
			right[j] = a[m+1+j];
		
		/* Merge the temp arrays back into arr[l..r]*/
		i = 0; // Initial index of first subarray
		j = 0; // Initial index of second subarray
		k = l; // Initial index of merged subarray
		
		while(i<n1 && j<n2)
		{
			if(left[i] < right[j])
			{
				a[k] = left[i];
				i++;
				k++;
			}
			else
			{
				a[k] = right[j];
				j++;
				k++;
			}
		}
		while(i<n1)
		{			
			a[k] = left[i];
			i++;
			k++;
		}
		
		while(j<n2)
		{
			a[k] = right[j];
			j++;
			k++;
		}
	}
}