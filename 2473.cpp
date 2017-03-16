
#include <iostream>
#include <limits.h>
#include <algorithm>
using namespace std;

long long ABS(long long n){
    if(n < 0) return -n;
    return n;
}
int main(){
    int N,start=0,mid=0,end=0;
    long long sum, chemi[5003], tot=LONG_MAX;
    
    scanf("%d",&N);
    for(int i=0;i<N;i++)
        scanf("%lld",&chemi[i]);
    
    sort(chemi,chemi+N);
    
    for(int i=0;i<N;i++){
        int j = i+1;
        int k = N-1;
            while(1){
                if(j >= k) break;
                sum = chemi[j]+chemi[k]+chemi[i];
                
                if(ABS(sum) < tot){
                    tot = ABS(sum);
                    start = i;
                    mid = j;
                    end = k;
                }
                if(sum < 0) j++;
                else k--;
            }
        
    }
    printf("%lld %lld %lld\n",chemi[start], chemi[mid], chemi[end]);
    
}

