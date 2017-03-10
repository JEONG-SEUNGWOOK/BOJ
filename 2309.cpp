

#include <cstdio>
#include <cmath>
#include <queue>
using namespace std;


priority_queue<int> pq;

bool print(int num[], int i_num){
    bool end = false;
    int place[9], cnt=0, sum=0;
    for(int i=8;i>=0;i--){
        if(i_num%2){
            cnt++;
            sum+=num[i];
        }
        place[i] = i_num%2;
        i_num/=2;
    }
    if(cnt == 7 && sum == 100){
        for(int i=0; i<9; i++){
            if(place[i]) {
                pq.push(-num[i]);
            }
        }
        end = true;
        while(!pq.empty()){
            printf("%d\n",-pq.top());
            pq.pop();
        }
    }
    return end;
}

int main(){
    int num[9];
    for(int i=0;i<9;i++)
        scanf("%d",&num[i]);
    
    for(int i=pow(2,6); i<=pow(2,9); i++)
        if(print(num, i)) break;
    
}
