#include <iostream>

using namespace std;

template <class T>
class Glist{
private:
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
    }

    struct node* first;
    struct node* Copy(node* ls){
        struct node* q;
        if(ls == NULL) return NULL;
        q = new node;
        q->type = ls->type;
        if(q->type == 0){
            q->info.ref = ls->info.ref;
        }
        else if(q->type == 1){
            q->info = ls->info;
        }
        else if(q->type == 2){
            q->info.hlink = Copy(ls->info.hlink);
        }
        q->tlink = Copy(ls->tlink);
        return q;
    }
    void Del(node* ls){
        if(ls == NULL) return;
        if(ls->type == 2){
            Del(ls->info.hlink);
        }
        Del(ls->tlink);
        delete ls;
    }
    void Delval(node *ls, const T &v){
        if(ls == NULL) return;
        struct node *p = ls->tlink, *q = ls;
        while(p != NULL){
            if(p->type == 1 && p->info.val == v){
                q->tlink = p->tlink;
                delete p;
                p = q->tlinl;
            }
        }
        if(p != NULL){
            if(p->type == 2){
                Delval(p->info.hlink, v);
            }
            Delval(p, v);
        }
    }
    bool Equal(node *s, node* t){
        if(s == NULL && t == NULL) return true;
        if(s == NULL || t == NULL) return false;
        if(s->type != t->type) return false;
        if(s->type == 0){
            if(s->info.ref != t->info.ref) return false;
            if(s->info.ref > 0){
                --s->info.ref;
                --t->info.ref;
                return Equal(s->tlink, t->tlink);
                ++s->info.ref;
                ++t->info.ref;
            }
            else{
                node *ps, *pt;
                while(s->tlink != NULL && t->tlink != NULL){
                    ps = s->tlink;
                    pt = t->tlink;
                    return Equal(ps,pt);
                }
            }
        }
        else if(s->type == 1){
            if(s->info.val != t->info.val) return false;
        }
        else if(s->type == 2){
            if(!Equal(s->info.hlink, t->info.hlink)) return false;
        }
        return Equal(s->tlink, t->tlink);
    }
public:
    Glist(){
        first = new node;
    }
    Glist(const Glist& g){
        first = g.first;
    }
    ~Glist(){
        Del(first);
    }
    node* copy(node* ls){
        return Copy(ls);
    }
    void del(node* ls){
        Del(ls);
    }
    void delval(node* ls, T v){
        Delval(ls, v);
    }
    
};



int main(){

    return 0;
}