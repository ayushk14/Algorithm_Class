import java.util.*;
public class multiply
{
  public static void main(String args[])
  {
    Scanner scan=new Scanner(System.in);
    int test_case=scan.nextInt();
    for (int x=0;x<test_case;x++)
    {
      String str1=scan.next();
      String str2=scan.next();

      char s[]=str1.toCharArray();
      char t[]=str2.toCharArray();

      char ans[]=new char[2000];
      for (int i=0;i<2000;i++)
        ans[i]='0';
      int temp=1999;
      int m=0;
      int c=0;
      int i=s.length-1;
      int j=t.length-1;
      int k=0;
      while(j>=0)
      {
        temp=ans.length-1-k;
        i=s.length-1;
        c=0;
        while(i>=0)
        {
          m=(s[i]-48)*(t[j]-48);
          int num=(ans[temp]-48)+m+c;
          ans[temp]=(char)(num%10+48);
          temp--;
          c=num/10;
          if (i==0 && c!=0)
          {
            ans[temp]=(char)(c+48);
            temp--;
          }
          i--;
        }
        j--;
        k++;
      }
      i=0;
      String ans_str="";
      for (int q=temp+1;q<2000;q++)
      {
        if (ans[q]-48 == 0)
        {
          i++;
        }
        ans_str=ans_str+ans[q];
      }
      if(i==(1999-temp))
      {
        System.out.println("0");
      }
      else
      {
        System.out.println(ans_str);
      }
    }
  }
}
