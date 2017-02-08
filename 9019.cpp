
#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T--){
        int A, B;
        bool visited[10000]={0,};
        queue<pair<int, string>> q;
        
        cin>>A>>B;
        q.push(make_pair(A, ""));
        visited[A]=true;
        
        while(!q.empty()){
            int n = q.front().first;
            string s = q.front().second;
            q.pop();
            
            if(n == B){
                cout<<s<<"\n";
                break;
            }
            
            // 1. D
            int dn = (2*n)%10000;
            string ds = s;
            if(!visited[dn]) {
                visited[dn] = true;
                ds += "D";
                q.push(make_pair(dn, ds));
            }
            
            // 2. S
            int sn;
            string ss = s;
            if((sn = n - 1) < 0) sn = 9999;
            if(!visited[sn]) {
                visited[sn] = true;
                ss += "S";
                q.push(make_pair(sn, ss));
            }
            
            // 3. L
            string ls = s;
            int ln1 = n/1000;
            int ln = (n%1000)*10+ln1;
            if(!visited[ln]) {
                visited[ln] = true;
                ls += "L";
                q.push(make_pair(ln, ls));
            }
            
            // 4. R
            string rs = s;
            int rn4 = n%10;
            int rn = (n/10)+ rn4*1000;
            if(!visited[rn]) {
                visited[rn] = true;
                rs += "R";
                q.push(make_pair(rn, rs));
            }
        }
    }
}
