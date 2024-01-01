#include <iostream>
#include <vector>
using namespace std;

/* Class Queue */
class Queue
{
private:
    vector<int> v = vector<int>();

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
    cout << "Queue : ";
    for (int i : v)
        cout << i << " ";
    cout << endl;
    cout << "Size : " << size() << endl;
}
void Queue::clear() { v.clear(); }
void Queue::enqueue(int data) { v.insert(v.begin(), data); }
void Queue::dequeue() { v.pop_back(); }

int main()
{
    Queue *Q = new Queue();

    cout << "Enqueue" << endl;
    Q->enqueue(0);
    Q->enqueue(-1);
    Q->enqueue(-2);
    Q->enqueue(-3);
    Q->display();

    cout << "Dequeue" << endl;
    Q->dequeue();
    Q->display();

    cout << "CLEAR" << endl;
    Q->clear();
    Q->display();
}