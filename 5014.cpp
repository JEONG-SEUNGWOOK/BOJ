
#include <iostream>
#include <queue>
using namespace std;

bool visited[1000001];
queue<int> q;
int main(){
    int F,S,G,U,D,cnt=0;
    bool flag = false;
    cin>>F>>S>>G>>U>>D;
    visited[S]=true;
    q.push(S);
    while(!q.empty()){
        int sz = q.size();
        while(sz--){
            int pos = q.front(); q.pop();
            if(pos == G){
                flag = true;
                break;
            }
            int nPos[2] = {pos - D, pos + U};
            
            for(int i=0;i<2;i++){
                if (i==0 && nPos[0] < 1) continue;
                if (i==1 && nPos[1] > F) continue;
                if (visited[nPos[i]]) continue;
                visited[nPos[i]] = true;
                q.push(nPos[i]);
            }
        }
        if(flag) break;
        cnt++;
    }
    flag ? cout<<cnt<<"\n" : cout<<"use the stairs\n";
}
