
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int N,ans=0,cnt=1;
vector<vector<int>> m;
queue<vector<vector<int>>> q;


void print(vector<vector<int>> map){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            printf("%d ",map[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
int main(){
    scanf("%d",&N);
    m.resize(N*N);
    for(int i=0;i<N;i++){
        for(int j=0,n;j<N;j++){
            scanf("%d",&n);
            m[i].push_back(n);
        }
    }
    ans=m[0][0];
    q.push(m);
    while(!q.empty()){
        int sz = q.size();
        while(sz--){
            
            vector<vector<int>> t = q.front();
            q.pop();
            
            //right
            vector<vector<int>> tt;
            tt.resize(N*N);
            for(int r=0;r<N;r++){
                
                for(int rr=0;rr<N;rr++)
                    for(int cc=0;cc<N;cc++)
                        tt[rr].push_back(0);
                
                vector<int> v;
                v.resize(N);
                for(int c=N-1;c>=0;c--)
                    if(t[r][c] !=0) v.push_back(t[r][c]);
                
                for(int k=0;k<v.size();k++){
                    if(k==v.size()-1) {
                        if(ans < v[k]) ans=v[k];
                        continue;
                    }
                    if(v[k]==v[k+1]) {
                        v[k] += v[k+1];
                        if(ans < v[k]) ans = v[k];
                        v[k+1] = 0;
                    }
                }
                
                for(int k=0,l=N-1;k<v.size();k++){
                    if(v[k] !=0){
                        tt[r][l--] = v[k];
                    }
                }
            }
            q.push(tt);
            
            
            //left
            tt.clear();
            tt.resize(N*N);
            for(int r=0;r<N;r++){
                
                for(int rr=0;rr<N;rr++)
                    for(int cc=0;cc<N;cc++)
                        tt[rr].push_back(0);
                
                
                vector<int> v;
                v.resize(N);
                for(int c=0;c<N;c++)
                    if(t[r][c] !=0) v.push_back(t[r][c]);
                
                for(int k=0;k<v.size();k++){
                    if(k==v.size()-1) {
                        if(ans < v[k]) ans=v[k];
                        continue;
                    }
                    if(v[k]==v[k+1]) {
                        v[k] += v[k+1];
                        if(ans < v[k]) ans = v[k];
                        v[k+1] = 0;
                    }
                }
                
                for(int k=0,l=0;k<v.size();k++){
                    if(v[k] !=0){
                        tt[r][l++] = v[k];
                    }
                }
            }
            
            q.push(tt);
            
            //up
            tt.clear();
            tt.resize(N*N);
            for(int c=0;c<N;c++){
                
                for(int rr=0;rr<N;rr++)
                    for(int cc=0;cc<N;cc++)
                        tt[rr].push_back(0);
                
                
                vector<int> v;
                v.resize(N);
                for(int r=0;r<N;r++)
                    if(t[r][c] !=0) v.push_back(t[r][c]);
                
                
                
                for(int k=0;k<v.size();k++){
                    if(k==v.size()-1) {
                        if(ans < v[k]) ans=v[k];
                        continue;
                    }
                    if(v[k]==v[k+1]) {
                        v[k] += v[k+1];
                        if(ans < v[k]) ans = v[k];
                        v[k+1] = 0;
                    }
                }
                
                for(int k=0,l=0;k<v.size();k++){
                    if(v[k] !=0){
                        tt[l++][c] = v[k];
                    }
                }
                
                
                
            }
            q.push(tt);
            
            //down
            tt.clear();
            tt.resize(N*N);
            for(int c=0;c<N;c++){
                
                for(int rr=0;rr<N;rr++)
                    for(int cc=0;cc<N;cc++)
                        tt[rr].push_back(0);
                
                vector<int> v;
                v.resize(N);
                for(int r=N-1;r>=0;r--)
                    if(t[r][c] !=0) v.push_back(t[r][c]);
                
                for(int k=0;k<v.size();k++){
                    if(k==v.size()-1) {
                        if(ans < v[k]) ans=v[k];
                        continue;
                    }
                    if(v[k]==v[k+1]) {
                        v[k] += v[k+1];
                        if(ans < v[k]) ans = v[k];
                        v[k+1] = 0;
                    }
                }
                
                for(int k=0,l=N-1;k<v.size();k++){
                    if(v[k] !=0){
                        tt[l--][c] = v[k];
                    }
                }
                
            }
            q.push(tt);
            
        }
        cnt++;
        if(cnt>5) break;
    }
    printf("%d\n",ans);
}

