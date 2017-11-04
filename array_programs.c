#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void sumEqualToX(int a[],int n,int x)
{
  //a[i]+a[j]=x
  //Method 1: Brute force --> O(n^2)
  //Method 2: Sort the array. Now take a element, subtract it from x and apply binary search for 'x-a[i]' --> O(nlogn)
  //Method 3: Below method --> O(n) if array given is sorted otherwise O(nlogn)


  //Sort array
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

  //Method continues
  int l=0;
  int r=n-1;
  int f=0;
  while(l<=r)
  {
    if (a[l]+a[r]==x)
    {
      f=1;
      break;
    }
    else if (a[l]+a[r]<x)
      l++;
    else
      r--;
  }
  if (f==1)
  {
    printf("Match found at l=%d, r=%d\n",l,r);
  }
  else
    printf("Match not found\n");
}


void sumEqualToElementOfArray(int a[],int n)
{
  //a[i]+a[j]=a[k]
  //Method 1: Brute force --> O(n^3)
  //Method 2: Below Method --> O(n^2)


  //First step is to sort the array
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

  //Second step
  int k,l,r;
  int g=0;
  for (k=0;k<n;k++)
  {
    int x=a[k];
    l=0;
    r=n-1;
    int f=0;
    while (l<=r)
    {
      if (a[l]+a[r]==x)
      {
        f=1;
        break;
      }
      else if (a[l]+a[r]<x)
        l++;
      else
        r--;
    }
    if (f==1)
    {
      g=1;
      break;
    }
  }
  if (g==1)
  {
    printf("Match found with index values as i=%d, j=%d, k=%d\n",l,r,k);
  }
  else
  {
    printf("Match not found\n");
  }
}


int modMinDiff(int a[],int n)
{
  //Method 1: Brute force --> O(n^2)
  //Method 2: Sort the array and take difference of consecutive numbers --> O(nlogn)

  //Sort array
  for (int i=0;i<n;i++)
  {
    for (int j=0;j<n-1-i;j++)
    {
      if(a[j]>a[j+1])
      {
        int temp=a[j];
        a[j]=a[j+1];
        a[j+1]=temp;
      }
    }
  }

  //Taking difference of consecutive elements
  int min=abs(a[0]-a[1]);
  for (int i=1;i<n-1;i++)
  {
    int temp=abs(a[i]-a[i+1]);
    if (temp<min)
      min=temp;
  }

  return min;
}


int modMaxDiff(int a[],int n)
{
  int max=0;
  int min=10000;
  for (int i=0;i<n;i++)
  {
    if (a[i]>max)
      max=a[i];
    if (a[i]<min)
      min=a[i];
  }
  return abs(max-min);
}


int maxDiffWithGreaterJ(int a[],int n)
{
  //Method 1: Brute force --> O(n^2)
  /*
    for i=0 to n
        for j=i+1 to n
            if (a[j]-a[i]>m)
              m=a[j]-a[i];
  */
  //Method 2: Below method --> O(n)

  int i=0;
  int j=1;
  int max=a[j]-a[i];
  j++;
  while (j<n)
  {
    if (a[i]>a[j-1])
      i=j-1;
    if (a[j]-a[i]>max)
      max=a[j]-a[i];
    j++;
  }
  return max;
}


int maxDiffWithWindowL(int a[],int n,int l)
{
  int i=0;
  int j=l;
  int max=a[j]-a[i];
  j++;
  while (j<n)
  {
    if (a[i]>a[j-1])
      i=j-l;
    if (a[j]-a[i]>max)
      max=a[j]-a[i];
    j++;
  }
  return max;
}



int main()
{
  printf("Ente size of array : ");
  int n;
  scanf("%d",&n);
  int a[n];
  printf("Enter elements of array\n");
  for (int i=0;i<n;i++)
  {
    scanf("%d",&a[i]);
  }
  while (1)
  {
    printf("\n\nFollowing choices are as follows:\n");
    printf("1. a[i]+a[j]=x\n");
    printf("2. a[i]+a[j]=a[k]\n");
    printf("3. min(|a[i]-a[j]|)\n");
    printf("4. max(|a[i]-a[j]|)\n");
    printf("5. max(a[i]-a[j]) where j>i\n");
    printf("6. max(a[i]-a[j]) where j>=i+l\n");
    printf("10. Exit\n");
    printf("Enter your choice : ");
    int choice;
    scanf("%d",&choice);
    if (choice==1)
    {
      int x;
      printf("Enter x : ");
      scanf("%d",&x);
      sumEqualToX(a,n,x);
    }
    else if (choice==2)
    {
      sumEqualToElementOfArray(a,n);
    }
    else if (choice==3)
    {
      printf("Answer is %d\n",modMinDiff(a,n));
    }
    else if (choice==4)
    {
      printf("Answer is %d",modMaxDiff(a,n));
    }
    else if (choice==5)
    {
      printf("Answer is %d\n",maxDiffWithGreaterJ(a,n));
    }
    else if (choice==6)
    {
      printf("Enter window size : \n");
      int l;
      scanf("%d",&l);
      printf("Answer is %d\n",maxDiffWithWindowL(a,n,l));
    }
    else
    {
      break;
    }
  }
  return 0;
}
