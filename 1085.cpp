#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
    int x,y,w,h;
    scanf("%d %d %d %d",&x, &y, &w, &h);
    int m=1001;
    m = min(min(x-0, w-x), min(y-0, h-y));
    printf("%d",m);
    return 0;
}
