
#include <cstdio>
using namespace std;

int n,k,s;
bool incident[401][401];
int main(){
    //cin사용하니 TLE
    scanf("%d%d",&n,&k);
    
    while(k--){
        int a,b;
        scanf("%d%d",&a,&b);
        incident[a][b]=true;
    }
    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                incident[i][j] = incident[i][j] || (incident[i][k]&&incident[k][j]);
            }
        }
    }
    
    scanf("%d",&s);
    while(s--){
        int a,b;
        scanf("%d%d",&a,&b);
        if(!incident[a][b] && !incident[b][a]) printf("0\n");
        else if(incident[a][b]) printf("-1\n");
        else if(!incident[a][b] && incident[b][a]==1) printf("1\n");
    }
}