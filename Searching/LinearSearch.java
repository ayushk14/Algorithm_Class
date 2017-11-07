import java.util.*;
public class LinearSearch{
	public static void main(String args[])
	{
		Scanner s = new Scanner(System.in);
		
		System.out.println("Enter the number of elements : ");
		int n = s.nextInt();
		
		System.out.println("Enter the elements : ");
		int arr[] = new int[n];
		
		for(int i = 0 ; i < n ; i++)
		{
			arr[i] = s.nextInt();
		}
		
		
		System.out.println("Enter the element you want to search : ");
		int key = s.nextInt();
		
		System.out.println(linearSearch(arr, key));
		
		
	}
	
	public static int linearSearch(int a[] , int ele)
	{
	
		for(int i = 0 ; i < a.length ; i++)
		{
			if(a[i] == ele)
				return i;
		}
		return -1;
	}
}