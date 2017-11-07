#include<stdio.h>
int main()
{
  int x;
  int n;
  printf("Enter x : ");
  scanf("%d",&x);
  printf("Enter n : ");
  scanf("%d",&n);
  int y=1;
  int a=x;
  int b=n;


  //Iterative method
  while (n>0)
  {
    if (n%2==1)
      y=y*x;
    x=x*x;
    n=n/2;
  }

  //Recursive method
  /*
    Power(x,n)
    {
      if (n==0)
        return 1;
      else if (n<1)
        Power(1/x,-n);
      else if (n%2==0)
        Power(x^2,n/2);
      else
        x*Power(x^2,n/2);
    }
  */
  printf("%d^%d = %d\n",a,b,y);
  return 0;
}
