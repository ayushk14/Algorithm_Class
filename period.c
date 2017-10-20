#include <stdio.h>
#include <malloc.h>
int countDigit(int num)
{
    int count=0;
    while(num!=0)
    {
        num/=10;
        count++;
    }
    return count;
}
int main()
{
    int i,sum,a,b,p,n,m,c;
    a=0;
    b=1;
    i=2;
    sum=0;
    m=4;
    p=0; 
    while(1)
    {
        sum=(a+b)%m;
        a=b;
        b=sum;
        if(sum==0)
        {
            if((a+b)%m == 1)
            {
                p=i;
                break;
            }
        }
        i++;
    }    
    char *arr = (char*)malloc(sizeof(char) * 100000);
    printf("Enter a number :");
    scanf("%s",arr);
    sum=0;
    i=0;
    c=0;
    while(arr[i]!='\0')
    {
        c=0;
        while(c<9)
        {
            sum = sum*10 + (int)(arr[i]);
            i++;
            c=countDigit(sum);
            if(arr[i]=='\0') break;
        }
        if(c == 9) { sum = sum/10; i--;}
        sum = sum%p;
    }
    a=0;
    b=1;
    c=0;
    for(i=2;i<=sum;i++)
    {
        c=(a+b)%m;
        a=b;
        b=c;
    }
    printf("%d\n",c);
    return 0;
}
