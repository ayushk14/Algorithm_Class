import java.util.*;
public class kmp
{
	public static String matchPattern(String t,String p,int a[])
	{
		int len_t=t.length();
		int len_p=p.length();
		int i,j,f,x=0;
		i=0;
		j=0;
		f=0;
		int flag=0;
		while (i<len_t)
		{
			f=0;
			if (t.charAt(i)!=p.charAt(j))
			{
				if (j!=0)
				{
					x=i-a[j-1];
					j=a[j-1];
					f=1;
				}
			}
			else
			{
				j++;
				if (j==len_p)
				{
					flag=1;
					break;
				}
			}
			if (f==0)
				i++;
		}
		if (flag==1)
			return "Pattern matched from index "+(x+1);
		else
			return "Pattern do not match";
	}
	
	
	
	public static void main(String args[])
	{
		Scanner scan=new Scanner(System.in);
		System.out.print("Enter Text : ");
		String t=scan.nextLine();
		System.out.print("Enter Pattern : ");
		String p=scan.nextLine();
		
		int len_p=p.length();
		int a[]=new int[len_p];
		for (int i=0;i<len_p;i++)
			a[i]=0;
		int i,j,f;
		f=0;
		j=0;
		i=1;
		while(i<len_p)
		{
			f=0;
			if (p.charAt(j)!=p.charAt(i))
			{
				if (j!=0)
				{
					j=a[j-1];
					f=1;
				}
			}
			else
			{
				a[i]=j+1;
				j++;
			}
			if (f==0)
				i++;
		}
		String ans=matchPattern(t,p,a);
		System.out.println(ans);
		/*for (i=0;i<len_p;i++)
			System.out.print(p.charAt(i)+" ");
		System.out.println();
		for (i=0;i<len_p;i++)
			System.out.print(a[i]+" ");
		System.out.println();*/
	}
}