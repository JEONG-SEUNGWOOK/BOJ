#include <cstdio>
#include <deque>
using namespace std;

int turnLeft(int n){
    if(n==1) return 4;
    else if(n==2) return 3;
    else if(n==3) return 1;
    else return 2;
}

int turnRight(int n) {
    if(n==1) return 3;
    else if(n==2) return 4;
    else if(n==3) return 2;
    else return 1;
}

int pr[5] = {0, 0,0,1,-1};
int pc[5] = {0, 1,-1,0,0};

deque<pair<int, int>> dq;
bool flag= false;
int map[102][102];
int N, K, X, L, dir=1, ans=1;
char C;
int r=0,c=0, nr,nc;

int main(){
    scanf("%d%d",&N,&K);
    while(K--){
        int a,b;
        scanf("%d%d",&a,&b);
        map[a-1][b-1] = 2;
    }
    map[0][0] = 1;
    dq.push_back(make_pair(0, 0));
    scanf("%d",&L);
    while(L--){
        
        scanf("%d %c",&X,&C);
        
        for(int i=ans;i<=X;i++){
            nr = r + pr[dir];
            nc = c + pc[dir];
            //printf("%d %d\n",nr, nc);
            if(nr < 0 || nc < 0 || nr >= N || nc >= N || map[nr][nc]==1) {
                flag = true;
                break;
            }
            
            if(map[nr][nc] == 0) {
                map[dq.back().first][dq.back().second] = 0;
                dq.pop_back();
            }
            dq.push_front(make_pair(nr, nc));
            map[nr][nc] = 1;
            
            r=nr, c=nc;
            ans++;
        }
        if(flag) break;
        if(C=='D') dir = turnRight(dir);
        else dir = turnLeft(dir);
    }
    printf("%d\n",ans);
    return 0;
}
