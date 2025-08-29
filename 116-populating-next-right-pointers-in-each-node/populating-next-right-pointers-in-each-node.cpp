/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/
class Solution {
public:
    void Solve(Node* leftNode, Node* rightNode){
        if(!leftNode || !rightNode) return;
        leftNode->next = rightNode;
        Solve(leftNode->left, leftNode->right);
        Solve(rightNode->left, rightNode->right);
        Solve(leftNode->right, rightNode->left);
    }
    Node* connect(Node* root) {
        // if(!root) return NULL;
        // queue<Node*>q;
        // q.push(root);
        // while(!q.empty()){
        //     int Size = q.size();
        //     Node* prev = nullptr;
        //     for(int i = 0; i<Size; i++){
        //         Node* front = q.front();
        //         q.pop();
        //         if(prev){
        //             prev->next = front;
        //         }
        //         prev = front;
        //         if(front->left)q.push(front->left);
        //         if(front->right) q.push(front->right);
        //     }
        // }
        // return root;
        if(!root) return NULL;
        Solve(root->left, root->right);
        return root;
    }
};
















































