

#include <cstdio>
#include <queue>
using namespace std;
int R,C, cnt=0;
char map[1502][1502];
bool visited[1502][1502], thaw_visited[1502][1502];
queue<pair<int, int>> q, thaw;
pair<int, int> S,E;
int pr[4]={1,-1,0,0};
int pc[4]={0,0,1,-1};
bool flag = 0;

void MeltIce(int r, int c){
    thaw_visited[r][c]=1;
    if(map[r][c]=='X'){
        thaw.push({r, c});
        if(flag) map[r][c]='.';
    }
    else {
        for(int i=0;i<4;i++){
            int nr = r+pr[i], nc = c+pc[i];
            if(nr < 0 || nc < 0 || nr >= R || nc >= C) continue;
            if(thaw_visited[nr][nc]) continue;
            MeltIce(nr, nc);
        }
    }
    return;
}

bool canMeetFuckingSwan(){
    //만남가능여부
    queue<pair<int, int>> swan_temp;
    swap(swan_temp, q);
    while(!swan_temp.empty()){
        int r = swan_temp.front().first, c = swan_temp.front().second;
        swan_temp.pop();
        if(r==E.first && c==E.second){
            return true;
        }
        for(int i=0;i<4;i++){
            int nr = r+pr[i], nc = c+pc[i];
            if(nr < 0 || nc < 0 || nr >= R || nc >= C) continue;
            if(visited[nr][nc]) continue;
            if(map[nr][nc]=='X') q.push({nr, nc});
            else swan_temp.push({nr ,nc});
            visited[nr][nc]=1;
        }
    }
    return false;
}

int main(){
    scanf("%d%d",&R,&C);
    bool first=0;
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            char c;
            scanf(" %c",&c);
            map[i][j]=c;
            if(c=='L'){
                if(!first){
                    first= 1;
                    S.first=i, S.second=j;
                }
                else E.first=i, E.second=j;
            }
        }
    }
    
    // 테두리 얼음 찾기
    for(int i=0;i<R;i++)
        for(int j=0;j<C;j++)
            if(!thaw_visited[i][j] && map[i][j]!='X')
                MeltIce(i,j);
    flag = 1;
    q.push(make_pair(S.first, S.second));
    visited[S.first][S.second]=1;
    
    while(!canMeetFuckingSwan()){
        cnt++;
        
        //해동
        queue<pair<int, int>> temp;
        swap(temp, thaw);
        while(!temp.empty()){
            int r=temp.front().first, c=temp.front().second;
            temp.pop();
            MeltIce(r, c);
        }
        
    }
    
    printf("%d\n",cnt);
    /*
     printf("%d\n",cnt);
     for(int i=0;i<R;i++){
     for(int j=0;j<C;j++){
     printf("%c",map[i][j]);
     }
     printf("\n");
     }
     */
    
    
    return 0;
}
