import java.util.*;
public class fractKnapsack
{
  public static void main(String args[])
  {
      //Taking input from user
      Scanner scan=new Scanner(System.in);
      System.out.print("Enter number of items : ");
      int n=scan.nextInt();
      System.out.println("Enter the required details for each item:");
      int weight[]=new int[n];
      int value[]=new int[n];
      for (int i=0;i<n;i++)
      {
        System.out.print("Enter the weight of item "+(i+1)+" : ");
        weight[i]=scan.nextInt();
        System.out.print("Enter the value of item "+(i+1)+" : ");
        value[i]=scan.nextInt();
      }
      System.out.print("Enter the weight of Knapsack : ");
      int wgt_knapsack=scan.nextInt();


      //Solving using greedy approach
      //Create an array fraction[n] which contains value/weight
      float fraction[]=new float[n];
      int index[]=new int[n];
      for (int i=0;i<n;i++)
      {
        fraction[i]=(float)value[i]/(float)weight[i];
      }
      for (int i=0;i<n;i++)
      {
        index[i]=i;
      }

      //Sort fraction[] and index[] with respect to fraction
      for (int i=0;i<n;i++)
      {
        for (int j=0;j<n-1-i;j++)
        {
          if (fraction[j]<fraction[j+1])
          {
            float temp=fraction[j];
            fraction[j]=fraction[j+1];
            fraction[j+1]=temp;

            int temp1=index[j];
            index[j]=index[j+1];
            index[j+1]=temp1;
          }
        }
      }


      //Computing profit using greedy approach
      float profit=0.0f;
      int wgt=0;
      for (int i=0;i<n;i++)
      {
        int temp=wgt+weight[index[i]];
        if (wgt==wgt_knapsack)
          break;
        else if (temp<wgt_knapsack)
        {
          profit=profit+value[index[i]];
          wgt=temp;
        }
        else
        {
          int x=wgt_knapsack-wgt;
          //System.out.println("x="+x);
          wgt=wgt+x;
          //System.out.println("wgt="+wgt);
          float y=((float)x/(float)weight[index[i]]);
          //System.out.println("y="+y);
          profit=profit+(((float)value[index[i]])*y);
        }
      }

      //Printing the final answer
      System.out.println("Profit earned will be "+profit);
  }
}
