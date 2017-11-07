//3 44 38 5 47 15 36 26 27 2 46 4 19 50 48
#include<stdio.h>
#include<math.h>

void insertionSort(int *a,int start,int end)
{
	int i,j,t;
	for(i=start+1;i<=end;i++)
	{
		t=a[i];
		j=i-1;
		while(j>=start && a[j]>t)
		{
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=t;
	}
}


int dPivot(int *a,int n)
{
	int count=(int)ceil(n/5);
	printf("count %d\n",count);
	int i=0,start,end;
	while(i<count)
	{
		start=i*5;
		end=start+5-1;
		if(end>n)
			end=n-1;
		printf("start %d end %d\n",start,end);
		insertionSort(a,start,end);
		int j;
		for(j=start;j<=end;j++)
			printf("%d\n",a[j]);
		printf("\n");

		i++;
	}
	i=0;
	int t=n/10,g;
	while(i<count)
	{
		g=a[i];
		a[i]=a[t];
		a[t]=g;
		t=t+5;
		if(t>n)
			t=n-1;
		i++;
	}

	for (i=0;i<count;i++)
		printf("%d\n",a[i]);

	i=0;

	insertionSort(a,i,count-1);

	printf("\n");

	for(i=0;i<n;i++)
		printf("%d\n",a[i]);
	printf("Median %d\n",a[count/2]);

	return count/2;
}


void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}


int partition (int a[], int low, int high, int p)
{
    swap(&a[p],&a[high]);
    int pivot = a[high];    // pivot
    int i = (low - 1);  // Index of smaller element
    int j;
    for (j = low; j <= high- 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (a[j] <= pivot)
        {
            i++;    // increment index of smaller element
            swap(&a[i], &a[j]);
        }
    }
    swap(&a[i + 1], &a[high]);
    return (i + 1);
}

int findRank(int a[], int i, int j, int r){

  int p, k;
  if(j<i)
	{
    printf("\nCould not find!!\n");
		return 0;
  }
  else
	{
    p = dPivot(int *a,int n);
    k = partition(a,i,j,p);
  }
  if(r==(j-k+1))
    return k;
  else if(r<(j-k+1))
    findRank(a,k+1,j,r);
  else
    findRank(a,i,k-1,r-(j-k+1));
}

int main(){
  int k,m;
  int a[] = {2,3,8,7,10,23,4,6,4,5};
  /*
  k = rPivot(0,9);
  m = partition(a,0,9,k);
  cout<<endl<<k<<" "<<m<<endl;


  for(int i=0;i<10;i++){
    cout<<a[i]<<" ";
  }
  cout<<endl;
  */
  k = findRank(a,0,9,3);
  printf("%d\n",a[k]);
  return 0;
}
