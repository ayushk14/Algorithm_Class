import java.util.*;
public class longestPalindromeSubsequence
{
  public static void main(String args[])
  {
    //Taking input from user
    Scanner scan=new Scanner(System.in);
    System.out.print("Enter string : ");
    String str=scan.nextLine();

    //Finding length of string
    int n=str.length();

    //Converting string to character array
    char ch[]=str.toCharArray();

    //Creating a 2-D array v[n][n]
    int v[][]=new int[n][n];

    //Block to be commented
    for (int i=0;i<n;i++)
    {
      for (int j=0;j<n;j++)
        v[i][j]=0;
    }
    //Initialization of table
    for (int i=0;i<n;i++)
    {
      v[i][i]=1;
    }
    for (int i=0;i<n-1;i++)
    {
      if (ch[i]==ch[i+1])
        v[i][i+1]=2;
      else
        v[i][i+1]=1;
    }

    //Creation of table
    for (int l=2;l<n;l++)
    {
      int j=l;
      for (int i=0;i<n-l;i++,j++)
      {

        if (ch[i]==ch[j])
        {
          v[i][j]=2+v[i+1][j-1];
        }
        else
        {
          if (v[i+1][j]>v[i][j-1])
            v[i][j]=v[i+1][j];
          else
            v[i][j]=v[i][j-1];
        }
      }
    }

    //Displaying of the table
    for (int p=0;p<n;p++)
    {
      for (int q=0;q<n;q++)
        System.out.print(v[p][q]+"\t");
      System.out.println();
    }


    //Backtrack
    char subseq[]=new char[v[0][n-1]];
    int index=v[0][n-1]-1;
    int i=0;
    int j=n-1;
    while (i!=j)
    {
      if (ch[i]==ch[j])
      {
        subseq[index]=ch[j];
        index--;
        i=i+1;
        j=j-1;
      }
      else
      {
        if (v[i+1][j]>v[i][j-1])
          i=i+1;
        else
          j=j-1;
      }
    }
    while(j>=0 && index>=0)
    {
      subseq[index]=ch[j];
      j--;
      index--;
    }

    //Creating final answer
    String final_subseq="";
    for (int q=0;q<v[0][n-1];q++)
    {
      final_subseq=final_subseq+subseq[q];
    }

    //Displaying the answers
    System.out.println("Length of longest palindrome subsequence is "+v[0][n-1]);
    System.out.println("Longest palindrom subsequence is "+final_subseq);
  }
}
