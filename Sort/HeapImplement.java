import java.util.Scanner;


public class HeapImplement {

	public static int Heap[];
	public static void main(String args[])
	{
		Scanner s = new Scanner(System.in);
		int option = 0 ; 
		int count = 0;

		do{
			System.out.println("Press 1 to insert !");
			System.out.println("Press 2 to Delete !");
			System.out.println("Press 3 to Sort the data !");
			System.out.println("Press 4 to print Heap !");
			System.out.println("Press 0 to Exit !");
		
			option = s.nextInt();
			
			switch(option)
				{
					case 1 : System.out.println("Enter the key to insert in heap : ");
							 count++;		 
							 insert(s.nextInt() , count , Heap);
							 break;
							 
					case 2 : int min = deleteMinKey(Heap);
							 System.out.println("After min deletion the Heap become : ");
							 showHeap(Heap);
							 count--;
							 break;
							 
					case 3 : System.out.println("The Sorted Order after insertion is : ");
							 while(Heap.length > 0)
							 {
								 int key = deleteMinKey(Heap);
								 System.out.print(key + " ");
							 }
							 break;
							 
					case 4 : System.out.println("The Heap entries are : ");
							 showHeap(Heap);
							 break;
							 
					case 0 : break;
				}
		}while(option != 0);
	}
	
	private static void insert(int key, int count, int[] tempheap) {
		// TODO Auto-generated method stub
		
		Heap = new int[count];
		for(int i = 0; i < count-1 ; i++ )
		{
			Heap[i] = tempheap[i];
		}
		Heap[count-1] = key;
		
		buildHeap(Heap);
	}
	
	public static void buildHeap(int[] build_heap)
	{
		
		int child = build_heap.length - 1;
		int parent = (child - 1)/2;
		int temp = 0;
		
		while(parent >= 0)
		{
			if(build_heap[parent] > build_heap[child])
			{
				temp = build_heap[parent];
				build_heap[parent] = build_heap[child];
				build_heap[child] = temp;
			}
			
			if(parent != 0)
			{
				child = parent;
				parent = (child - 1)/2;
			}
			else {
				parent = -1;
			}
			temp = 0;
		}
	}
	
	public static int deleteMinKey(int[] heap) 
	{
		int min = heap[0];
		
		int temp = heap[0];
		heap[0] = heap[heap.length - 1];
		heap[heap.length - 1] = temp;
		
		Heap = new int[heap.length - 1];
		
		for(int i = 0; i < Heap.length ; i++)
		{
			Heap[i] = heap[i];
		}
		
		heapify(Heap);
		
		return min;
	}
	
	public static void heapify(int[] heap)
	{
		int parent = 0;
		int lchild = (2*parent) + 1;
		int rchild = (2*parent) + 2;
		int len = heap.length - 1;
		
		while((parent <= len) || (parent <= len-1))
		{
			if(lchild >= len)
				break;
			else {
				int small_child = (heap[lchild] > heap[rchild]) ? rchild : lchild; 
				
				if(heap[small_child] < heap[parent])
				{
					int temp = heap[small_child];
					heap[small_child] = heap[parent];
					heap[parent] = temp;
					
					parent = small_child;
					lchild = (2*parent) + 1;
					rchild = (2*parent) + 2; 
					
				}
				else
					break;
			}

		}
	}
	
	public static void showHeap(int[] heap) {
		
		for(int i = 0; i < heap.length ; i++)
		{
			System.out.println(heap[i]);
		}
	}

}
