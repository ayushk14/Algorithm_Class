package subsequence;
// max subsequence i+k>=j
public class Subsequencev3 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int n=9;
		int k=2;
		int l=0;
		//int r=0;
		//int s[]=new int[n];
		int a[]= {-6,990,-4,20,700,1,-17,-2,98};
		int sum=a[0];
		int max=a[0];
		int j=1;
		int i=0;
		//s[0]=0;
		for(;j<=k;j++) {
			if(sum<0)
			{
				sum=0;
				l=j;
				//r++;
			}
			//s[++r] = j ;
			sum+=a[j];
			
			if(sum > max)
				max=sum;
		}
		System.out.println(sum);
		
		for(;j<n;j++) {
			
			if(sum<0)
			{
				sum=0;
				l=j;
			}
			sum+=a[j];
			if(j-l>k) {
				sum-=a[l++];
				System.out.println(sum);
				if(sum<0)
				{
					sum=0;
					l=j;
				}
			}
			if(sum > max)
				max=sum;
			
		}
		System.out.println(max);
	}

}
