
#include <cstdio>
#include <map>
using namespace std;

int N,M;
map<int, int> m;
pair<map<int, int>::iterator, bool> pr;
map<int, int>::iterator iter;
int main(){
    scanf("%d",&N);
    for(int i=0,n;i<N;i++){
        scanf("%d",&n);
        pr = m.insert({n,1});
        if(!pr.second) pr.first->second +=1;
    }
    
    scanf("%d",&M);
    for(int i=0,n;i<M;i++){
        scanf("%d",&n);
        iter = m.find(n);
        if(iter != m.end()){
            if(i==M-1) printf("%d\n",iter->second);
            else printf("%d ",iter->second);
        }
        else {
            if(i==M-1) printf("0\n");
            else printf("0 ");
        }
    }
}
