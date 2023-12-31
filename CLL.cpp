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
    friend class CircularLinkedList;
};
node::node(int data)
{
    this->data = data;
    this->next = NULL;
    this->prev = NULL;
}

/* Class CircularLinkedList */
class CircularLinkedList
{
private:
    node *cur = new node(0);

public:
    CircularLinkedList();
    ~CircularLinkedList();
    int size();
    void display();
    void clear();
    void insert_next(int data);
    void insert_prev(int data);
    void delete_next();
    void delete_prev();
    void move_next();
    void move_prev();
};

CircularLinkedList::CircularLinkedList()
{
    cur->next = cur;
    cur->prev = cur;
}
CircularLinkedList::~CircularLinkedList()
{
    clear();
    delete cur;
}
int CircularLinkedList::size()
{
    return cur->data;
}
void CircularLinkedList::display()
{
    cout << "List: ";
    node *temp = cur->next;
    while (temp != cur)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
    cout << "size: " << size() << endl;
}
void CircularLinkedList::clear()
{
    while (size())
        delete_next();
}
void CircularLinkedList::insert_next(int data)
{
    cur->data++;
    node *temp = new node(data);
    temp->next = cur->next;
    temp->prev = cur;
    cur->next->prev = temp;
    cur->next = temp;
}
void CircularLinkedList::insert_prev(int data)
{
    cur->data++;
    node *temp = new node(data);
    temp->next = cur;
    temp->prev = cur->prev;
    cur->prev->next = temp;
    cur->prev = temp;
}
void CircularLinkedList::delete_next()
{
    cur->data--;
    node *temp = cur->next;
    cur->next = temp->next;
    cur->next->prev = cur;
    delete temp;
}
void CircularLinkedList::delete_prev()
{
    cur->data--;
    node *temp = cur->prev;
    cur->prev = temp->prev;
    cur->prev->next = cur;
    delete temp;
}
void CircularLinkedList::move_next()
{
    swap(cur->data, cur->next->data);
    cur = cur->next;
}
void CircularLinkedList::move_prev()
{
    swap(cur->data, cur->prev->data);
    cur = cur->prev;
}

int main()
{
    CircularLinkedList *C = new CircularLinkedList();

    cout << "INSERT FRONT" << endl;
    C->insert_next(0);
    C->insert_next(-1);
    C->insert_next(-2);
    C->insert_next(-3);
    C->display();

    cout << "INSERT BACK" << endl;
    C->insert_prev(1);
    C->insert_prev(2);
    C->insert_prev(3);
    C->display();

    cout << "DELETE FRONT" << endl;
    C->delete_next();
    C->display();

    cout << "DELETE BACK" << endl;
    C->delete_prev();
    C->display();

    cout << "MOVE NEXT" << endl;
    C->move_next();
    C->display();

    cout << "MOVE PREV" << endl;
    C->move_prev();
    C->display();

    cout << "CLEAR" << endl;
    C->clear();
    C->display();
}