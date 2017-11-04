#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	char *s=(char *)malloc(sizeof(char)*100000);
	printf("Enter string:");
	scanf("%s",s);
	int len=strlen(s);
	int dpTable[len][len];
	memset(dpTable,0,sizeof(dpTable[0][0])*len*len);
	for(int i=0;i<len;i++)
	{
		dpTable[i][i]=1;
	}
	for(int i=0;i<len-1;i++)
	{
		if(s[i]==s[i+1])
		{
			dpTable[i][i+1]=2;
		}
		else
		{
			dpTable[i][i+1]=1;
		}
	}
/*	for(int i=0;i<len;i++)
	{
		printf("%d\n",dpTable[i][i]);
	}
	printf("---------------------------------\n");
	for(int i=0;i<len-1;i++)
	{
		printf("%d\n",dpTable[i][i+1]);
	}
	*/
	int l=2;
	int i,j;
	while(l<len)
	{
		i=0;
		j=l;
		while(i<=len-1-l)
		{
			if(s[i]==s[j])
			{
				dpTable[i][j]=2+dpTable[i+1][j-1];
			}
			else
			{
				if(dpTable[i+1][j]>dpTable[i][j-1])
				{
					dpTable[i][j]=dpTable[i+1][j];
				}
				else
				{
					dpTable[i][j]=dpTable[i][j-1];
				}
			}
			j++;
			i++;
		}
		l++;
	}
	i=0;
	while(i<len)
	{
		l=0;
		while(l<len)
		{
			printf("%d ",dpTable[i][l]);
			l++;
		}
		printf("\n");
		i++;
	}
	printf("Length of longest common palindrome subsequence :%d\n",dpTable[0][len-1]);
	int temp=dpTable[0][len-1];
	char * subsequence=(char *)malloc(sizeof(char)*temp+1);
	subsequence[temp]='\0';
	temp--;
	j=len-1;
	i=0;
	while(i!=j)
	{
		if(s[i]==s[j])
		{
			subsequence[temp]=s[j];
			temp--;
			i++;
			j--;
		}
		else
		{
			if (dpTable[i+1][j]>dpTable[i][j-1])
				i=i+1;
			else
				j=j-1;
		}
	}
	while(j>=0 && temp>=0)
	{
		subsequence[temp]=s[j];
		j--;
		temp--;
	}
	printf("%s\n",subsequence);
	return 0;
}
