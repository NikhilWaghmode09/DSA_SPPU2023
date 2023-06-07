/*A Dictionary stores keywords & its meanings. Provide facility for adding new keywords,
deleting keywords, updating values of any entry. Provide facility to display whole data
sorted in ascending/ Descending order. Also find how many maximum comparisons may
require for finding any keyword. Use Binary Search Tree for implementation. */

#include <iostream>
#include <cstdlib>
using namespace std;
// Node class to represent each node in the Binary Search Tree
class node
{
    public:
        node *left;
        node *right;
        string word;
        string meaning;
};
// Dictionary class to implement the operations
class Dict
{
    public:
        node *root;
// Constructor to initialize the root of the Binary Search Tree
        Dict()
        {
            root = NULL;
        }
        void create();// Function to create a new node and insert it into the Binary Search Tree
        void insert(node*,node*); // Recursive function to insert a node into the Binary Search Tree
        void inorder(node*);// Recursive function to perform inorder traversal of the Binary Search Tree
        void descend(node*);// Recursive function to perform descending order traversal of the Binary Search Tree
        void search(node*,string);// Recursive function to search for a word in the Binary Search Tree
        void modify(node*,string);// Recursive function to modify the meaning of a word in the Binary Search Tree
        node* minValue(node*); // Helper function to find the node with the minimum value in a subtree
        node* deleteNode(node*,string);// Recursive function to delete a node from the Binary Search Tree
};
void Dict :: create()
{
    node *temp;
    temp = new node;
    cout << "Enter word :";
    cin >> temp->word;
    cin.ignore();
    cout << "Enter meaning: ";
    getline(cin,temp->meaning);
    temp->left = temp->right = NULL;
 // If the tree is empty, make the new node as the root
    if (root == NULL)
    {
        root = temp;
    }
    else
    {
        insert(root,temp); // Otherwise, insert the node recursively
    }
}
void Dict :: insert(node *root,node *temp)
{
    if(temp->word < root->word)
    {
        if(root->left == NULL)
        {
            root->left = temp;
        }
        else
        {
            insert(root->left,temp);// If the word is smaller than the current node, insert into the left subtree
        }
    }
    else
    {
        if(root->right == NULL)
        {
            root->right = temp;
        }
        else
        {
            insert(root->right,temp); // If the word is greater than or equal to the current node, insert into the right subtree
        }
    }    
    }

void Dict :: inorder(node *temp)
{
    if (temp!=NULL)
    {
        inorder(temp->left); // Traverse the left subtree
        cout << temp->word << endl; // Visit the current node
        inorder(temp->right); // Traverse the right subtree
    }
}
void Dict :: descend(node *temp)
{
    if (temp!=NULL)
    {
        descend(temp->right); // Traverse the right subtree
        cout << temp->word << endl; // Visit the current node
        descend(temp->left); // Traverse the left subtree
    }
}
void Dict :: search(node *root,string key)
{
    if (key.compare(root->word)< 0)
    {
        if(root->left == NULL)
        {
            cout << "Word not found!!" << endl;
        }
        else
            search(root->left,key);// If the word is smaller than the current node, search in the left subtree
    }
    else if (key.compare(root->word)> 0)
    {
        if(root->right == NULL)
        {
            cout << "Word not found!!" << endl;
        }
        else
            search(root->right,key);
    }
    else
    {
        cout << "Word: "<< root->word << endl;
        cout << "Meaning: "<< root->meaning << endl;
    }
}

void Dict :: modify(node *root,string key)
{
    if (key.compare(root->word)< 0)
    {
        if(root->left == NULL)
        {
            cout << "Word not found!!" << endl;
        }
        else
            modify(root->left,key);
    }
    else if (key.compare(root->word)> 0)
    {
        if(root->right == NULL)
        {
            cout << "Word not found!!" << endl;
        }
        else
            modify(root->right,key);
    }
    else
    {
        cout << "Word: "<< root->word << endl;
        cin.ignore();
        cout << "Enter new meaning: ";
        getline(cin,root->meaning);
    }
}

node* Dict :: minValue(node *root)
{
    node *curr;
    curr = new node;
    curr = root;
    while (curr->left != NULL)
        curr = curr->left;
    return curr;    
}

node* Dict :: deleteNode(node *root, string key)
{
    if(root==NULL)
        return root;
    node *temp;
    temp = new node;    
    if (key.compare(root->word)< 0)
    {
        if(root->left == NULL)
        {
            cout << "Word not found!!" << endl;
        }
        else
            root->left = deleteNode(root->left,key);
    }
    else if (key.compare(root->word)> 0)
    {
        if(root->right == NULL)
        {
            cout << "Word not found!!" << endl;
        }
        else
            root->right = deleteNode(root->right,key);
    }
    else{
        if(root->left == NULL)
        {
            temp = root->right;
            delete(root);
            return temp;
        }
         if(root->right == NULL)
        {
            temp = root->left;
            delete(root);
            return temp;
        }
        temp = minValue(root->right);
        root->word = temp->word;
        root->meaning = temp->meaning;
        root->right = deleteNode(root->right,temp->word);
    }
    return root;
}
int main()
{
    Dict d;
    string key;
    int n,ch;
    do
    {
        d.create();
        cout << "Do u want to continue(1/0): ";
        cin >> n;
    }while(n==1);

    while(1)
    {
        cout << "\n1. Enter a word";
        cout << "\n2. Ascending order";
        cout << "\n3. Descending order";
        cout << "\n4. Search";
        cout << "\n5. Modify";
        cout << "\n6. Delete";
        cout << "\n7. Exit";
        cout << "\nEnter your choice: ";
        cin >> ch;

        switch(ch)
        {
            case 1:
            d.create();
            break;

            case 2:
            cout << "Ascending order: "<< endl;
            d.inorder(d.root);
            break;

            case 3:
            cout << "Descending order: "<< endl;
            d.descend(d.root);
            break;

            case 4:
            cout << "\nEnter word you want to search: ";
            cin >> key;
            d.search(d.root, key);
            break;

            case 5:
            cout << "\nEnter word you want to modify: ";
            cin >> key;
            d.modify(d.root, key);
            break;

            case 6:
            cout << "\nEnter word u want to delete:";
            cin >> key;
            d.root = d.deleteNode(d.root, key);
            break;

            case 7:
                exit(1);
                break;

            default:
            cout << "\nInvalid choice";
            break;
        }
    }
    return 0;
}
/*Define a class named node to represent each node in the Binary Search Tree. It has member variables left and right pointers to its left and right children, and word and meaning to store the keyword and its meaning.

Define a class named Dict to implement the operations of the dictionary. It has a member variable root to store the root of the Binary Search Tree.

Implement a constructor for the Dict class to initialize the root as NULL.

Implement the create function in the Dict class to create a new node by taking input for the word and its meaning. If the tree is empty, make the new node as the root. Otherwise, call the insert function to insert the node into the Binary Search Tree.

Implement the insert function in the Dict class to recursively insert a node into the Binary Search Tree. If the word is smaller than the current node's word, go to the left subtree. If the left child is NULL, insert the new node as the left child; otherwise, recursively call the insert function on the left subtree. If the word is greater than or equal to the current node's word, go to the right subtree. If the right child is NULL, insert the new node as the right child; otherwise, recursively call the insert function on the right subtree.

Implement the inorder function in the Dict class to perform an inorder traversal of the Binary Search Tree. Recursively traverse the left subtree, visit the current node, and then recursively traverse the right subtree. Print the word of each node.

Implement the descend function in the Dict class to perform a descending order traversal of the Binary Search Tree. Recursively traverse the right subtree, visit the current node, and then recursively traverse the left subtree. Print the word of each node.

Implement the search function in the Dict class to search for a word in the Binary Search Tree. Compare the given key with the current node's word. If the key is smaller, go to the left subtree. If the left child is NULL, the word is not found. Otherwise, recursively call the search function on the left subtree. If the key is greater, go to the right subtree. If the right child is NULL, the word is not found. Otherwise, recursively call the search function on the right subtree. If the key is found, print the word and its meaning.

Implement the modify function in the Dict class to modify the meaning of a word in the Binary Search Tree. Compare the given key with the current node's word. If the key is smaller, go to the left subtree. If the left child is NULL, the word is not found. Otherwise, recursively call the modify function on the left subtree. If the key is greater, go to the right subtree. If the right child is NULL, the word is not found. Otherwise, recursively call the modify function on the right subtree. If the key is found, prompt the user to enter the new meaning and update the meaning of the node.

Implement the minValue function in the Dict class to find the node with the minimum value in a subtree. Starting from the given node, go to the left child until the left child is NULL. Return the current node.

Implement the deleteNode function in the Dict class to delete a node from the Binary Search Tree. If the root is NULL, return NULL. Compare the given key with the current node's word. If the key is smaller, go to the left subtree. If the left child is NULL, the word is not found. Otherwise, recursively call the deleteNode function on the left subtree. If the key is greater, go to the right subtree. If the right child is NULL, the word is not found. Otherwise, recursively call the deleteNode function on the right subtree. If the key is found, perform the deletion based on the following cases:

If the node has no left child, replace the node with its right child.
If the node has no right child, replace the node with its left child.
If the node has both left and right children, find the node with the minimum value in the right subtree, copy its word and meaning to the current node, and recursively delete the minimum node from the right subtree.
In the main function, create an instance of the Dict class and a string variable key to store user input.

Use a loop to continuously prompt the user for input to create new nodes until they choose to stop.

Inside another loop, display a menu to the user and perform the chosen operation based on the input:

If the user chooses to enter a word, call the create function.
If the user chooses to display the words in ascending order, call the inorder function.
If the user chooses to display the words in descending order, call the descend function.
If the user chooses to search for a word, prompt for the word and call the search function.
If the user chooses to modify the meaning of a word, prompt for the word and call the modify function.
If the user chooses to delete a word, prompt for the word and call the deleteNode function.
If the user chooses to exit, terminate the program.
Add appropriate error handling and input validation where necessary.
*/
