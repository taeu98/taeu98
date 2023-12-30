#include <iostream>
using namespace std;

/* Class Node */
class node
{
private:
    int data;
    node *next;

public:
    node(int data);
    friend class SinglyLinkedList;
};
node::node(int data)
{
    this->data = data;
    this->next = NULL;
}

/* Class SinglyLinkedList */
class SinglyLinkedList
{
private:
    node *null = new node(0);

public:
    SinglyLinkedList();
    ~SinglyLinkedList();
    int size();
    void display();
    void clear();
    void insert_front(int data);
    void insert_back(int data);
    void delete_front();
    void delete_back();
};
SinglyLinkedList::SinglyLinkedList()
{
    null->next = null;
}
SinglyLinkedList::~SinglyLinkedList()
{
    clear();
    delete null;
}
int SinglyLinkedList::size()
{
    return null->data;
}
void SinglyLinkedList::display()
{
    cout << "List: ";
    node *temp = null->next;
    while (temp != null)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
    cout << "Size: " << size() << endl;
}
void SinglyLinkedList::clear()
{
    while (size())
        delete_front();
}
void SinglyLinkedList::insert_front(int data)
{
    null->data++;
    node *new_node = new node(data);
    new_node->next = null->next;
    null->next = new_node;
}
void SinglyLinkedList::insert_back(int data)
{
    null->data++;
    node *new_node = new node(data);
    node *temp = null->next;
    while (temp->next != null)
    {
        temp = temp->next;
    }
    temp->next = new_node;
    new_node->next = null;
}
void SinglyLinkedList::delete_front()
{
    null->data--;
    node *temp = null->next;
    null->next = temp->next;
    delete temp;
}
void SinglyLinkedList::delete_back()
{
    null->data--;
    node *temp = null->next;
    while (temp->next->next != null)
    {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = null;
}

int main()
{
    SinglyLinkedList *S = new SinglyLinkedList();

    cout << "INSERT FRONT" << endl;
    S->insert_front(0);
    S->insert_front(1);
    S->insert_front(2);
    S->insert_front(3);
    S->display();

    cout << "INSERT BACK" << endl;
    S->insert_back(-1);
    S->insert_back(-2);
    S->insert_back(-3);
    S->display();

    cout << "DELETE FRONT" << endl;
    S->delete_front();
    S->display();

    cout << "DELETE BACK" << endl;
    S->delete_back();
    S->display();

    cout << "CLEAR" << endl;
    S->clear();
    S->display();
}