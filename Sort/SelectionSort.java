import java.util.*;
public class SelectionSort{
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

		selectionSort(arr);

		System.out.println("Sorted Array list : ");
		for(int i = 0; i < n ; i++)
		{
			System.out.print(arr[i] + "\t");
		}

	}

	public static void selectionSort(int a[])
	{
		int temp;
		int min,p;
		for(int i = 0 ; i < a.length ; i++)
		{
			p = i;
			min = a[i];
			for(int j = i+1 ; j < a.length; j++)
			{
				if(min > a[j])
				{
					min  = a[j];
					p = j;
				}
			}

			temp = a[i];
			a[i] = a[p];
			a[p] = temp;
		}
	}
}
