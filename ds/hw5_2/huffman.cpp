#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int defaultSize = 20;

template <class T>
class MaxHeap{
private:
    
    T *heap;
    int size;

public:

    MaxHeap(){
        heap = new T[defaultSize];
        size = 0;
    } 

    ~MaxHeap(){
        delete []heap;
    }

    void pushDown(int root){
        int current = root;
        while(1){
            int ls = current << 1;
            int rs = ls + 1;
            if(ls > size) return;
            if(ls == size){
                if(heap[current] < heap[ls])
                    swap(heap[current], heap[ls]);
                return;
            }
            int maxs = heap[ls] > heap[rs] ? ls : rs;
            if(heap[current] < heap[maxs]){
                swap(heap[current], heap[maxs]);
                current = maxs;
            }
        }
        
    }

    void pushUp(int i){
        while(i > 1 && heap[i] > heap[i >> 1]){
            swap(heap[i], heap[i >> 1]);
            i >>= 1;
        }  
    }

    void push(T& x){
        heap[++size] = x;
        pushUp(size);
    }

    T& top(){
        return heap[1];
    }

    void pop(){
        heap[1] = heap[size--];
        pushDown(1);
    }
    
    int Size(){
        return size;
    }

};

template<class T>
class HuffmanTree{

private:
    struct HuffmanNode{
        T data;
        int weight;
        HuffmanNode *parent, *lchild, *rchild;

        HuffmanNode():
            data(0), weight(0), parent(NULL), lchild(NULL), rchild(NULL){}
        
        HuffmanNode(const T& d, const int& w):
            data(d), weight(w), parent(NULL), lchild(NULL), rchild(NULL){}
        
        bool operator < (const HuffmanNode& rhs) const{
            return weight > rhs.weight;
        }

        bool operator > (const HuffmanNode& rhs) const{
            return weight < rhs.weight;
        }

        HuffmanNode(const HuffmanNode& x){
            data = x.data;
            weight = x.weight;
            parent = x.parent;
            lchild = x.lchild;
            rchild = x.rchild;
        }
    };

    HuffmanNode* root;

    void destroy(HuffmanNode* root){
        if(root != NULL){
            destroy(root->lchild);
            destroy(root->rchild);
            delete root;
        }
    }

    void create(HuffmanNode* &root){
        int n;
        cin >> n;
        HuffmanNode *parent, *first, *second;
        HuffmanNode *nodeptr;
        MaxHeap<HuffmanNode> heap;
        for(int i = 0; i < n; ++i){
            T d;
            int w;
            cin >> d >> w;
            nodeptr = new HuffmanNode(d,w);
            heap.push(*nodeptr);
        }
        for(int i = 0; i < n-1; ++i){
            first = new HuffmanNode(heap.top());
            // first = &heap.top();
            heap.pop();
            second = new HuffmanNode(heap.top()); 
            // second = &heap.top();
            heap.pop();
            cout << first->weight << " " << second->weight << endl;
            parent = new HuffmanNode;
            parent->weight = first->weight + second->weight;
            parent->lchild = first;
            parent->rchild = second;
            first->parent = parent;
            second->parent = parent;
            heap.push(*parent);
        }
        root = &heap.top();
        heap.pop();
        return;
    }

    void print(HuffmanNode* current, string &path){
        if(current == NULL) return;
        if(current->lchild == NULL && current->rchild == NULL){
            cout << current->data << " " << current->weight << " " << path << endl;
        }
        if(current->lchild != NULL){
            path.push_back('0');
            print(current->lchild, path);
            path.pop_back();
        }
        if(current->rchild != NULL){
            path.push_back('1');
            print(current->rchild, path);
            path.pop_back();
        }
    }

    void printTree(HuffmanNode* root){
        if(root == NULL) return;
        if(root->data != NULL)
            cout << root->data << " " << root->weight << endl;
        printTree(root->lchild);
        printTree(root->rchild);
    }

public:

    HuffmanTree():root(NULL){}
    ~HuffmanTree(){
        destroy(root);
    }

    void create(){
        create(root);
    }

    void print(){
        string path;
        print(root, path);
    }

    void printTree(){
        printTree(root);
    }

};

int main(){

    HuffmanTree<char> tree;
    tree.create();
    tree.print(); 
    // tree.printTree();

    return 0;
}