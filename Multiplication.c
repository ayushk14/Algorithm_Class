#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    int test_case;
    scanf("%d",&test_case);
    int x;
    for (x=0;x<test_case;x++)
    {
      char * s = (char *)malloc(sizeof(char)*1000);
      char * t = (char *)malloc(sizeof(char)*1000);
      scanf("%s",s);
      scanf("%s",t);
      int signs=0;
      int signt=0;
      if(s[0]=='-')
      {
        signs=1;
      }
      if(t[0]=='-')
      {
        signt=1;
      }
      char *ans = (char *)malloc(sizeof(char)*2001);
      int temp=2000;
      int m=0;
      int c=0;
      int i=strlen(s)-1;
      int j=strlen(t)-1;
      int k=0;
      while(j>=0)
      {
        temp=2000-k;
        i=strlen(s)-1;
        c=0;
        while(i>=0)
        {
          m=(s[i]-48)*(t[j]-48);
          int num=(ans[temp])+m+c;
          //printf("m %d c %d num %d ans[temp] %d\n",m,c,num,ans[temp] );
          ans[temp]=(char)((num%10));
          //printf("After ans[temp] %d at temp %d\n",ans[temp],temp );
          temp--;
          c=num/10;
          if(signs==1)
          {
            if(i==1 && c!=0)
            {
              ans[temp]=(char)c;
              //printf("After ans[temp]%d at temp %d\n",ans[temp],temp );
              temp--;
            }
          }
          if (i==0 && c!=0)
          {
            ans[temp]=(char)(c);
            //printf("After ans[temp] %d at temp %d\n",ans[temp],temp );
            temp--;
          }
          i--;
          if(i==0 && signs==1) break;
        }
        j--;
        if(j==0 && signt==1) break;
        k++;
      }
      i=0;
      j=0;
      char *ans_str=(char *)malloc(sizeof(char)*(2001-temp+1));
      int q;
      if((signt==1 && signs==0) || (signt==0 && signs==1))
      {
        ans_str[0]='-';
        j++;
      }
      q=temp+1;
      while(q<2001)
      {
        if (ans[q] == 0)
        {
          i++;
        }
        ans_str[j]=ans[q]+48;
        j++;
        q++;
      }
      ans_str[j]='\0';
      if(i==(2000-temp))
      {
        printf("0\n");
      }
      else
      {
        printf("%s\n",ans_str);
      }
    }
    return 0;
}
