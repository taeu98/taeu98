#include <iostream>
#include <queue>
using namespace std;

class node
{
public:
    int data;
    node *parent;
    node *left;
    node *right;
    node(int data)
    {
        this->data = data;
        this->parent = NULL;
        this->left = NULL;
        this->right = NULL;
    }
};

class BinarySearchTree
{
public:
    node *root;
    BinarySearchTree();
    ~BinarySearchTree();
    void Display(node *root);
    void DFS(node *root);
    void BFS(node *root);
    void insert(int data);
};

BinarySearchTree::BinarySearchTree()
{
    root = NULL;
}
BinarySearchTree::~BinarySearchTree()
{
    delete root;
}
void BinarySearchTree::Display(node *root)
{
    if (root == NULL)
        return;
    Display(root->left);
    cout << root->data << " ";
    Display(root->right);
}
void BinarySearchTree::DFS(node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    DFS(root->left);
    DFS(root->right);
}
void BinarySearchTree::BFS(node *root)
{
    if (root == NULL)
        return;
    queue<node *> q;
    q.push(root);
    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();
        cout << temp->data << " ";
        if (temp->left != NULL)
            q.push(temp->left);
        if (temp->right != NULL)
            q.push(temp->right);
    }
}
void BinarySearchTree::insert(int data)
{
    node *newNode = new node(data);
    if (root == NULL)
    {
        root = newNode;
        return;
    }
    node *temp = root;
    while (temp != NULL)
    {
        if (data < temp->data)
        {
            if (temp->left == NULL)
            {
                temp->left = newNode;
                newNode->parent = temp;
                return;
            }
            temp = temp->left;
        }
        else
        {
            if (temp->right == NULL)
            {
                temp->right = newNode;
                newNode->parent = temp;
                return;
            }
            temp = temp->right;
        }
    }
}
int main()
{
    BinarySearchTree BST;
    BST.insert(4);
    BST.insert(2);
    BST.insert(6);
    BST.insert(1);
    BST.insert(3);
    BST.insert(5);
    BST.insert(7);
    cout << "Insert : 4 2 6 1 3 5 7" << endl;
    cout << "DFS    : ";
    BST.DFS(BST.root);
    cout << endl;
    cout << "BFS    : ";
    BST.BFS(BST.root);
    cout << endl;
    cout << "Display: ";
    BST.Display(BST.root);
    cout << endl;
    return 0;
}