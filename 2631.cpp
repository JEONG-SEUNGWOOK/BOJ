
#include <stdio.h>
#include <algorithm>
using namespace std;
int N;
int boy[205];
int dy[205]={0,};
int cnt = 0;
int main(){
    scanf("%d",&N);
    for(int i=0;i<N;i++) scanf("%d",&boy[i]);
    
    for(int i=0 ;i<N;i++){
        dy[i]=1;
        for(int j=0; j<i; j++){
            if(boy[i] > boy[j] && dy[i] < dy[j]+1)
                dy[i]=dy[j]+1;
        }
    }
    
    for(int i=0; i<N;i++){
        printf("%d ",dy[i]);
        cnt = max(cnt, dy[i]);
    }
    printf("%d",N-cnt);
}
