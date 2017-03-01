
#include <cstdio>
#include <vector>
using namespace std;

int N, ans=0;
vector<pair<int, int>> v[10001];

int dfs(int start){
    int fst=0, snd=0, sum;
    for (auto n : v[start]){
        //printf("%d %d\n",start,n.second+len);
        sum = dfs(n.first) + n.second;
        if(sum > fst) {
            snd = fst;
            fst = sum;
        }
        else if (sum > snd) snd = sum;
    }
    if(ans < (fst + snd)) ans = fst+snd;
    return fst;
}
int main(){
    scanf("%d",&N);
    for(int i=1;i<N;i++){
        int a,b,w;
        scanf("%d%d%d",&a,&b,&w);
        v[a].push_back(make_pair(b, w));
    }
    
    dfs(1);
    
    printf("%d\n",ans);
}
