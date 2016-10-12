
#include <stdio.h>
#include <algorithm>
using namespace std;

int N;
int main(){
    scanf("%d",&N);
    
    int a, b, c;
    int temp_a, temp_b, temp_c;
    scanf("%d %d %d",&a, &b, &c);
    for(int i=0;i<N-1;i++){
        scanf("%d %d %d",&temp_a, &temp_b, &temp_c);
        temp_a += min(b, c);
        temp_b += min(c, a);
        temp_c += min(a, b);
        
        a=temp_a;
        b=temp_b;
        c=temp_c;
    }
    printf("%d",min(min(a,b),c));
    
    return 0;
}
