#include <iostream>
#include <queue>
using namespace std;

class Stack {
private:
	queue<int> q;
public:
    // Push element x onto stack.
    void push(int x) {
        q.push(x);
    }

    // Removes the element on top of the stack.
    void pop() {
    	queue<int> p;
    	while(q.size() != 1){
        	int x = q.front();
        	p.push(x);
        	q.pop();
    	}
    	q = p;
    }

    // Get the top element.
    int top() {
        queue<int> p;
    	while(q.size() != 1){
        	int x = q.front();
        	p.push(x);
        	q.pop();
    	}
    	int result = q.front();
    	p.push(result);
    	q = p;
    	return result;
    }

    // Return whether the stack is empty.
    bool empty() {
        return q.empty();
    }
};

int main(){
	Stack s;
	cout<<s.empty()<<endl;
	s.push(1);
	cout<<s.empty()<<endl;
	cout<<s.top()<<endl;
	s.pop();
	cout<<s.empty()<<endl;
	return 0;
}