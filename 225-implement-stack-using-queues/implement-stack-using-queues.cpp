// class MyStack {
// public:
//     queue<int>q1,q2;
//     MyStack() {
        
//     }
//     void push(int x) {
//         while(!q1.empty()){
//             q2.push(q1.front());
//             q1.pop();
//         }
//         q1.push(x);
//         while(!q2.empty()){
//             q1.push(q2.front());
//             q2.pop();
//         }
//     }
    
//     int pop() {
//         int val = q1.front();
//         q1.pop();
//         return val;
//     }
    
//     int top() {
//         return q1.front();
//     }
    
//     bool empty() {
//         return q1.empty();
//     }
// };



class MyStack {
public:
    queue<int> q1, q2;

    MyStack() {}

    void push(int x) {
        // Push the new element onto q2
        q2.push(x);

        // Push all the elements of q1 to q2
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }

        // Swap the names of q1 and q2
        swap(q1, q2);
    }

    int pop() {
        int val = q1.front();
        q1.pop();
        return val;
    }

    int top() {
        return q1.front();
    }

    bool empty() {
        return q1.empty();
    }
};


/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */