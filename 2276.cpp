
#include <cstdio>
#include <algorithm>
using namespace std;
bool bs(int size,int a[],int m){
    int low=0, high=size-1, mid;
    while(low<=high){
        mid = low+(high-low)/2;
        if(a[mid]<m) low=mid+1;
        else if(a[mid]>m)high=mid-1;
        else return true;
    }
    return false;
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int N,M;
        int a[1000001];
        scanf("%d",&N);
        for(int i=0;i<N;i++) scanf("%d",&a[i]);
        sort(a,a+N);
        scanf("%d",&M);
        while(M--){
            int t;
            scanf("%d",&t);
            printf("%d\n",bs(N,a,t));
        }
    }
}
