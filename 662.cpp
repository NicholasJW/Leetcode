#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

    int widthOfBinaryTree(TreeNode* root) {
        queue<TreeNode*> q;

        q.push(root);
        int level=0;
        int width=0;
        stack<TreeNode*> st;
        while(!q.empty()){
            while(st.size()!=0)
                st.pop();
            level++;
            // cout << level << endl;
            int numInQue = (int) q.size();
            // cout << numInQue << endl;
            for(int i=0; i<numInQue; i++){
                if(st.empty()&&q.front()==NULL){
                    q.pop();
                    continue;
                }
                st.push(q.front());
                if(q.front()==NULL){
                    q.push(NULL);
                    q.push(NULL);
                }else{
                    q.push(q.front()->left);
                    q.push(q.front()->right);
                }
                q.pop();
                // cout << "check\n";
            }
            // cout << st.size() << endl;
            while(st.size()!=0){
                if(st.top()==NULL)
                    st.pop();
                else
                    break;
            }
            // cout << "Stack size: " << st.size() << endl;
            if(st.size()==0)
                break;
            width = max(width, (int)st.size());
            // cout << width << endl;
        }

        return width;
    }

int main(){
    cout << "Approach using too much space. Smarter approach see 662bf.cpp" << endl;
}