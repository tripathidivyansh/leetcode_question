class Solution {
public:
    struct Node {
        int data;
        int row;
        int col;

        Node(int val, int r, int c) : data(val), row(r), col(c) {}
    };
    struct compare {
        bool operator()(Node* a, Node* b) {
            return a->data > b->data;
        }
    };

    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k = nums.size();
        int mini = INT_MAX, maxi = INT_MIN;
        int start = 0, end = INT_MAX;

        priority_queue<Node*, vector<Node*>, compare> minHeap;

        for (int i = 0; i < k; i++) {
            int element = nums[i][0];
            maxi = max(maxi, element);
            minHeap.push(new Node(element, i, 0));
        }

        while (!minHeap.empty()) {
            Node* temp = minHeap.top();  
            minHeap.pop();
            mini = temp->data;

            if (maxi - mini < end - start) {
                start = mini;
                end = maxi;
            }
            if (temp->col + 1 < nums[temp->row].size()) {
                int nextVal = nums[temp->row][temp->col + 1];
                maxi = max(maxi, nextVal);
                minHeap.push(new Node(nextVal, temp->row, temp->col + 1));
            } else {
                break;
            }
        }
        return {start, end};
    }
};
