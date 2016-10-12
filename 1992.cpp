
#include <stdio.h>
#include <iostream>

int student[100002];
int isVisit[100002];

void dfs(int n){
    
    
    if(isVisit[n] != -1 || isVisit[n]!=2){
        isVisit[student[n]]++;
        dfs(student[n]);
    }
    
}
int main() {
    
    int T, N=0;
    scanf("%d", &T);
    for(int testcase=0; testcase<T; testcase++){
        
        scanf("%d",&N);
        for(int i=1; i<=N; i++){
            scanf("%d",&student[i]);
            isVisit[i] =0;
        }
        
        for(int i=1; i<=N; i++){
            if(isVisit[i]!=-1 || isVisit[i]!=2){
                isVisit[i]=1;
                dfs(i);
            }
            for(int j=1; j<=N; j++) {
                if(isVisit[j]==1) isVisit[j]=-1;
            }
        }
        for(int i=1; i<=N; i++) printf("%d\n", isVisit[i]);
    }
    return 0;
}
