
#include <iostream>
#include <queue>
using namespace std;

int pr[4] = {1,-1,0,0};
int pc[4] = {0,0,1,-1};

int main(){
    int T;
    cin>>T;
    while(T--){
        int H,W,ans=0;
        char map[101][101];
        bool visited[101][101]={0,};
        queue<pair<int, int>> q;
        queue<pair<int, int>> door[26];
        bool keys[26]={0,};
        string key;
        
        cin>>H>>W;
        for(int i=0;i<H;i++) cin>>map[i];
        cin>>key;
        
        if(key.at(0) != '0'){
            for(int i=0;i<key.size();i++){
                keys[key.at(i)-'a']=true;
            }
        }
        
        for(int i=0;i<H;i++)
            for(int j=0;j<W;j++)
                if(i==0 || i==H-1 || j==0 || j==W-1)
                    if(map[i][j]!='*')
                        q.push(make_pair(i, j));
        
        while(!q.empty()){
            
            int r = q.front().first, c = q.front().second;
            char pos = map[r][c];
            q.pop();
        
            if(isupper(pos)) {
                if(keys[pos-'A'])
                    map[r][c]='.';
                
                else{
                    door[pos-'A'].push(make_pair(r, c));
                    continue;
                }
            }
            else if(islower(pos)) {
                int k = pos-'a';
                while(!door[k].empty()){
                    q.push(make_pair(door[k].front().first, door[k].front().second));
                    door[k].pop();
                }
                keys[k] = true;
                map[r][c]='.';
            }
            else if(pos == '$') {
                map[r][c]='.';
                ans++;
            }

            
            for(int i=0;i<4;i++) {
                int nr = r+pr[i], nc = c+pc[i];
                if(nr <0 || nc <0 || nr >=H || nc >=W) continue;
                if(visited[nr][nc]) continue;
                if(map[nr][nc] == '*') continue;
                visited[nr][nc] = true;
                q.push(make_pair(nr, nc));
            }
        }
        
        cout<<ans<<"\n";
    }
}
