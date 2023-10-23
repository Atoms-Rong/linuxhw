/*

bool Equal(node* s, node* t){
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
            node* ps, * pt;
            while(s->tlink != NULL && t->tlink != NULL){
                ps = s->tlink;
                pt = t->tlink;
                return Equal(ps, pt);
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
*/