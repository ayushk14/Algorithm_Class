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
int main()
{
int n;
scanf("%d",&n);
int a[n],i,count,start,end;
for(i=0;i<n;i++)
{
scanf("%d",&a[i]);
}
count=(int)ceil(n/5);
printf("count %d\n",count);
i=0;
while(i<count)
{
start=i*5;
end=start+5-1;
if(end>n) end=n-1;
printf("start %d end %d\n",start,end);
insertionSort(a,start,end);
int j;
for(j=start;j<=end;j++) printf("%d\n",a[j]);
printf("\n");

i++;
}
i=0;
int t=2,g;
while(i<count)
{
g=a[i];
a[i]=a[t];
a[t]=g;
t=t+5;
if(t>n) t=n-1;
i++;
}

for (i=0;i<count;i++)
	printf("%d\n",a[i]);
i=0;
insertionSort(a,i,count-1);
printf("\n");
for(i=0;i<n;i++) printf("%d\n",a[i]);
printf("Median %d\n",a[count/2]);

return 0;
}