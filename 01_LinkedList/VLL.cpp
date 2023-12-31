#include <iostream>
#include <vector>
using namespace std;

vector<int> v = vector<int>();

/* Class VectorLinkedList */
class VectorLinkedList
{
private:
    int cur;

public:
    VectorLinkedList();
    ~VectorLinkedList();
    int size();
    void display();
    void clear();
    void insert_front(int data);
    void insert_back(int data);
    void delete_front();
    void delete_back();
    void move_next();
    void move_prev();
};

VectorLinkedList::VectorLinkedList() { cur = 0; }
VectorLinkedList::~VectorLinkedList() { clear(); }
int VectorLinkedList::size() { return v.size(); }
void VectorLinkedList::display()
{
    for (int i : v)
        cout << i << " ";
    cout << endl;
}
void VectorLinkedList::clear() { v.clear(); }
void VectorLinkedList::insert_front(int data) { v.insert(v.begin(), data); }
void VectorLinkedList::insert_back(int data) { v.push_back(data); }
void VectorLinkedList::delete_front() { v.erase(v.begin()); }
void VectorLinkedList::delete_back() { v.pop_back(); }
void VectorLinkedList::move_next() { cur++; }
void VectorLinkedList::move_prev() { cur--; }

int main()
{
    VectorLinkedList *V = new VectorLinkedList();

    cout << "INSERT FRONT" << endl;
    V->insert_front(0);
    V->insert_front(-1);
    V->insert_front(-2);
    V->insert_front(-3);
    V->display();

    cout << "INSERT BACK" << endl;
    V->insert_back(1);
    V->insert_back(2);
    V->insert_back(3);
    V->display();

    cout << "DELETE FRONT" << endl;
    V->delete_front();
    V->display();

    cout << "DELETE BACK" << endl;
    V->delete_back();
    V->display();

    cout << "MOVE NEXT" << endl;
    V->move_next();
    V->display();

    cout << "MOVE PREV" << endl;
    V->move_prev();
    V->display();

    cout << "CLEAR" << endl;
    V->clear();
    V->display();
}