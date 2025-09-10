class MyQueue {
public:
    stack<int>q1, q2;
    MyQueue() {

    }
    void push(int x) {
        while(!q2.empty()){
            q1.push(q2.top());
            q2.pop();
        }
        q2.push(x);
        while(!q1.empty()){
            q2.push(q1.top());
            q1.pop();
        }
    }
    int pop() {
        int val = q2.top();
        q2.pop();
        return val;
    }
    
    int peek() {
        return q2.top();
    }
    
    bool empty() {
        return q2.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */