#include <iostream>

using namespace std;

struct BitNode{
    char data;
    BitNode *lchild;
    BitNode *rchild;
};

BitNode* getLCA(BitNode* root, char x, char y){
    if(root == NULL) return NULL;
    if(root->data == x || root->data == y) return root;
    
}
int main(){

    return 0;
}