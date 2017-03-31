
#include <cstdio>
#include <queue>
using namespace std;
int S,cnt=0;
queue<pair<int, int>> q;
bool visited[2002][2002];
int main(){
    scanf("%d",&S);
    q.push(make_pair(1, 0));
    visited[1][0]=1;
    while(!q.empty()){
        int sz=q.size();
        while(sz--){
            int len = q.front().first;
            int clip = q.front().second;
            q.pop();
            
            if(len == S){
                printf("%d\n",cnt);
                return 0;
            }
            
            //1. copy
            int c = len;
            q.push(make_pair(len, c));
            
            //2. paste
            if(clip!=-1) {
                int l = len+clip;
                if(!visited[l][clip] && l<=1000) q.push(make_pair(l, clip));
                visited[l][clip] = 1;
            }
            
            //3. remove emoji
            int l = len-1;
            if(!visited[l][clip] && l>1) q.push(make_pair(l, clip));
            visited[l][clip] = 1;
        }
        cnt++;
    }
}
