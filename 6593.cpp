
#include <iostream>
#include <queue>
using namespace std;
struct Pos{
    int l,r,c;
};
int L,R,C,ans=0,dis=0;
char map[32][32][32];
bool isVisited[32][32][32];
Pos s,e;
queue<Pos> q;

int px[6] = {1,-1,0,0,0,0};
int py[6] = {0,0,1,-1,0,0};
int pz[6] = {0,0,0,0,1,-1};
int main(){
    while(true){
        cin>>L>>R>>C;
        dis=0 ,ans=0;
        if(L==0 && R==0 && C==0) return 0;
        
        for(int i=0;i<L;i++){
            for(int j=0;j<R;j++){
                for(int k=0;k<C;k++){
                    isVisited[i][j][k]=false;
                    map[i][j][k]=0;
                }
            }
        }
        
        for(int i=0;i<L;i++){
            for(int j=0;j<R;j++){
                cin>>map[i][j];
                
            }
        }
        
        
        
        for(int i=0;i<L;i++){
            for(int j=0;j<R;j++){
                for(int k=0;k<C;k++){
                    if(map[i][j][k]=='S') s.l=i,s.r=j,s.c=k;
                    if(map[i][j][k]=='E') e.l=i,e.r=j,e.c=k;
                    
                }
            }
        }
        q.push(s);
        isVisited[s.l][s.r][s.c]=true;
        while(!q.empty()){
            int q_size=q.size();
            while(q_size--){
                Pos p=q.front(); q.pop();
                int l=p.l, r=p.r, c=p.c;
                
                //cout<<l<<" "<<r<<" "<<c<<" "<<dis<<endl;
                if(l==e.l && r==e.r && c==e.c){
                    ans = dis;
                    cout<<"Escaped in "<<ans<<" minute(s)."<<'\n';
                    break;
                }
                
                for(int i=0; i<6; i++){
                    if(l+pz[i]>=0 && l+pz[i]<L && r+px[i]>=0 && r+px[i]<R && c+py[i]>=0 && c+py[i]<C
                       && map[l+pz[i]][r+px[i]][c+py[i]]!='#' && !isVisited[l+pz[i]][r+px[i]][c+py[i]]){
                        
                        isVisited[l+pz[i]][r+px[i]][c+py[i]] = true;
                        Pos t;
                        t.l=l+pz[i], t.r=r+px[i], t.c=c+py[i];
                        q.push(t);
                    }
                }
            }
            dis++;
            
        }
        if(ans==0) cout<<"Trapped!"<<'\n';
        
    }
}