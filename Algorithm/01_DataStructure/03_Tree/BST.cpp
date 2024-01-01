#include <iostream>
#include <queue>
using namespace std;

struct Node
{
    int data;
    Node *parent;
    Node *left;
    Node *right;
};

class binarySearchTree
{
private:
    Node *root;

public:
    binarySearchTree() { root = nullptr; }
    
    Node *getRoot();
    Node *find(int data);
    void insert(int data);
    void swap(Node *a, Node *b);
    void erase(int data);
    void erase(Node *data);
    void print(Node *node);
    void DFS(Node *node);
    void BFS(Node *node);
};
Node *binarySearchTree::getRoot() { return root; }

Node *binarySearchTree::find(int data)
{
    Node *cur = root;
    if (cur == nullptr)
        return nullptr;

    while (1)
    {
        while (cur->data > data)
            cur = cur->left;

        while (cur->data <= data)
        {
            if (cur->data == data)
                return cur;
            cur = cur->right;
        }

        if (cur == nullptr)
            return nullptr;
    }
}

void binarySearchTree::insert(int data)
{
    Node *new_node = new Node;
    if (root == nullptr)
    {
        new_node->data = data;
        new_node->parent = nullptr;
        new_node->left = nullptr;
        new_node->right = nullptr;
        root = new_node;
        return;
    }

    Node *cur = root;
    while (1)
    {
        while (cur->data > data)
        {
            if (cur->left == nullptr)
            {
                new_node->data = data;
                new_node->parent = cur;
                new_node->left = nullptr;
                new_node->right = nullptr;
                cur->left = new_node;
                return;
            }
            else
                cur = cur->left;
        }
        while (cur->data <= data)
        {
            if (cur->right == nullptr)
            {
                new_node->data = data;
                new_node->parent = cur;
                new_node->left = nullptr;
                new_node->right = nullptr;
                cur->right = new_node;
                return;
            }
            else
                cur = cur->right;
        }
    }
}

void binarySearchTree::swap(Node *a, Node *b)
{
    Node *tmp = new Node;
    if (a->parent->left == a)
        a->parent->left = b;
    else
        a->parent->right = b;

    if (b->parent->left == b)
        b->parent->left = a;
    else
        b->parent->right = a;

    tmp->data = b->data;
    b->data = a->data;
    a->data = tmp->data;

    tmp->parent = b->parent;
    b->parent = a->parent;
    a->parent = tmp->parent;

    tmp->left = b->left;
    b->left = a->left;
    a->left = tmp->left;

    tmp->right = b->right;
    b->right = a->right;
    a->right = tmp->right;

    delete (tmp);
}

void binarySearchTree::erase(int data)
{
    Node *delNode = find(data);
    if (delNode == nullptr)
        return;

    if (delNode->left == nullptr && delNode->right == nullptr)
    {
        if (delNode->parent->left == delNode)
            delNode->parent->left = nullptr;
        else
            delNode->parent->right = nullptr;
    }
    else if (delNode->left == nullptr)
    {
        if (delNode->parent->left == delNode)
            delNode->parent->left = delNode->right;
        else
            delNode->parent->right = delNode->right;

        delNode->right->parent = delNode->parent;
    }
    else if (delNode->right == nullptr)
    {
        if (delNode->parent->left == delNode)
            delNode->parent->left = delNode->left;
        else
            delNode->parent->right = delNode->left;

        delNode->left->parent = delNode->parent;
    }
    else
    {
        Node *cur = delNode->right;
        while (cur->left != nullptr)
            cur = cur->left;

        swap(cur, delNode);

        if (delNode->parent->left == delNode)
            delNode->parent->left = nullptr;
        else
            delNode->parent->right = nullptr;
    }
    delete (delNode);
}
void binarySearchTree::erase(Node *node)
{
    if (node->left == nullptr && node->right == nullptr)
    {
        if (node->parent->left == node)
            node->parent->left = nullptr;
        else
            node->parent->right = nullptr;
    }
    else if (node->left == nullptr)
    {
        if (node->parent->left == node)
            node->parent->left = node->right;
        else
            node->parent->right = node->right;
        node->right->parent = node->parent;
    }
    else if (node->right == nullptr)
    {
        if (node->parent->left == node)
            node->parent->left = node->left;
        else
            node->parent->right = node->left;
        node->left->parent = node->parent;
    }
    else
    {
        Node *cur = node->right;
        while (cur->left != nullptr)
            cur = cur->left;
        swap(cur, node);
        if (node->parent->left == node)
            node->parent->left = nullptr;
        else
            node->parent->right = nullptr;
    }
    delete (node);
}

void binarySearchTree::print(Node *node)
{
    if (node == nullptr)
        return;
    print(node->left);
    cout << node->data << " ";
    print(node->right);
}


void binarySearchTree::DFS(Node *node)
{
    if (node == nullptr)
        return;
    cout << node->data << " ";
    DFS(node->left);
    DFS(node->right);
}

void binarySearchTree::BFS(Node *node)
{
    if (node == nullptr)
        return;
    queue<Node *> q;
    q.push(node);
    while (!q.empty())
    {
        Node *cur = q.front();
        q.pop();
        cout << cur->data << " ";
        if (cur->left != nullptr)
            q.push(cur->left);
        if (cur->right != nullptr)
            q.push(cur->right);
    }
}

int main()
{
    binarySearchTree *bst = new binarySearchTree();
    cout << "Insert: 5 2 3 4 1 6 7" << endl;
    bst->insert(5);
    bst->insert(2);
    bst->insert(3);
    bst->insert(4);
    bst->insert(1);
    bst->insert(6);
    bst->insert(7);

    cout << "DFS: ";
    bst->DFS(bst->getRoot());
    cout << endl;

    cout << "BFS: ";
    bst->BFS(bst->getRoot());
    cout << endl;

    cout << "PRT: ";
    bst->print(bst->getRoot());
    cout << endl;

    cout << "Erase 3:";
    bst->erase(3);
    bst->print(bst->getRoot());
    cout << endl;

    cout << "Insert 3: ";
    bst->insert(3);
    bst->print(bst->getRoot());
    cout << endl;

    cout << "Insert 3: ";
    bst->insert(3);
    bst->print(bst->getRoot());
    cout << endl;

    cout << "Erase 3: ";
    bst->erase(bst->find(3));
    bst->print(bst->getRoot());
    cout << endl;

    return 0;
}