
#include <stdio.h>
#include <algorithm>
using namespace std;

struct point{
    int x,y;
};
point p[100001];
bool cmp(const point &a, const point &b){
    if(a.x == b.x) return a.y < b.y;
    else return a.x < b.x;

}
int N;

int main(){
    scanf("%d", &N);
    for(int i=0; i<N; ++i)
        scanf("%d %d",&p[i].x, &p[i].y);
    
    sort(p, p+N, cmp);
    for(int i=0; i<N; i++)
        printf("%d %d\n",p[i].x, p[i].y);
    
}
