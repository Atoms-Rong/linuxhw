#include <iostream>
#include <cstdio>

using namespace std;

class BiThreadTree{
private:

    struct BiTreeNode{
        char data;
        struct BiTreeNode* lchild, * rchild;
        int ltag, rtag; 

        BiTreeNode(const char& ch):
            data(ch), lchild(NULL), rchild(NULL),
            ltag(0), rtag(0){}
    };

    
    BiTreeNode* root;

    void createBiThreadTree(BiTreeNode* &root){
        char ch;
        cin >> ch;
        if(ch == '#')
            root = NULL;
        else{
            root = new BiTreeNode(ch);
            createBiThreadTree(root->lchild);
            createBiThreadTree(root->rchild);
            
        }
    }

    void destroy(BiTreeNode* root){
        if(root != NULL){
            if(root->ltag == 0) destroy(root->lchild);
            else if (root->rtag == 0) destroy(root->rchild);
            delete root;
        }
    }
    
    void print(BiTreeNode* root){
        if(root == NULL) return;
        cout << root->data << endl;
        print(root->lchild);
        print(root->rchild);
    }

    void initPreOrder(BiTreeNode* current, BiTreeNode* &pre){
        if(current == NULL) return;
        if(current->lchild == NULL){
            current->lchild = pre;
            current->ltag = 1;
        }
        if(pre && pre->rchild == NULL){
            pre->rchild = current;
            pre->rtag = 1;
        }
        pre = current;
        if(current->ltag == 0)
            initPreOrder(current->lchild, pre);
        if(current->rtag == 0)
            initPreOrder(current->rchild, pre);
    }

public:

    void createBiThreadTree(){
        createBiThreadTree(root);
    }

    void initPreOrder(){
        BiTreeNode* pre = NULL;
        initPreOrder(root, pre);
    }

    void destroy(){
        destroy(root);
    }

    BiTreeNode* preOrderNext(BiTreeNode *node){
        if(node == NULL) return NULL;
        if(node->ltag == 0) return node->lchild;
        return node->rchild;
    }

    BiTreeNode*& getRoot(){
        return root;
    }
    
    void print(){
        print(root);
    }
};

int main(){
    BiThreadTree tree;
    tree.createBiThreadTree();
    tree.initPreOrder();
    cout << tree.preOrderNext(tree.getRoot())->data << endl;
    cout << tree.preOrderNext(tree.getRoot()->lchild)->data << endl;
    cout << tree.preOrderNext(tree.getRoot()->rchild)->data << endl;
    tree.destroy();

    return 0;
}