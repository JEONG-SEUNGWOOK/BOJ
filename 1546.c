#include<stdio.h>
float a[1001];
int main(){
    int N;
    float max=0,sum=0;
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        scanf("%f",&a[i]);
        if(a[i]>max) max=a[i];
    }
    for(int i=0;i<N;i++) sum+=a[i]/max*100;
    printf("%.2f\n",sum/N);
}
