#include<stdio.h>
//#include<time.h>
int main()
{
    printf("Hello");
    int i,j,k,s=2,n=1000;
    //clock_t start,end;
    //start=clock();
    for (i=0;i<n;i++)
    {
        for (j=0;j<n;j++)
        {
            for (k=0;k<n;k++)
            {
                //printf("%d\n",s);
                s=2*s+1;
            }
        }
    }
    //end=clock();
    printf("s=%d\n",s);
    //printf("time=%f\n",(double)(end-start));
    return 0;
}
