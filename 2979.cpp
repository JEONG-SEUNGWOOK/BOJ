
#include <cstdio>
#include <queue>
using namespace std;

int main(){
    int A,B,C,cnt=0,ans=0;
    priority_queue<pair<int, bool>> q;
    scanf("%d %d %d",&A,&B,&C);
    for(int i=0;i<3;i++) {
        int a,b;
        scanf("%d%d",&a,&b);
        q.push(make_pair(-a, true));
        q.push(make_pair(-b, false));
    }
    for(int i=1;i<=100;i++){
        while(-q.top().first == i){
            if(q.top().second) cnt++;
            else cnt--;
            q.pop();
            if(q.empty()) break;
        }
        if (cnt==1) ans+=A;
        if (cnt==2) ans+=B*2;
        if (cnt==3) ans+=C*3;
        if(q.empty())break;
    }
    printf("%d\n",ans);
}
