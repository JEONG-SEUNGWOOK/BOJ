

#include <stdio.h>
#include <algorithm>

using namespace std;

int main(){
    int N, time=0;
    int a[1001];
    scanf("%d", &N);
    for(int i=0; i<N; i++)
        scanf("%d",&a[i]);
    
    sort(a, a+N);
    
    for(int i=1; i<=N; i++)
        for(int j=0; j<i; j++)
            time += a[j];
    
    printf("%d", time);
    return 0;
}

