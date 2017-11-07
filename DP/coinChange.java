import java.util.*;
public class coinChange
{
  public static void main(String args[])
  {
    Scanner scan=new Scanner(System.in);

    //Taking input
    System.out.print("Enter the amount for which change is needed : ");
    int amt=scan.nextInt();
    System.out.print("Enter number of denominatios : ");
    int d_n=scan.nextInt();
    int denominations[]=new int[d_n];
    System.out.println("Enter the available denominations");
    for (int i=0;i<d_n;i++)
      denominations[i]=scan.nextInt();

    //Sort the given denominations in ascending order
    Arrays.sort(denominations);

    //Creating table using dynamic approach
    //v[i][j] will minimum number of coins required for amount i using first j coins
    //Our answer will be v[amt][d_n]
    int v[][]=new int[amt+1][d_n+1];
    for (int i=0;i<d_n;i++)
      v[0][i]=0;
    for (int i=0;i<amt;i++)
      v[i][0]=0;
    int x,y;

    for (int j=1;j<=d_n;j++)
  	{
  		for (int i=1;i<=amt;i++)
  		{
    		if (i<denominations[j-1])
  				v[i][j]=v[i][j-1];
  			else
  			{
    			x=v[i-denominations[j-1]][j]+1;
    			y=v[i][j-1];
    			if (y==0)
    				v[i][j]=x;
  				else
  				{
    				if (x>y)
    					v[i][j]=y;
    				else
    					v[i][j]=x;
    			}
  			}
    	}
    }

    //Displaying of table
    System.out.print("\t");
    for (int i=0;i<d_n;i++)
      System.out.print(denominations[i]+"\t");
    System.out.println();
    System.out.print("\t");
    for (int i=1;i<=d_n;i++)
      System.out.print("("+i+")\t");
    System.out.println();
    for (int i=1;i<amt+1;i++)
    {
      System.out.print(i+"|\t");
      for (int j=1;j<d_n+1;j++)
        System.out.print(v[i][j]+"\t");
      System.out.println();
    }



    //Backtrack to find which denominations are used
    int chk[]=new int[d_n];
    for (int i=0;i<d_n;i++)
      chk[i]=0;
    int i=amt;
    int j=d_n;
    while (i!=0 && j!=0)
    {
      System.out.println(i+"\t"+j);
      if (v[i][j]==v[i][j-1])
      {
        System.out.println("Inside equal if\n");
        j=j-1;
      }
      else
      {
        System.out.println("inside else");
        System.out.println(denominations[j-1]+"\n");
        i=i-denominations[j-1];
        chk[j-1]+=1;
      }
    }

    for (i=0;i<d_n;i++)
    {
      System.out.println("Number of denomination - "+denominations[i]+" required : "+chk[i]);
    }
  }
}
