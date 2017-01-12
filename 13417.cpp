
#include <cstdio>
#include <deque>
using namespace std;
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        deque<char> dq;
        dq.clear();
        int N;
        char c;
        scanf("%d",&N);
        for(int i=0;i<N;i++){
            scanf(" %c",&c);
            if(dq.empty()) dq.push_back(c);
            else{
                if(dq.front() >= c) dq.push_front(c);
                else dq.push_back(c);
            }
        }
        while(!dq.empty()){
            printf("%c",dq.front());
            dq.pop_front();
        }
        printf("\n");
    }
}

