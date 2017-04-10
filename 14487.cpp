
#include <cstdio>
#include <algorithm>

int main(){
    int N,A[50002],ans=0;
    scanf("%d",&N);
    for(int i=0;i<N;i++)
        scanf("%d",&A[i]);
    std::sort(A,A+N);
    for(int i=0;i<N-1;i++)
        ans+=A[i];
    
    printf("%d\n",ans);
}
