#include <iostream>
#include <string>

template <class T>
struct node{
    int type;
    union data{
        int ref;
        T val;
        node* hlink;
    }info;
    struct node* tlink;

    node(){
        type = 0;
        info.ref = 0;
        tlink = NULL;
    }
    node(const node& n){
        type = n.type;
        info = n.info;
        tlink = n.tlink;
    }
};
template <class T>
bool Equal(node<T>* s, node<T>* t){
    if(s == NULL && t == NULL) return true;
    if(s == NULL || t == NULL) return false;
    if(s->type != t->type) return false;
    if(s->type == 0){
        if(s->info.ref != t->info.ref) return false;
    }
    else if(s->type == 1){
        if(s->info.val != t->info.val) return false;
    }
    else if(s->type == 2){
        if(!Equal(s->info.hlink, t->info.hlink)) return false;
    }
    return Equal(s->tlink, t->tlink);
}