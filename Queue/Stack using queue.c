//Implementing Stack using Queue.

class MyStack {
public:
    queue<int> q;
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);                           //pushing element onto the stack 
        for(int i=0;i<q.size()-1;i++){
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {                             // Removing element on top of the stack and returning it
        int a = q.front();
        q.pop();
        return a;
    }
    
    int top() {                                 //Getting top element
        return q.front();
    }
    
    bool empty() {                              // Return whether the stack is empty. 
        return q.empty();
    }
};