
#include<stdio.h>
int gcd(int p, int q)
{
    if (q == 0) return p;
    return gcd(q, p%q);
}

int main(){
    int A,B;
    scanf("%d",&A);
    getchar();
    scanf("%d",&B);
    int n=gcd(A,B);
    printf("%d:%d\n",A/n,B/n);
}
