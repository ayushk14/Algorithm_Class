import java.util.*;
public class treeTraversal
{

  /*
    class Node
    {
        int data;
        Node left;
        Node right;
    }
  */
  //--------------------------Level Order Traversal--------------------------
  void levelOrder(Node root)
   {
       Node a[]=new Node[500];
       int front,rear;
       front=-1;
       rear=-1;
       System.out.print(root.data+" ");
       if (root.left!=null)
       {
           front++;
           //rear++;
           a[front]=root.left;
       }
       if (root.right!=null)
       {
           front++;
           a[front]=root.right;
           //if (rear==-1)
               //rear++;
       }
       while(root!=null)
       {
            if (front!=-1)
            {
                rear++;
                root=a[rear];
                System.out.print(root.data+" ");
                //rear++;
                if (root.left!=null)
                {
                    front++;
                    a[front]=root.left;
                }
                if (root.right!=null)
                {
                    front++;
                    a[front]=root.right;
                }
            }
       }
   }


   //-------------------------Inorder Traversal---------------------------------
   void inOrder(Node root)
   {
     if (root!=null)
     {
        inOrder(root.left);
        System.out.print(root.data+" ");
        inOrder(root.right);
    }
  }


  //----------------------Preorder Traversal------------------------------------
  void preOrder(Node root)
  {
    if (root!=null)
    {
        System.out.print(root.data+" ");
        preOrder(root.left);
        preOrder(root.right);
    }
  }


  //--------------------Postorder Traversal-------------------------------------
  void postOrder(Node root)
  {
    if (root!=null)
    {
        postOrder(root.left);
        postOrder(root.right);
        System.out.print(root.data+" ");
    }
  }
}
