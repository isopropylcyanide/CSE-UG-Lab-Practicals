#include <iostream>
#include <cstddef>
#include <queue>
#include <string>
#include <cstdlib>
#include <bits/stdc++.h>

using namespace std;
class Node{
    public:
        int data;
        Node *left,*right;
        Node(int d){
            data=d;
            left=right=NULL;
        }
};
class Solution{
    queue<Node *> level;

    public:
  		Node* insert(Node* root, int data){
            if(root==NULL){
                return new Node(data);
            }
            else{
                Node* cur;
                if(data<=root->data){
                    cur=insert(root->left,data);
                    root->left=cur;
                }
                else{
                   cur=insert(root->right,data);
                   root->right=cur;
                 }
           return root;
           }
        }

        void levelOrder(Node * root){
            if (root == NULL)
                return;

            level.push(root);
            while (!level.empty()){
                Node * pop = level.front();
                cout << pop-> data <<" ";

                level.pop();
                if (pop -> left)
                level.push(pop -> left);
                if (pop -> right)
                level.push(pop -> right);
            }
        }
};


int main(){
    Solution myTree;
    Node* root=NULL;
    int T,data;
    cin>>T;
    while(T-->0){
        cin>>data;
        root= myTree.insert(root,data);
    }
    myTree.levelOrder(root);
    return 0;
}










//
