
#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

int N, K, Q;
vector<int> v[1001];

int c = 2;
int cnt = 0;
void dfs(int start, int end){
    
}
int main(){
    scanf("%d%d%d",&N, &K, &Q);
    for(int i=1; i<=N; i++){
        while(cnt != K){
            v[i].push_back(c);
            v[c].push_back(i);
            c++, cnt++;
        }
        cnt=0;
        
        
    }
    while(Q--){
        int start, end;
        scanf("%d%d",&start, &end);
        dfs(start, end);
    }
}
