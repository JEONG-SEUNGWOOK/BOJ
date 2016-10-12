#include <stdio.h>
#include <algorithm>
using namespace std;

struct Ball{
    int color, size, idx, sum;
};
bool cmp_size(const Ball &a, const Ball &b){
    return a.size < b.size;
}
int N, total_sum=0;
Ball ball[200001];
int color_sum[200001]={0,};
int score[200001]={0,};
void input(){
    scanf("%d",&N);
    for(int i=0; i<N; i++){
        scanf("%d %d",&ball[i].color, &ball[i].size);
        ball[i].idx = i;
        ball[i].sum = 0;
    }
}
void process(){
    sort(ball, ball+N, cmp_size);

    for(int i=0; i<N; i++){
        ball[i].sum = total_sum - color_sum[ball[i].color];
        if(i>0 && ball[i].size == ball[i-1].size){
            for(int j=i-1; j>=0; --j){
            
                
                if( ball[i].size == ball[j].size ){
                    if(ball[i].color != ball[j].color){
                        ball[i].sum -= ball[j].size;
                    }

                    
                    
                }
                else break;
            }
        }
        score[ball[i].idx] = ball[i].sum;
        total_sum += ball[i].size;
        
        color_sum[ball[i].color] += ball[i].size;
    }
}
void output(){
    for(int i=0; i<N; i++){
        printf("%d\n", score[i]);
    }
}

int main(){
    input();
    process();
    output();
}

