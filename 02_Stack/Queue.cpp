#include <iostream>
#include <vector>
using namespace std;

vector<int> v = vector<int>();

/* Class Queue */
class Queue
{
public:
    ~Queue();
    int size();
    void display();
    void clear();
    void enqueue(int data);
    void dequeue();
};

Queue::~Queue() { clear(); }
int Queue::size() { return v.size(); }
void Queue::display()
{
    for (int i : v)
        cout << i << " ";
    cout << endl;
}
void Queue::clear() { v.clear(); }
void Queue::enqueue(int data) { v.insert(v.begin(), data); }
void Queue::dequeue() { v.pop_back(); }

int main()
{
    Queue *V = new Queue();

    cout << "INSERT FRONT" << endl;
    V->enqueue(0);
    V->enqueue(-1);
    V->enqueue(-2);
    V->enqueue(-3);
    V->display();

    cout << "DELETE BACK" << endl;
    V->dequeue();
    V->display();

    cout << "CLEAR" << endl;
    V->clear();
    V->display();
}