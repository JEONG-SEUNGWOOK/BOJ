

#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int N;
bool visited[102];
vector<int> v[102];
queue<int> q;
priority_queue<int> blue, white;
int main(){
    scanf("%d",&N);
    for(int i=1,n,m;i<=N;i++){
        scanf("%d",&n);
        while(n--){
            scanf("%d",&m);
            v[i].push_back(m);
            v[m].push_back(i);
        }
    }
    
    for(int i=1;i<=N;i++){
        bool flag = 0;
        
        if(!visited[i]){
            visited[i]=1;
            q.push(i);
            if(flag) blue.push(-i);
            else white.push(-i);
        }
        
        
        while(!q.empty()){
            int sz = q.size();
            if(flag) flag = 0;
            else flag = 1;
            while(sz--){
                int n = q.front();
                q.pop();
                
                for(auto &l : v[n]){
                    if(visited[l]) continue;
                    visited[l]=1;
                    q.push(l);
                    if(flag) blue.push(-l);
                    else white.push(-l);
                }
            }
            
        }
    }
    int b=blue.size(), w=white.size();
    printf("%d\n",b);
    for(int i=0;i<b;i++){
        if(i==b-1) printf("%d\n",-blue.top());
        else printf("%d ",-blue.top());
        blue.pop();
    }
    printf("%d\n",w);
    for(int i=0;i<w;i++){
        if(i==w-1) printf("%d\n",-white.top());
        else printf("%d ",-white.top());
        white.pop();
    }
}
