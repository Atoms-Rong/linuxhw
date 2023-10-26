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
void CreateBinTree(istream &in,BinNode<char>* &root){
    stack<BinNode<char>*> stk;
    stk.push(root);
    char ch;
    int flag = 1;
    while(in >> ch){
        if(ch == '#') break;
        BinNode<char>* &p = stk.top();
        if(ch >= 'A' && ch <= 'Z'){
            p = new BinNode<char>;
            p->data = ch;
            if(flag){
                root = p;
                flag = 0;
            }
        }
        else if(ch == '('){
            stk.push(p->lchild);
        }
        else if(ch == ','){
            stk.pop();
            stk.top()->lchild = p;
            stk.push(stk.top()->rchild);
        }
        else if(ch == ')'){
            stk.pop();
            stk.top()->rchild = p;
        }
    }
    return;
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
int depth(BinNode<char>* root){
    if(root == NULL) return 0;
    int l = depth(root->lchild);
    int r = depth(root->rchild);
    return max(l, r) + 1;
}

int maxDistance(BinNode<char>* root){
    return depth(root->lchild) + depth(root->rchild);
}

int main(){
    BinNode<char> *root = NULL;
    CreateBinTree(cin, root);
    cout << "The tree is: ";
    printBinTree(root);
    cout << endl;
    char a, b;
    cin >> a >> b;
    cout << (getLCA(root, a, b))->data << endl;
    cout << maxDistance(root) << endl;
    deleteBinTree(root);
    return 0;
}