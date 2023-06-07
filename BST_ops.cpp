/*Beginning with an empty binary search tree, Construct binary search tree by inserting 
the values in the order given. After constructing a binary tree -
i. Insert new node, ii. Find number of nodes in longest path from root, iii. Minimum data 
value found in the tree, iv. Change a tree so that the roles of the left and right pointers 
are swapped at every node, v. Search a value*/
#include<iostream>
using namespace std;
class Node
{
public:
    int key;
    Node *ln, *rn;
};

class Tree
{
public:
    Node* root;
    Node* createTree(int key)
    {
        root = new Node();
        root->key = key;
        root->ln = NULL;
        root->rn = NULL;
        return root;
    }

    void insertNode(int key, Node* root)
    {
        Node* node = new Node();
        node->key = key;
        if (root->key >= key)
        {
            if (root->ln == NULL)
            {
                root->ln = node;
            }
            else
                insertNode(key, root->ln);
        }
        else if (root->key < key)
        {
            if (root->rn == NULL)
            {
                root->rn = node;
            }
            else
                insertNode(key, root->rn);
        }
    }

    void displayInorder(Node* root, int level)
    {
        if (root != NULL)
        {
            displayInorder(root->ln, level + 1);
            for (int i = 0; i < level; i++)
                cout << "\t";
            cout << root->key << "\n";
            displayInorder(root->rn, level + 1);
        }
    }


    void displayFirst(Node* root)
    {
        while (root->ln != NULL)
        {
            root = root->ln;
        }
        cout << "\nMinimum number is " << root->key;
    }

    void search(Node* root, int searchKey)
    {
        if (searchKey < root->key)
        {
            if (root->ln == NULL && root->rn == NULL)
                cout << "\nNumber not found";
            else
                search(root->ln, searchKey);
        }

        else if (searchKey > root->key)
        {
            if (root->ln == NULL && root->rn == NULL)
                cout << "\nNumber not found";
            else
                search(root->rn, searchKey);
        }

        else if (searchKey == root->key)
        {
            cout << "\nNumber Found!";
        }
    }

    int longestPath(Node* root)
    {
        if (root == NULL)
            return 0;
        int Lctr = longestPath(root->ln);
        int Rctr = longestPath(root->rn);
        if (Lctr > Rctr)
            return (Lctr + 1);
        else
            return (Rctr + 1);
    }

    Node* swapNodes(Node* root)
    {
        Node* temp;
        if (root == NULL)
            return NULL;

        temp = root->ln;
        root->ln = root->rn;
        root->rn = temp;

        swapNodes(root->ln);
        swapNodes(root->rn);
    }

};

int main()
{
    int choice, order, flag = 0;
    int key, searchKey;
    Tree t1;
    Node* root;
    do
    {
        cout << "\n1. Enter a number \n2. Display \n3. Swap left and right nodes \n4. Search \n5. Exit ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "\nEnter the number: ";
            cin >> key;
            if (flag == 0)
            {
                root = t1.createTree(key);
                flag = 1;
            }
            else
            {
                t1.insertNode(key, root);
            }
            break;

        case 2:
            cout << "\n1. Display list \n2. Show minimum number \n3. Show number of nodes in the longest path ";
            cin >> order;
            switch (order)
            {
            case 1:
                cout << "Inorder Traversal:\n";
                t1.displayInorder(root, 0);
                break;
            case 2:
                t1.displayFirst(root);
                break;
            case 3:
                cout << "The height of the tree or the longest path is: " << t1.longestPath(root);
                break;
            }

            break;

        case 3:
            t1.swapNodes(root);
            cout << "Swapped! The new list is: ";
            t1.displayInorder(root, 0);
            break;

        case 4:
            cout << "\nEnter the number you want to search: ";
            cin >> searchKey;
            t1.search(root, searchKey);
            break;

        case 5:
            break;
        }
    } while (choice != 5);
    return 0;
}
/*1. Enter a number 
2. Display 
3. Swap left and right nodes 
4. Search 
5. Exit 1
Enter the number: 2
1. Enter a number 
2. Display 
3. Swap left and right nodes 
4. Search 
5. Exit 1
Enter the number: 3
1. Enter a number 
2. Display 
3. Swap left and right nodes 
4. Search 
5. Exit 1
Enter the number: 4
1. Enter a number 
2. Display 
3. Swap left and right nodes 
4. Search 
5. Exit 2
1. Display list 
2. Show minimum number 
3. Show number of nodes in the longest path 1
Inorder Traversal:
2
	3
		4

1. Enter a number 
2. Display 
3. Swap left and right nodes 
4. Search 
5. Exit */
