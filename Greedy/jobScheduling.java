import java.util.*;
public class jobScheduling
{
    public static void main(String args[])
    {
      //Taking input from users
      Scanner scan=new Scanner(System.in);
      System.out.print("Enter number of jobs to scheduled : ");
      int n=scan.nextInt();
      System.out.println("Enter some details for each job:");
      int start_time[]=new int[n];
      int end_time[]=new int[n];
      for (int i=0;i<n;i++)
      {
        System.out.print("Enter the start time for job "+(i+1)+" : ");
        start_time[i]=scan.nextInt();
        System.out.print("Enter the end time for job "+(i+1)+" : ");
        end_time[i]=scan.nextInt();
      }

      int index[]=new int[n];
      for (int i=0;i<n;i++)
      {
        index[i]=i;
      }
      //Sort end_time[] and index[] with respect to end_time[]
      for (int i=0;i<n;i++)
      {
        for (int j=0;j<n-1-i;j++)
        {
          if (end_time[j]>end_time[j+1])
          {
            int temp=end_time[j];
            end_time[j]=end_time[j+1];
            end_time[j+1]=temp;

            temp=start_time[j];
            start_time[j]=start_time[j+1];
            start_time[j+1]=temp;

            temp=index[j];
            index[j]=index[j+1];
            index[j+1]=temp;
          }
        }
      }

      for (int i=0;i<n;i++)
        System.out.print(start_time[i]+"\t");
      System.out.println();
      for (int i=0;i<n;i++)
        System.out.print(end_time[i]+"\t");
      System.out.println();


      int jobs_scheduled=0;
      int t=0;
      t=t+(end_time[0]);
      jobs_scheduled++;
      System.out.println("Job "+(index[0]+1)+" gets scheduled havind start time "+start_time[0]+" and end time "+end_time[0]);
      //System.out.println("t="+t+"\tScheduled="+jobs_scheduled);
      for (int i=1;i<n;i++)
      {
        //System.out.println("i="+i);
        if (start_time[i]>=t)
        {
          //System.out.println("hii");
          t=t+(end_time[i]-start_time[i]);
          jobs_scheduled++;
          System.out.println("Job "+(index[i]+1)+" gets scheduled havind start time "+start_time[i]+" and end time "+end_time[i]);
          //System.out.println("t="+t+"\tScheduled="+jobs_scheduled);
        }
      }
      System.out.println("Total number of jobs scheduled is "+jobs_scheduled);
    }
}
