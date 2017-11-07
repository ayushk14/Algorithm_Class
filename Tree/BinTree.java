import java.util.*;
public class BinTree
{
	String value;
	BinTree left;
	BinTree right;
	public BinTree(String data)
	{
		left=null;
		right=null;
		value=data;
	}
	public boolean find(BinTree n,String item)
	{
		if(n!=null)
		{
			if(n.value.compareTo(item)==0)
				return true;
			else
				return find(n.left,item) || find(n.right,item);
		}
		return false;
	}
	int count=0;
	public int numberOfNodes(BinTree n)
	{
		if (n!=null)
		{
			count++;
			if(n.left!=null)
				numberOfNodes(n.left);
			if(n.right!=null)
				numberOfNodes(n.right);	
		}
		return count;
	}
	public BinTree isDescendent(BinTree n,String item,BinTree p)
	{
		if (n==null)
			return null;
		if (n.value.compareTo(item)==0)
			return p;
		else
		{
			if(find(n.left,item))
				return isDescendent(n.left,item,n);
			else
				return isDescendent(n.right,item,n);			
		}
	}
	public BinTree isSibling(BinTree n,String item)
	{
		BinTree psp=isDescendent(n,item,n);
		if (psp.left.value.compareTo(item)!=0)
			return psp.left;
		else
			return psp.right;
	}
	public BinTree isCousin(BinTree n,String item)
	{
		BinTree des=isDescendent(n,item,n);
		if (des.value.compareTo(n.value)==0)
			return n;
		BinTree sib=isSibling(n,des.value);
		return sib;
	}
	public BinTree closestCommonAncestor(BinTree n,String item, String another_item)
	{
		BinTree des1,des2;
		while(true)
		{
			des1=isDescendent(n,item,n);
			des2=isDescendent(n,another_item,n);
			if (des1.value.compareTo(des2.value)!=0)
			{
				item=des1.value;
				another_item=des2.value;
				continue;
			}
			else
				break;
		}
		return des1;
	}
}
/*public class Q5
{	
	public static void main(String args[])
	{
		Boolean check;
		System.out.print("Enter a member name : ");
		Scanner scan=new Scanner(System.in);
		String temp=scan.nextLine();
		BinTree n=new BinTree("Gajanan Khopkar");
		n.left=new BinTree("Pradeep Khopkar");
		n.right=new BinTree("Prakash Khopkar");
		n.left.left=new BinTree("Piyush Khopkar");
		n.left.right=new BinTree("Ayush Khopkar");
		n.right.left=new BinTree("Shreyas Khopkar");
		n.right.right=new BinTree("Shruti Khopkar");
		
		System.out.println("Member is present (True or False) : "+n.find(n,temp));			
		
		System.out.println("Numebr of members : "+n.numberOfNodes(n));	
		
		if (!n.find(n,temp))
			System.out.println("No node present");
		else
		{
			if (n.value.compareTo(temp)==0)
				System.out.println("No descendent");
			else
			{
				System.out.print("Enter another member name : ");
				scan=new Scanner(System.in);
				String temp_another=scan.nextLine();
				BinTree temp_tree=n.isDescendent(n,temp,n);
				if (temp_tree.value.compareTo(temp_another)==0)
					check=true;
				else
					check=false;
				System.out.println(temp+" is descendent of "+temp_another+" (true or false) : "+check);
			}
		}
		
		if (!n.find(n,temp))
			System.out.println("No node present");
		else
		{
			if (n.value.compareTo(temp)==0)
				System.out.println("No Sibling");
			else
			{
				System.out.print("Enter another member name : ");
				scan=new Scanner(System.in);
				String temp_another=scan.nextLine();
				BinTree temp_tree=n.isSibling(n,temp);
				if (temp_tree.value.compareTo(temp_another)==0)
					check=true;
				else
					check=false;
				System.out.println(temp+" is sibling of "+temp_another+" (true or false) : "+check);
			}
		}
		
		if (!n.find(n,temp))
			System.out.println("No node present");
		else
		{
			if (n.value.compareTo(temp)==0)
				System.out.println("No Cousin");
			else
			{
				BinTree temp_tree=n.isCousin(n,temp);
				if (n.value.compareTo(temp_tree.value)==0)
					System.out.println("No Cousin");
				else
				{
					System.out.print("Enter another member name : ");
					scan=new Scanner(System.in);
					String temp_another=scan.nextLine();
					if ((temp_tree.left.value.compareTo(temp_another)==0) || (temp_tree.right.value.compareTo(temp_another)==0))
						check=true;
					else
						check=false;
					System.out.println(temp+" is cousin of "+temp_another+" (true or false) : "+check);
				}
			}
		}
		
		if (!n.find(n,temp))
			System.out.println("No node present");
		else
		{
			if (n.value.compareTo(temp)==0)
				System.out.println("Closest Common Ancestor is : "+n.value);
			else
			{
				System.out.print("Enter another member name : ");
				scan=new Scanner(System.in);
				String temp_another=scan.nextLine();
				BinTree temp_tree=n.closestCommonAncestor(n,temp,temp_another);
				System.out.println("Closest Common Ancestor of "+temp+" and "+temp_another+" is : "+temp_tree.value);
			}
		}
	}
}*/
