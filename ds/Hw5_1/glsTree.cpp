#include <iostream>
#include <stack>

using namespace std;

template <class T>
struct BinNode{
    T data;
    BinNode<T> *lchild;
    BinNode<T> *rchild;

};

void printBinNode(BinNode<char> *root){
    if(root == NULL) cout << "NULL" << endl;
    else cout << root->data << endl << root->lchild << " " << root->rchild << endl;
}

void CreateBinTree(istream &in, BinNode<char>* &root){
    stack<BinNode<char>*> stk;
    stk.push(NULL);
    char ch;
    int flag = 2;
    BinNode<char>* p;
    while(in >> ch){
        if(ch == '#') break;
        if(ch >= 'A' && ch <= 'Z'){
            p = new BinNode<char>;
            p->data = ch;
            if(root == NULL){
                root = p;
            }
            else{
                if(flag == 1) stk.top()->lchild = p;
                else if(flag == 2) stk.top()->rchild = p;
            }
        }
        else if(ch == '('){
            stk.push(p);
            flag = 1;
        }
        else if(ch == ','){
            flag = 2;
        }
        else if(ch == ')'){
            stk.pop();
        }
    }
}

void printBinTree(BinNode<char> *root){

    if(root == NULL) return;
    cout << root->data;
    if(root->lchild != NULL || root->rchild != NULL){
        cout << "(";
        if(root->lchild) printBinTree(root->lchild);
        cout << ",";
        if(root->rchild) printBinTree(root->rchild);
        cout << ")";
    }
}

void deleteBinTree(BinNode<char> *root){
    if(root == NULL) return;
    deleteBinTree(root->lchild);
    deleteBinTree(root->rchild);
    delete root;
}

BinNode<char>* getLCA(BinNode<char>* root, char x, char y){
    if(root == NULL) return NULL;
    if(root->data == x || root->data == y) return root;
    BinNode<char>* l = getLCA(root->lchild, x, y);
    BinNode<char>* r = getLCA(root->rchild, x, y);
    if(l == NULL && r == NULL) return NULL;
    if(l == NULL) return r;
    if(r == NULL) return l;
    if(l != NULL && r != NULL) return root;
    return NULL;
}

int height(BinNode<char>* root, int &dist){
    if(root == NULL) return 0;
    int l = height(root->lchild, dist);
    int r = height(root->rchild, dist);
    if(dist < l + r){
        dist = l + r;
    }
    return l > r ? l + 1 : r + 1;
}

int maxDistance(BinNode<char>* root){
    int dist = -1;
    height(root, dist);
    return dist;
}

int main(){
    BinNode<char> *root = NULL;
    CreateBinTree(cin, root);
    cout << "The tree is: ";
    printBinTree(root);
    cout << endl;
    cout << "input two nodes that you want to find their LCA:";
    char a, b;
    cin >> a >> b;
    cout << (getLCA(root, a, b))->data << endl;
    cout << "The max distance is:"; 
    cout << maxDistance(root) << endl;
    deleteBinTree(root);
    return 0;
}