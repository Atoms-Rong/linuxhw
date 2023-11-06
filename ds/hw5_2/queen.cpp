#include <iostream>

using namespace std;

const int N = 10;

int col[N], raw[N], diag1[N << 1], diag2[N << 1];
int queen[N][N];
int n;
int tot = 0;

void print(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)
            cout << queen[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}

void dfs(int i, int j, int cnt){
    if(cnt == n){
        ++tot;
        print();
        return;
    }
    if(!(raw[i] ||  col[j] || diag1[n+i-j-1] || diag2[i+j])){
        raw[i] = 1;
        col[j] = 1;
        diag1[n+i-j-1] = 1;
        diag2[i+j] = 1;
        queen[i][j] = 1;
        dfs(i, j, cnt+1);
        raw[i] = 0;
        col[j] = 0;
        diag1[n+i-j-1] = 0;
        diag2[i+j] = 0;
        queen[i][j] = 0;
    }
    if(j < n-1) dfs(i, j+1, cnt);
    else if(i < n-1 && j == n-1) dfs(i+1, 0, cnt);
}


int main(){
    cin >> n;
    dfs(0, 0, 0);
    cout << tot << endl;
    return 0;
}