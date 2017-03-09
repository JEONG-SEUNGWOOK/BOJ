

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, B[51];
vector<pair<int, int>> v;

int main(){
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        int a;
        scanf("%d",&a);
        v.push_back(make_pair(a, i));
    }
    sort(v.begin(), v.end());
    for(int i=0;i<N;i++)
        B[v[i].second] = i;
    
    for(int i=0;i<N;i++)
        printf("%d ",B[i]);
    
}
