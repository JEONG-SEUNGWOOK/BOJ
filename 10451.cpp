

#include <stdio.h>
int T,N;
int perm[1005];
bool isVisited[1005];
int cnt=0;

void dfs(int v){
    if (isVisited[v]){
        cnt++;
        return;
    }
    else if (!isVisited[v]) {
        isVisited[v]=true;
        dfs(perm[v]);
    }
}

int main(){
    scanf("%d",&T);
    for(int testcase=1; testcase<=T; testcase++){
        cnt=0;
        
        for(int i=1;i<=N;i++){
            isVisited[i]=false;
            perm[i]=0;
        }
        
        scanf("%d",&N);
        
        for(int i=1; i<=N;i++)
            scanf("%d",&perm[i]);
        
        for(int i=1; i<=N;i++)
            if (!isVisited[i]){
                dfs(i);
            }
        printf("%d\n",cnt);
        
    }
}

