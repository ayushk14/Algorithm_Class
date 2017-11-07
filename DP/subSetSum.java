import java.util.*;
public class subSetSum
{
  public static void main(String args[])
  {
    Scanner scan=new Scanner(System.in);

    //Taking inputs from user
    System.out.print("Enter number of elements in the set : ");
    int n=scan.nextInt();
    int elements[]=new int[n];
    System.out.println("Enter elements of set:");
    for (int i=0;i<n;i++)
      elements[i]=scan.nextInt();
    System.out.print("Enter the sum value : ");
    int sum=scan.nextInt();

    //Creating a data structure using dynamic programming approach
    //We will create a boolean 2-D array value[][] of size (n+1)x(sum+1)
    //If value[i][j] is true, it means that first i elements of set is having a
    //subset with sum j

    int p=n+1;
    int q=sum+1;
    boolean value[][]=new boolean[p][q];
    for (int i=0;i<p;i++)
      value[i][0]=true;
    for (int i=1;i<q;i++)
      value[0][i]=false;

      for (int i=1;i<=n;i++)
      {
        for (int j=1;j<=sum;j++)
        {
          value[i][j]=value[i-1][j]||(elements[i-1]<=j && value[i-1][j-elements[i-1]]);
        }
      }

      //Displaying the data structure created above
      System.out.print("\t");
      for (int i=0;i<q;i++)
        System.out.print(i+"\t");
      System.out.println();
      for (int i=0;i<p;i++)
      {
        if (i==0)
          System.out.print(i+"\t");
        else
          System.out.print(i+"("+elements[i-1]+")\t");
        for (int j=0;j<q;j++)
          System.out.print(value[i][j]+"\t");
        System.out.println();
      }

      //Displaying the final answer; true or false
      System.out.println("There is subset having sum="+sum+" : "+value[n][sum]);
  }
}
