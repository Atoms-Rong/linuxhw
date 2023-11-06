#include <iostream>
#include <stack>
#include <cstdio>

using namespace std;

class BiTree{ 
private:
    struct BiTreeNode{
        int data;
        struct BiTreeNode* lchild, * rchild;
    };
    BiTreeNode* root;

    void createBiTree(BiTreeNode* &root){
        char ch;
        cin >> ch;
        if(ch == '#')
            root = NULL;
        else{
            root = new BiTreeNode;
            root->data = ch;
            createBiTree(root->lchild);
            createBiTree(root->rchild);
        }
    }

    void preOrder(BiTreeNode* root){
        stack<BiTreeNode*> s;
        BiTreeNode* p;
        s.push(root);
        while(!s.empty()){
            p = s.top();
            s.pop();
            putchar(p->data);
            if(p->rchild != NULL)
                s.push(p->rchild);
            if(p->lchild != NULL)
                s.push(p->lchild); 
        }
        cout << endl;
    }
    
public:

    BiTree(){
        root = NULL;
    }
    ~BiTree(){
        destroy(root);
    }

    void createBiTree(){
        createBiTree(root);
    }

    void preOrder(){
        preOrder(root);
    }

    void destroy(BiTreeNode* root){
        if(root != NULL){
            destroy(root->lchild);
            destroy(root->rchild);
            delete root;
        }
    }

};

int main(){

    BiTree tree;
    tree.createBiTree();
    tree.preOrder();

    return 0;
}
