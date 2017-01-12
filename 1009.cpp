#include <stdio.h>
#include <cmath>
using namespace std;
int main(){
    int T;
    scanf("%d",&T);
    for(int testcase=1; testcase<=T; testcase++){
        long a,b;
        int data=1;
        scanf("%ld %ld",&a, &b);
        for(int i=1; i<=b; i++){
            data *= a;
            data %= 10;
        }
        printf("%d\n",data==0?10 :data);
    }
    return 0;
}
