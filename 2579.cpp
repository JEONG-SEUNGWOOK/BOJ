
#include <stdio.h>

int N;
int step[310];
int point[2][310]={0,};

void input(){
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        scanf("%d", &step[i]);
    }
}

void dp(){
    point[0][0] = point[1][0] = step[0];
    for(int i=1; i<=N; i++){
        point[0][i] += point[1][i-1];
        point[1][i] += point[0][i-1];
    }
}
void output(){
}
int main(){
    input();
    dp();
    output();
}
