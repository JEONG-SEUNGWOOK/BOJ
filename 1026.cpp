#include <cstdio>
#include <algorithm>
#include<functional>

using namespace std;

int main(){
    int N;
    int a[51];
    int b[51];
    int answer = 0;
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        scanf("%d",&a[i]);
    }
    for(int i=0;i<N;i++){
        scanf("%d",&b[i]);
    }
    sort(a, a+N);
    sort(b, b+N,greater<int>());
    
    for(int i=0;i<N;i++){
        answer += a[i]*b[i];
    }
    printf("%d",answer);
    return 0;
}
