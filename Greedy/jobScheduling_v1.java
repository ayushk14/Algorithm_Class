import java.util.*;
public class jobScheduling_v1
{
  public static int findConflict(int start_time[],int end_time[],int n,int max_end_time)
  {
    int grid[][]=new int[n][max_end_time];
    for (int i=0;i<n;i++)
    {
      for (int j=0;j<max_end_time;j++)
      {
        grid[i][j]=0;
      }
    }
    for (int i=0;i<n;i++)
    {
      for (int j=start_time[i];j<end_time[i];j++)
      {
        grid[i][j]=1;
      }
    }

    int max=0;
    for (int j=0;j<max_end_time;j++)
    {
      int count=0;
      for (int i=0;i<n;i++)
      {
        if (grid[i][j]==1)
          count++;
      }
      if (count>max)
        max=count;
    }
    return max;
  }


  
  public static void main(String args[])
  {
    //Taking input from users
    Scanner scan=new Scanner(System.in);
    System.out.print("Enter number of jobs to scheduled : ");
    int n=scan.nextInt();
    System.out.println("Enter some details for each job:");
    int start_time[]=new int[n];
    int end_time[]=new int[n];
    int max_end_time=0;
    for (int i=0;i<n;i++)
    {
      System.out.print("Enter the start time for job "+(i+1)+" : ");
      start_time[i]=scan.nextInt();
      System.out.print("Enter the end time for job "+(i+1)+" : ");
      end_time[i]=scan.nextInt();
      if (end_time[i]>max_end_time)
        max_end_time=end_time[i];
    }

    int index[]=new int[n];
    for (int i=0;i<n;i++)
    {
      index[i]=i;
    }
    //Sort start_time[] and end_time[] with respect to start_time[]
    for (int i=0;i<n;i++)
    {
      for (int j=0;j<n-1-i;j++)
      {
        if (start_time[j]>start_time[j+1])
        {
          int temp=start_time[j];
          start_time[j]=start_time[j+1];
          start_time[j+1]=temp;

          temp=end_time[j];
          end_time[j]=end_time[j+1];
          end_time[j+1]=temp;

          temp=index[j];
          index[j]=index[j+1];
          index[j+1]=temp;
        }
      }
    }

    //Find maximum number of conflicts
    int num_conflicts=findConflict(start_time,end_time,n,max_end_time);
    System.out.println(num_conflicts);
  }
}
