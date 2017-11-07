import java.util.*;
public class BinarySearch{
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
		
		Arrays.sort(arr);
		System.out.println("Enter the element you want to search : ");
		int key = s.nextInt();
		
		System.out.println(binarySearch(arr, key , 0 , n-1));
		
		
	}
	
	public static int binarySearch(int a[] , int ele, int l , int r)
	{
	int mid = (l + r)/2;
		if(a[mid] == ele)
			return mid;
		else if(ele < a[mid])
			return binarySearch(a , ele , l , mid-1);
		else if(ele > a[mid])
			return binarySearch(a , ele , mid+1 , r);
		else
			return -1;
	}
}