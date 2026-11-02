#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int value)
    {
        data = value;
        left = NULL;
        right = NULL;
    }
};

class Tree
{
public:
    Node* create()
    {
        int value;

        cout << "Enter value (-1 for no node): ";
        cin >> value;

        if (value == -1)
        {
            return NULL;
        }

        Node *newNode = new Node(value);

        cout << "Enter left child of " << value << endl;
        newNode->left = create();

        cout << "Enter right child of " << value << endl;
        newNode->right = create();

        return newNode;
    }

    // Recursive Inorder Traversal
    void inorder(Node *root)
    {
        if (root == NULL)
        {
            return;
        }

        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }

    // Recursive Preorder Traversal
    void preorder(Node *root)
    {
        if (root == NULL)
        {
            return;
        }

        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }

    // Recursive Postorder Traversal
    void postorder(Node *root)
    {
        if (root == NULL)
        {
            return;
        }

        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
};

int main()
{
    Tree t;
    Node *root = NULL;
    int choice;

    cout << "Create Binary Tree\n";
    root = t.create();

    do
    {
        cout << "\n\n--- MENU ---";
        cout << "\n1. Inorder Traversal";
        cout << "\n2. Preorder Traversal";
        cout << "\n3. Postorder Traversal";
        cout << "\n4. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "\nInorder: ";
            t.inorder(root);
            cout << endl;
            break;

        case 2:
            cout << "\nPreorder: ";
            t.preorder(root);
            cout << endl;
            break;

        case 3:
            cout << "\nPostorder: ";
            t.postorder(root);
            cout << endl;
            break;

        case 4:
            cout << "\nProgram ended.";
            break;

        default:
            cout << "\nInvalid choice!";
        }

    } while (choice != 4);

    return 0;
}

