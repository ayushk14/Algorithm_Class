import java.util.*;
public class InsertionSort{
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

		insertionSort(arr);

		System.out.println("Sorted Array list : ");
		for(int i = 0; i < n ; i++)
		{
			System.out.print(arr[i] + "\t");
		}

	}

	public static void insertionSort(int a[])
	{
		int key, j;
		for(int i = 1 ; i < a.length ; i++)
		{
			j = i-1;
			key = a[i];
				while(j >= 0 && key < a[j])
				{
					a[j+1] = a[j];
					j--;
				}
				a[j+1] = key;
		}
	}
}
