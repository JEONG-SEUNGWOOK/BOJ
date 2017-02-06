
#include <stdio.h>

int R,C,cnt=0,time=0;
int map[303][303];
bool isVisited[303][303];
int dr[4]={1,-1,0,0};
int dc[4]={0,0,1,-1};

void dfs(int r,int c){
    isVisited[r][c] = true;
    for(int i=0;i<4;i++){
        int nr = r+dr[i], nc = c+dc[i];
        if(nr >= 0 && nc >= 0 && nr < R && nc < C && !isVisited[nr][nc] && map[nr][nc] > 0){
            dfs(nr,nc);
        }
    }
}
int melt(int r,int c){
    int num=0;
    for(int i=0;i<4;i++){
        int nr = r+dr[i], nc = c+dc[i];
        if(map[nr][nc] == 0){
            ++num;
        }
    }
    return num;
}
int main(){
    int n;
    scanf("%d%d",&R,&C);
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            scanf("%d",&n);
            map[i][j] = n;
        }
    }
    
    while(true){
        cnt=0;
        int meltMap[303][303];
        
        // isVisited 배열 초기화
        for(int i=0;i<R;i++){
            for(int j=0;j<C;j++){
                isVisited[i][j] = false;
            }
        }
        
        //빙하 개수 세기
        for(int i=0;i<R;i++){
            for(int j=0;j<C;j++){
                if(!isVisited[i][j] && map[i][j] > 0){
                    cnt++;
                    dfs(i,j);
                }
            }
        }
        
        //얼음 융해
        for(int i=0;i<R;i++){
            for(int j=0;j<C;j++){
                if(map[i][j] == 0) continue;
                meltMap[i][j] = map[i][j] - melt(i, j);
                if(meltMap[i][j] < 0) meltMap[i][j] = 0;
            }
        }
        
        //얼음 크기 수정
        for(int i=0;i<R;i++){
            for(int j=0;j<C;j++){
                map[i][j] = meltMap[i][j];
            }
        }
        if(cnt >= 2) {
            printf("%d\n",time);
            break;
        }
        if(cnt == 0) {
            printf("0\n");
            break;
        }
        time++;
    }
}
