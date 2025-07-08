class CustomStack {
public:
    stack<int> S;
    int maxSize;

    CustomStack(int maxSize) {
        this->maxSize = maxSize;
    }

    void push(int x) {
        if (S.size() < maxSize) {
            S.push(x);
        }
    }

    int pop() {
        if (S.empty()) return -1;
        int top = S.top();
        S.pop();
        return top;
    }

    void increment(int k, int val) {
        vector<int> temp;
        int size = S.size();
        
        for (int i = 0; i < size; i++) {
            temp.push_back(S.top());
            S.pop();
        }

        for (int i = size - 1; i >= 0; i--) {
            if (size - 1 - i < k) {
                temp[i] += val;
            }
        }

        for (int i = size - 1; i >= 0; i--) {
            S.push(temp[i]);
        }
    }
}; 
