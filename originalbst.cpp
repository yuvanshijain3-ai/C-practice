#include <iostream>
using namespace std;

//=====================================================
// NODE CLASS
// Represents one node of the Binary Search Tree
//=====================================================
class Node
{
public:
    int data;
    Node *left;
    Node *right;

    // Constructor
    Node(int value)
    {
        data = value;
        left = NULL;
        right = NULL;
    }
};

//=====================================================
// BST CLASS
//=====================================================
class BST
{
private:
    Node *root;

    //=================================================
    // Insert a node recursively
    //=================================================
    Node* insert(Node *root, int value)
    {
        // If position is empty, create a new node
        if (root == NULL)
        {
            return new Node(value);
        }

        // Insert into left subtree
        if (value < root->data)
        {
            root->left = insert(root->left, value);
        }

        // Insert into right subtree
        else if (value > root->data)
        {
            root->right = insert(root->right, value);
        }

        // Duplicate value
        else
        {
            cout << "Duplicate value " << value
                 << " is not inserted.\n";
        }

        return root;
    }

    //=================================================
    // Copy the original BST
    //=================================================
    Node* copyTree(Node *root)
    {
        // If original tree is empty
        if (root == NULL)
        {
            return NULL;
        }

        // Create a new node
        Node *newNode = new Node(root->data);

        // Copy left subtree
        newNode->left = copyTree(root->left);

        // Copy right subtree
        newNode->right = copyTree(root->right);

        return newNode;
    }

    //=================================================
    // Find height of the tree
    //=================================================
    int findHeight(Node *root)
    {
        // Empty tree has height 0
        if (root == NULL)
        {
            return 0;
        }

        // Find height of left subtree
        int leftHeight = findHeight(root->left);

        // Find height of right subtree
        int rightHeight = findHeight(root->right);

        // Return greater height + 1
        if (leftHeight > rightHeight)
        {
            return leftHeight + 1;
        }
        else
        {
            return rightHeight + 1;
        }
    }

    //=================================================
    // Display leaf nodes
    //=================================================
    void displayLeaves(Node *root)
    {
        // Tree is empty
        if (root == NULL)
        {
            return;
        }

        // A leaf node has no left and right child
        if (root->left == NULL && root->right == NULL)
        {
            cout << root->data << " ";
            return;
        }

        // Check left subtree
        displayLeaves(root->left);

        // Check right subtree
        displayLeaves(root->right);
    }

public:

    //=================================================
    // Constructor
    //=================================================
    BST()
    {
        root = NULL;
    }

    //=================================================
    // Create BST
    //=================================================
    void createBST()
    {
        int n, value;

        cout << "\nEnter number of nodes: ";
        cin >> n;

        for (int i = 1; i <= n; i++)
        {
            cout << "Enter value " << i << ": ";
            cin >> value;

            root = insert(root, value);
        }

        cout << "\nBST created successfully.\n";
    }

    //=================================================
    // Display BST Level-Wise
    // Manual Queue implementation
    //=================================================
    void displayLevelWise()
    {
        if (root == NULL)
        {
            cout << "\nTree is empty.\n";
            return;
        }

        // Maximum queue size
        Node *queue[100];

        int front = 0;
        int rear = 0;

        // Insert root into queue
        queue[rear] = root;
        rear++;

        cout << "\nLevel-Wise BST:\n";

        while (front < rear)
        {
            // Number of nodes at current level
            int nodesAtLevel = rear - front;

            cout << "Level: ";

            for (int i = 0; i < nodesAtLevel; i++)
            {
                // Remove node from queue
                Node *current = queue[front];
                front++;

                cout << current->data << " ";

                // Insert left child
                if (current->left != NULL)
                {
                    queue[rear] = current->left;
                    rear++;
                }

                // Insert right child
                if (current->right != NULL)
                {
                    queue[rear] = current->right;
                    rear++;
                }
            }

            cout << endl;
        }
    }

    //=================================================
    // Create New BST by copying original BST
    //=================================================
    BST* createNewTree()
    {
        BST *newTree = new BST();

        newTree->root = copyTree(root);

        return newTree;
    }

    //=================================================
    // Display Height
    //=================================================
    void displayHeight()
    {
        int height = findHeight(root);

        cout << "\nHeight of BST = " << height << endl;
    }

    //=================================================
    // Display Leaf Nodes
    //=================================================
    void displayLeafNodes()
    {
        if (root == NULL)
        {
            cout << "\nTree is empty.\n";
            return;
        }

        cout << "\nLeaf Nodes: ";

        displayLeaves(root);

        cout << endl;
    }
};

//=====================================================
// MAIN FUNCTION
// Menu is implemented inside main()
//=====================================================
int main()
{
    BST originalTree;
    BST *newTree = NULL;

    int choice;

    do
    {
        cout << "\n========================================";
        cout << "\n       BINARY SEARCH TREE MENU";
        cout << "\n========================================";
        cout << "\n1. Create Original BST";
        cout << "\n2. Display Original BST Level-Wise";
        cout << "\n3. Create New BST by Copying Original BST";
        cout << "\n4. Display New BST Level-Wise";
        cout << "\n5. Find Height of Original BST";
        cout << "\n6. Display Leaf Nodes of Original BST";
        cout << "\n7. Exit";
        cout << "\n========================================";

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            originalTree.createBST();
            break;

        case 2:
            cout << "\nOriginal BST";
            originalTree.displayLevelWise();
            break;

        case 3:
            if (newTree != NULL)
            {
                delete newTree;
                newTree = NULL;
            }

            newTree = originalTree.createNewTree();

            cout << "\nNew BST created successfully.\n";
            break;

        case 4:
            if (newTree == NULL)
            {
                cout << "\nFirst create the New BST using option 3.\n";
            }
            else
            {
                cout << "\nNew BST";
                newTree->displayLevelWise();
            }
            break;

        case 5:
            originalTree.displayHeight();
            break;

        case 6:
            originalTree.displayLeafNodes();
            break;

        case 7:
            cout << "\nProgram terminated.\n";
            break;

        default:
            cout << "\nInvalid choice. Please try again.\n";
        }

    } while (choice != 7);

    // Release dynamically allocated new BST
    if (newTree != NULL)
    {
        delete newTree;
    }

    return 0;
}