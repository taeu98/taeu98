#include <iostream>
#include <vector>
using namespace std;

vector<int> v = vector<int>();

/* Class Stack */
class Stack
{
public:
    ~Stack();
    int size();
    void display();
    void clear();
    void push(int data);
    void pop();
};

Stack::~Stack() { clear(); }
int Stack::size() { return v.size(); }
void Stack::display()
{
    cout << "Stack : ";
    for (int i : v)
        cout << i << " ";
    cout << endl;
    cout << "Size : " << size() << endl;
}
void Stack::clear() { v.clear(); }
void Stack::push(int data) { v.push_back(data); }
void Stack::pop() { v.pop_back(); }

int main()
{
    Stack *S = new Stack();

    cout << "PUSH" << endl;
    S->push(1);
    S->push(2);
    S->push(3);
    S->display();

    cout << "POP" << endl;
    S->pop();
    S->display();

    cout << "CLEAR" << endl;
    S->clear();
    S->display();
}