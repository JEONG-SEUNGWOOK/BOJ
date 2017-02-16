
#include <iostream>
#include <queue>
#include <string>
using namespace std;

int N,M,K,cnt=0,ans=0;
string word;
char map[101][101];
queue<pair<int, int>> q;
bool flag = false;

int pn[4] = {1,-1,0,0};
int pm[4] = {0,0,1,-1};

int main(){
    cin>>N>>M>>K;
    for(int i=0;i<N;i++)
        cin>>map[i];
    cin>>word;
    
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(map[i][j] == word[0]){
                q.push(make_pair(i, j));
            }
        }
    }
    while(!q.empty()){
        int sz = q.size();
        cnt++;
        while (sz--) {
            
            int n = q.front().first;
            int m = q.front().second;
            q.pop();
            if(cnt == word.size()) ans++;
            
            for(int i=0 ; i<4 ; i++){
                for(int j=0; j<K ;j++){
                    int nn = n + pn[i] + j , nm = m + pm[i] + j;
                    if(nn < 0 || nm < 0 || nn >= N || nm >= M) continue;
                    if(cnt == word.size()) {
                        flag = true;
                        break;
                    }
                    if(map[nn][nm] == word[cnt]){
                        q.push(make_pair(nn, nm));
                    }
                }
                //if(flag) break;
            }
            
        }
        if(flag) break;
    }
    cout<<ans<<"\n";
}
