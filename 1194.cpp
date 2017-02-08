

#include <iostream>
#include <queue>
using namespace std;

struct Minsik{
    int R,C,key=0;
};

queue<Minsik> q;
int R,C,cnt=0;
bool flag=false;
char map[52][52];
bool isVisited[52][52][64];
int pr[4]={1,-1,0,0};
int pc[4]={0,0,1,-1};

int main(){
    cin>>R>>C;
    for(int i=0;i<R;i++){
        cin>>map[i];
    }
    
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            if(map[i][j] == '0') {
                Minsik t;
                t.R = i, t.C = j;
                q.push(t);
                isVisited[i][j][0] = true;
            }
        }
    }
    
    
    while(!q.empty()){
        int sz = q.size();
        while(sz--){
            Minsik m = q.front(); q.pop();
            int r = m.R, c = m.C, key = m.key;
            //cout<<"-> "<<r<<" "<<c<<" cnt: "<<cnt<<" "<< key <<endl;
            
            if(map[r][c] == '1'){
                flag = true;
                break;
            }
            for(int i=0;i<4;i++){
                int nr = r + pr[i], nc = c + pc[i], nkey = key;
                
                if(nr<0 || nc<0 || nr>=R || nc>=C) continue;
                
                if(map[nr][nc] == '#') continue;
                else if(isupper(map[nr][nc])){
                    if(!(nkey & (1 << (map[nr][nc]-'A'))))
                        continue;
                }
                else if(islower(map[nr][nc])) {
                    nkey |= (1 << (map[nr][nc]-'a'));
                }
                
                if(isVisited[nr][nc][key]) continue;
                isVisited[nr][nc][nkey] = true;
                Minsik t;
                t.R = nr, t.C = nc, t.key = nkey;
                q.push(t);
            }
            
        }
        if(flag) break;
        cnt++;
    }
    flag ? cout<<cnt<<"\n": cout<<-1<<"\n";
}
