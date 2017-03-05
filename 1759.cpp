
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

int L,C;
char c[16];

void code(int n){
    int place[16], consonants = 0, vowels = 0;
    int a = n, cnt = 0;
    for(int i=C-1;i>=0;i--){
        place[i] = a%2;
        if(a % 2) {
            cnt++;
            if(c[i] == 'a' || c[i] == 'e' || c[i] == 'i' || c[i] == 'o' || c[i] == 'u')
                vowels++;
            else consonants++;
        }
        a /= 2;
    }
    
    if(cnt == L && (consonants > 1 && vowels > 0)){
        for(int i=0;i<C;i++)
            if(place[i])
                printf("%c",c[i]);
    printf("\n");
    }
}
int main(){
    scanf("%d%d",&L,&C);
    for(int i=0;i<C;i++)
        scanf(" %c",&c[i]);
    sort(c, c+C);
    
    for(int i=pow(2, C); i>0; i--)
        code(i);
    
}
