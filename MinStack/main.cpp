#include <iostream>
#include <stack>
#include <climits>
using namespace std;

class MinStack {
private:
    stack<int> s;
    stack<int> minStack;
public:
    void push(int x) {
        s.push(x);
        if(minStack.empty() || x <= minStack.top()){
            minStack.push(x);
        }
    }

    void pop() {
        int x = s.top();
        s.pop();
        if(!minStack.empty() && x == minStack.top()){
            minStack.pop();
        }
    }

    int top() {
        return s.top();
    }

    int getMin() {
        if(minStack.empty()){
            return 0;
        }
        return minStack.top();
    }
};

int main()
{
    MinStack ms;
    ms.push(7);
    ms.push(6);
    ms.push(5);
    ms.push(1);
    ms.push(2);
    ms.push(1);
    cout<<ms.getMin()<<endl;
    ms.pop();
    cout<<ms.getMin()<<endl;
    ms.pop();
    ms.pop();
    cout<<ms.getMin()<<endl;
    return 0;
}
