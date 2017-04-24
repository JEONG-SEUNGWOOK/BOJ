
#include <cstdio>
#include <algorithm>
using namespace std;

int R,C,area=0,ans=0,cnt=0;
int map[9][9];
int temp[9][9];
bool visited[9][9];
bool t_visited[9][9];
int pr[4]={1,-1,0,0};
int pc[4]={0,0,1,-1};

void dfs(int r, int c){
    t_visited[r][c]=1;
    cnt++;
    for(int i=0;i<4;i++){
        int nr=r+pr[i], nc=c+pc[i];
        if(nr < 0 || nc < 0 || nr >= R || nc >= C) continue;
        if(t_visited[nr][nc]) continue;
        if(temp[nr][nc]!=0) continue;
        dfs(nr, nc);
    }
}
void virus(){
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            if(t_visited[i][j]==0 && temp[i][j]==2){
                dfs(i,j);
            }
        }
    }
}
int main(){
    scanf("%d%d",&R,&C);
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            scanf("%d",&map[i][j]);
            if(map[i][j]!=1) area++;
        }
    }
    int r1,r2,r3, c1,c2,c3;
    for(r1=0;r1<R;r1++){
        for(c1=0;c1<C;c1++){
            if(map[r1][c1]==1 || map[r1][c1]==2) continue;
            
            for(r2=r1;r2<R;r2++){
                for(r1==r2 ? c2=c1+1 : c2=0;c2<C;c2++){
                    if(map[r2][c2]==1 || map[r2][c2]==2) continue;
                    
                    for(r3=r2;r3<R;r3++){
                        for(r3==r2 ? c3=c2+1 : c3=0;c3<C;c3++){
                            if(map[r3][c3]==1 || map[r3][c3]==2) continue;
                            
                            cnt=0;
                            copy(&map[0][0], &map[0][0]+9*9, &temp[0][0]);
                            copy(&visited[0][0], &visited[0][0]+9*9, &t_visited[0][0]);
                            temp[r1][c1] = temp[r2][c2] = temp[r3][c3] = 1;
                            
                            virus();
                            if(area-cnt-3 > ans) ans = area-cnt-3;
                        }
                    }
                }
            }
        }
    }
    
    printf("%d\n",ans);
}
