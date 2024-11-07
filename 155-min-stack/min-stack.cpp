// class MinStack {
// public:
//     stack<int>s;
//     stack<int>minStack;
//     MinStack() {
//         minStack.push(INT_MAX);
//     }
    
//     void push(int val) {
//         s.push(val);
//         minStack.push(min(val, minStack.top()));
//     }
    
//     void pop() {
//         s.pop();
//         minStack.pop();
//     }
//     int top() {
//         return s.top();
//     }
    
//     int getMin() {
//         return minStack.top();
//     }
// };


class MinStack {
public:
    stack<int>st, s2;
    MinStack() {
        
    }
    
    void push(int val) {
       if(s2.empty() ||  val <= s2.top()){
        s2.push(val);
       }
       st.push(val);
    }
    
    void pop() {
       if(st.top()== s2.top()){
        s2.pop();
       }
       st.pop();
    }
    int top() {
        return st.top();
    }
    
    int getMin() {
      return s2.top();
    }
};










/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */