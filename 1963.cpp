
#include <iostream>
#include <queue>
using namespace std;


bool nextPrime(int n){
    if( (n&1) == 0 )
        return (n == 2);
    
    for(int i=3; i*i<=n; i++)
    {
        if( n % i == 0)
        {
            return false;
        }
    }
    return true;
}

int main(){
    int T;
    cin>>T;
    while(T--){
        int S,E,cnt=0, num[4];
        bool flag = false;
        
        cin>>S>>E;
        queue<int> q;
        bool visited[10000]={0,};
        
        q.push(S);
        visited[S] = true;
        
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                int n = q.front(); q.pop();
                
                if(n == E){
                    flag= true;
                    break;
                }
                for(int i=0;i<4;i++){
                    int j;
                    for(i==0 ? j=1 : j=0 ; j<10;j++){
                        num[0]=n/1000;
                        num[1]=(n%1000)/100;
                        num[2]=(n%1000)%100/10;
                        num[3]=n%10;
                
                        num[i] = j;
                        int nS = num[0]*1000 + num[1]*100 + num[2]*10 + num[3];
                        if(nextPrime(nS) && !visited[nS]){
                            visited[nS] = true;
                            q.push(nS);
                        }
                    }
                }
                
            }
            if(flag) break;
            cnt++;
        }
        flag ? cout<<cnt<<"\n" : cout<<"Impossible\n";
    }
}
