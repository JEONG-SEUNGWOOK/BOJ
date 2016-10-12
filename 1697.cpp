

#include <iostream>
#include <queue>
using namespace std;

int N, K;
pair<int, int> p;
queue<pair<int, int>> q;
bool isVisited[100005];
int ans;
int main(){
    scanf("%d%d",&N,&K);
    q.push(make_pair(N, 0));
    while(!q.empty()){
        p = q.front(); q.pop();
        int time = p.second;
        int pos = p.first;
        isVisited[pos]=true;
        
        if(pos == K){
            ans=time;
            break;
        }
        if(pos*2<=100000 && !isVisited[pos*2] ) q.push(make_pair(pos*2, time+1));
        
        
        
        if(!isVisited[pos-1] && pos-1 >= 0)
            q.push(make_pair(pos-1, time+1));
        
        
       
        if(!isVisited[pos+1] && pos+1 <= 100000) q.push(make_pair(pos+1, time+1));
        
    }
    cout<<ans<<'\n';
}

