
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int N,M;
    vector<int> v;
    scanf("%d%d",&N,&M);
    for(int i=0;i<N+M;i++){
        int n;
        scanf("%d",&n);
        v.push_back(n);
    }
    sort(v.begin(), v.end());
    for(int i=0;i<v.size();i++){
        if(i == v.size()-1) printf("%d\n",v[i]);
        else printf("%d ",v[i]);
    }
}
