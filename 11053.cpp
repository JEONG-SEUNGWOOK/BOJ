

#include <stdio.h>
#include <algorithm>
using namespace std;

int N;
int prog[1001];
int dy[1001];
int longest = 0;
int main(){
    scanf("%d",&N);
    for(int i=1; i<=N;i++) scanf("%d",&prog[i]);
    
    for(int i=1;i<=N;i++){
        dy[1]=1;
        for(int j=0;j<i;j++){
            if(prog[j]<prog[i] && dy[i] < dy[j]+1){
                dy[i] = dy[j]+1;
            }
                
        }
        longest = max(dy[i], longest);
    }
    
    printf("%d",longest);
    
}