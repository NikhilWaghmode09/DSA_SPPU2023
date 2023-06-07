/*

Problem Statement : A book consists of chapters,chapters consist of sections and sections consist of subsections. Construct a tree and print the nodes. Find the time and space requirements of your method.

*/

# include <iostream>
# include <string.h>

using namespace std;

//Node Declaration
 
struct node
{
    char label[10];         // TO STORE CHAPTER HEAD,SECTION HEAD
    int ch_count;	    // To store no of child ele
    
    struct node *child[10]; //Array of pointers to store addresses of child nodes
}*root;     // To store the address of root

// Class Declaration

class BST
{
    public:
        void create_tree();  
 	void display(node * r1);
     
        BST()
        {
            root = NULL;
        }
};

void BST::create_tree()
{
 int tbooks,tchapters,i,j,k;
 
 root = new node();       // root node is created
  cout<<"Enter name of book";
 cin>>root->label;
 
 cout<<"Enter no. of chapters in book";
 cin>>tchapters; 
 root->ch_count = tchapters;
 
 for(i=0;i<tchapters;i++) //chapters
 {
  root->child[i] = new node;   //chapter is created

  cout<<"Enter Chapter name\n";
  cin>>root->child[i]->label;
   
  cout<<"Enter no.of sections in this Chapter:";
  cin>>root->child[i]->ch_count;

   for(j=0; j<root->child[i]->ch_count; j++)//sections
  
	{
		root->child[i]->child[j]=new node;
		cout<<"Enter section head";
		cin>>root->child[i]->child[j]->label;
  		
  	}  

 	}
}

void BST::display(node * r1)
{
 int i,j,k,tchapters;
 if(r1 != NULL)
 { 
  cout<<"\n-----Book Hierarchy---";

  cout<<"\n Book title : "<<r1->label;
  tchapters = r1->ch_count;  // how many chapters are there
  for(i=0;i<tchapters;i++)
  {
  
   cout<<"\n  Chapter "<<i+1;
   cout<<" "<<r1->child[i]->label;   
    cout<<"\n Sections";
   for(j=0;j<r1->child[i]->ch_count;j++)
   {
    //cin>>r1->child[i]->child[j]->label;   
    cout<<"\n  "<<r1->child[i]->child[j]->label;
   }  

  }
 }
}


/*
 * Main Contains Menu
 */
int main()
{
    int choice;
    BST bst;
    while (1)
    {
        cout<<"-----------------"<<endl;
        cout<<"Book Tree Creation"<<endl;
        cout<<"-----------------"<<endl;
        cout<<"1.Create"<<endl;
        cout<<"2.Display"<<endl;
        cout<<"3.Quit"<<endl;
        cout<<"Enter your choice : ";
        cin>>choice;
        switch(choice)
        {
        case 1:
              bst.create_tree();
        case 2:
              bst.display(root);
            break;
        case 3:
            exit(1);
        default:
            cout<<"Wrong choice"<<endl;
        }
    }
}

/* 

OUTPUT :

-----------------
Book Tree Creation
-----------------
1.Create
2.Display
3.Quit
Enter your choice : 1
Enter name of book DS
Enter no. of chapters in book 2
Enter Chapter name
A
Enter no.of sections in this Chapter:1
Enter section head X
Enter Chapter name
B
Enter no.of sections in this Chapter:1
Enter section head Y

-----Book Hierarchy---
 Book title : DS
  Chapter 1 A
 Sections
  X
  Chapter 2 B
 Sections
  Y-----------------
Book Tree Creation
-----------------
1.Create
2.Display
3.Quit
Enter your choice : 3



The time complexity for creating the book tree is O(tchapters * sections), and the space complexity is O(tchapters * sections), 
where tchapters is the number of chapters in the book and sections is the maximum number of sections in a chapter. 
The time complexity for displaying the book hierarchy is O(tchapters + sections), and the space complexity is O(1).
*/
