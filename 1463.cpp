
#include <cstdio>
#include <queue>
using namespace std;

queue<int> q;
bool visited[1000000];
int main(){
    int N,cnt=0;
    scanf("%d",&N);
    q.push(N);
    while(!q.empty()){
        int sz=q.size();
        while(sz--){
            int n = q.front(); q.pop();
            
            if (n==1){
                printf("%d\n",cnt);
                return 0;
            }
            if(n%3==0 && n/3>0 && !visited[n/3]) {
                q.push(n/3);
                visited[n/3]=true;
            }
            
            if(n%2==0 && n/2>0 && !visited[n/2]) {
                q.push(n/2);
                visited[n/2]=true;
            }
            
            if(n-1 >0 && !visited[n-1]){
                q.push(n-1);
                visited[n-1]=true;
            }
        }
        cnt++;
    }
    
}
