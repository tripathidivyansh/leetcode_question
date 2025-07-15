class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        unordered_map<int, vector<int>> adj;
        unordered_map<int, int> child_to_parent;

        for (int i = 0; i < n; i++) {
            int leftC = leftChild[i];
            int rightC = rightChild[i];

            if (leftC != -1) {
                adj[i].push_back(leftC);
                if (child_to_parent.find(leftC) != child_to_parent.end())
                    return false;  
                child_to_parent[leftC] = i;
            }

            if (rightC != -1) {
                adj[i].push_back(rightC);
                if (child_to_parent.find(rightC) != child_to_parent.end())
                    return false;
                child_to_parent[rightC] = i;
            }
        }

        
        int root = -1;
        for (int i = 0; i < n; i++) {
            if (child_to_parent.find(i) == child_to_parent.end()) {
                if (root != -1) return false; 
                root = i;
            }
        }

        if (root == -1) return false;  

        vector<bool> visited(n, false);
        queue<int> q;
        q.push(root);
        visited[root] = true;
        int count = 1;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int &v : adj[node]) {
                if (visited[v]) return false;  
                visited[v] = true;
                count++;
                q.push(v);
            }
        }
        return count == n;

    }
};