
#include <stdio.h>
#include <string.h>

int T, N;
int student[100001];
int isVisited[100001];
int cnt=0;

void dfs(int v){
    if (isVisited[v] == 2)
        return;
    else if (isVisited[v] != -1) {
        isVisited[v]++;
        dfs(student[v]);
    }
}
int main(){
    
    
    scanf("%d", &T);
    for(int testcase=1; testcase<=T; testcase++){
        scanf("%d", &N);
        
        for(int i=1; i<=N;i++)
            scanf("%d",&student[i]);
        
        memset(isVisited,0,sizeof(isVisited));
        
        for(int i=1; i<=N;i++){
            if (isVisited[i] != 2) {
                dfs(i);
                for (int j = 1; j <= N; j++) {
                    if (isVisited[j] == 1)
                        isVisited[j] = -1;
                }
            }
        }
        for(int i=1; i<=N;i++) if(isVisited[i] ==-1) ++cnt;
        
    }
    return 0;
}

