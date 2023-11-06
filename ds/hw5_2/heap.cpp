#include <iostream>
#include <algorithm>
#include <vector>

using std::cout;
using std::cin;
using std::swap;
using std::endl;
using std::vector;

const int defaultSize = 100;

template <class T>
class MaxHeap{
private:
    
    T *heap;
    int size;

    bool check(int root){
        int ls = root << 1;
        int rs = ls + 1;
        if(ls > size) return true;
        if(rs > size){
            if(heap[root] > heap[ls]){
                return true;
            }
            else return false;
        }
        if(heap[root] > heap[ls] && heap[root] > heap[rs]){
            return check(ls) && check(rs);
        }
        else return false;
    }

public:

    MaxHeap(){
        heap = new T[defaultSize];
        size = 0;
    } 

    ~MaxHeap(){
        delete []heap;
    }

    void input(int n){
        size = n;
        for(int i = 1; i <= n; ++i){
            cin >> heap[i];
        }
    }

    void pushDown(int root){
        int current = root;
        T temp = heap[root];
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
            else break;
        }
        
    }

    void pushUp(int i){
        T temp = heap[i];
        while(i > 1 && temp > heap[i >> 1]){
            heap[i] = heap[i >> 1];
            i >>= 1;
        }  
        heap[i] = temp;
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

    bool check(){
        return check(1);
    }

    void init(){
        for(int i = size; i >= 1; --i){
            pushDown(i);
        }
    }

    void print(){
        for(int i = 1; i <= size; ++i){
            cout << heap[i] << " ";
        }
        cout << endl;
    }

    void printMin(){
        for(int i = 1; i <= size; ++i){
            cout << -heap[i] << " ";
        }
        cout << endl;
    }

    void changeToMin(){
        for(int i = 1;i <= size; ++i){
            heap[i] = -heap[i];
        }
    }

    void input(vector<T> vec){
        size = vec.size();
        for(int i = 1; i <= size; ++i){
            heap[i] = vec[i-1];
        }
    }
};

int main(){
    MaxHeap<int> heap;
    vector<vector<int> > vec = 
        {
            {100,86,48,73,35,39,42,57,66,21},
            {12,70,33,65,24,56,48,92,86,33},
            {103,97,56,38,66,23,42,12,30,35,6,20},
            {5,56,20,23,40,38,29,61,35,76,28,100}
        };
    for(int i = 0; i < vec.size(); ++i){
        heap.input(vec[i]);  
        
        cout << "MaxHeap?" << endl;
        if(heap.check()){
            cout << "yes" << endl;
        }
        else{
            cout << "no" << endl;
            heap.init();
            if(heap.check()){
                cout << "initialized" << endl;
            }
            else{
                cout << "fail" << endl;
            }
            heap.print();
        }
        heap.input(vec[i]);  
        heap.changeToMin();
        cout << "MinHeap?" << endl;
        if(heap.check()){
            cout << "yes" << endl;
        }
        else{
            cout << "no" << endl;
            heap.init();
            if(heap.check()){
                cout << "initialized" << endl;
            }
            else{
                cout << "fail" << endl;
            }
            heap.printMin();
        }
    }
    return 0;
}