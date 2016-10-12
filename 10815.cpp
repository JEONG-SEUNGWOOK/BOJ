
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int N,M,T,a;
    vector<int> v,target;
    cin>>N;
    while(N--){
        cin>>a;
        v.push_back(a);
    }
    cin>>M;
    T=M;
    while(M--){
        cin>>a;
        target.push_back(a);
    }
    
    sort(v.begin(), v.end());
    for(auto l:target){
        if(--T !=0) cout<< binary_search(v.begin(), v.end(), l)<<" ";
        else cout<< binary_search(v.begin(), v.end(), l);
    }
}

