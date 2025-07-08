class CustomStack {
public:
    vector<int> S;
    int maxSize;

    CustomStack(int maxSize) {
        this->maxSize = maxSize;
    }

    void push(int x) {
        if (S.size() < maxSize) {
            S.push_back(x);
        }
    }

    int pop() {
        if (S.empty()) return -1;
        int top = S.back();
        S.pop_back();
        return top;
    }

    void increment(int k, int val) {
        for(int i = 0; i<min(k, (int)S.size()); i++){
            S[i] += val;
        }
    }
}; 
