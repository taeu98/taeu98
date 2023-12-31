#include <iostream>
using namespace std;

/* Class Node */
class node
{
private:
    int data;
    node *next;
    node *prev;

public:
    node(int data);
    friend class DoublyLinkedList;
};
node::node(int data)
{
    this->data = data;
    this->next = NULL;
    this->prev = NULL;
}

/* Class DoublyLinkedList */
class DoublyLinkedList
{
private:
    node *null = new node(0);

public:
    DoublyLinkedList();
    ~DoublyLinkedList();
    int size();
    void display();
    void clear();
    void insert_front(int data);
    void insert_back(int data);
    void delete_front();
    void delete_back();
};

DoublyLinkedList::DoublyLinkedList()
{
    null->next = null;
    null->prev = null;
}
DoublyLinkedList::~DoublyLinkedList()
{
    clear();
    delete null;
}
int DoublyLinkedList::size()
{
    return null->data;
}
void DoublyLinkedList::display()
{
    cout << "List: ";
    node *temp = null->next;
    while (temp != null)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
    cout << "size: " << size() << endl;
}
void DoublyLinkedList::clear()
{
    while (size())
        delete_front();
}
void DoublyLinkedList::insert_front(int data)
{
    null->data++;
    node *temp = new node(data);
    temp->next = null->next;
    temp->prev = null;
    null->next->prev = temp;
    null->next = temp;
}
void DoublyLinkedList::insert_back(int data)
{
    null->data++;
    node *temp = new node(data);
    temp->next = null;
    temp->prev = null->prev;
    null->prev->next = temp;
    null->prev = temp;
}
void DoublyLinkedList::delete_front()
{
    null->data--;
    node *temp = null->next;
    null->next = temp->next;
    null->next->prev = null;
    delete temp;
}
void DoublyLinkedList::delete_back()
{
    null->data--;
    node *temp = null->prev;
    null->prev = temp->prev;
    null->prev->next = null;
    delete temp;
}

int main()
{
    DoublyLinkedList *D = new DoublyLinkedList();

    cout << "INSERT FRONT" << endl;
    D->insert_front(0);
    D->insert_front(-1);
    D->insert_front(-2);
    D->insert_front(-3);
    D->display();

    cout << "INSERT BACK" << endl;
    D->insert_back(1);
    D->insert_back(2);
    D->insert_back(3);
    D->display();

    cout << "DELETE FRONT" << endl;
    D->delete_front();
    D->display();

    cout << "DELETE BACK" << endl;
    D->delete_back();
    D->display();

    cout << "CLEAR" << endl;
    D->clear();
    D->display();
}