#include<stdio.h>
#include<stdlib.h>

int rPivot(int *a,int i,int j)
{
  return i+rand()%(j-i+1);
}

int partition(int *a,int i,int j,int p)
{
  int e,f,m,t;
  e=i;
  f=j;
  //m=rPivot(a,i,j);
  m=i;
  while(1)
  {
    //e=i;
    while(e<j && a[e]<a[m])
      e++;
    //f=j;
    while(f>i && a[f]>=a[m])
      f--;
    if(e<f)
    {
      t=a[e];
      a[e]=a[f];
      a[f]=t;
      e++;
      f--;
    }
    else
    {
      t=a[f];
      a[f]=a[m];
      a[m]=t;
      break;
    }
  }
  return f;
}

int findElement(int *a,int i,int j,int r)
{
  if(j<i)
    return -1;
  int k=partition(a,i,j,i);
  if(r==j-k+1)
    return k;
  else if(r<j-k+1)
    findElement(a,k+1,j,r);
  else
    findElement(a,i,k-1,r-(j-k+1));
}


int main()
{
  int a[10],i;
  for(i=0;i<10;i++)
  {
    scanf("%d",&a[i]);
  }
  int r;
  printf("Enter the rank :");
  scanf("%d",&r);
  //printf("partition %d\n",partition(a,0,4,0));
  printf("element %d\n",a[findElement(a,0,9,r)]);
  return 0;
}
