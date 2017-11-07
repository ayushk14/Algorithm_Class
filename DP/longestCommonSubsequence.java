import java.util.*;
public class longestCommonSubsequence
{
  public static void main(String args[])
  {
    //Taking input from users
    Scanner scan=new Scanner(System.in);
    System.out.print("Enter first string : ");
    String str1=scan.nextLine();
    System.out.print("Enter second string : ");
    String str2=scan.nextLine();

    //Finding length of string
    int n=str1.length();
    int m=str2.length();

    char ch1[]=str1.toCharArray();
    char ch2[]=str2.toCharArray();
    //We will use dynamic approach
    //Create a 2-D array v[n][m]

    int v[][]=new int[m+1][n+1];
    //Table initialization
    for (int i=0;i<n+1;i++)
    {
      v[0][i]=0;
    }
    for (int i=0;i<m+1;i++)
    {
      v[i][0]=0;
    }


    //Creation of whole Table
    for (int i=1;i<=m;i++)
    {
      for (int j=1;j<=n;j++)
      {
        if (ch1[j-1]==ch2[i-1])
        {
          v[i][j]=1+v[i-1][j-1];
        }
        else
        {
          if (v[i-1][j]>v[i][j-1])
            v[i][j]=v[i-1][j];
          else
            v[i][j]=v[i][j-1];
        }
      }
    }

    /*//Displaying Table
    for (int i=0;i<=n;i++)
    {
      for (int j=0;j<=m;j++)
      {
        System.out.print(v[i][j]+"\t");
      }
      System.out.println();
    }*/

    //Backtrack
    char subseq[]=new char[v[m][n]];
    int index=v[m][n]-1;
    int i=m;
    int j=n;
    while (i!=0 && j!=0)
    {
      if (ch2[i-1]==ch1[j-1])
      {
        subseq[index]=ch2[i-1];
        index--;
        i=i-1;
        j=j-1;
      }
      else
      {
        if (v[i-1][j]>v[i][j-1])
        {
          i=i-1;
        }
        else
        {
          j=j-1;
        }
      }
    }

    String final_subseq="";
    for (int q=0;q<v[m][n];q++)
      final_subseq=final_subseq+subseq[q];


    //Displaying answer
    System.out.println("Length of longest common subsequence is "+v[m][n]);
    System.out.println("Longest common subsequence is '"+final_subseq+"'");
  }
}
