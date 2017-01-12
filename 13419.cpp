
#include <stdio.h>
#include <string.h>
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        char c[27];
        scanf(" %s",c);
        int sz= strlen(c);
        if(sz%2==0){
            for(int j=0;j<2;j++){
                for(int i=0;i<sz/2; i++){
                    printf("%c",c[i*2+j]);
                }
                printf("\n");
            }
        }
        else{
            for(int j=0;j<2;j++){
                if(sz==1){
                    printf("%c",c[0]);
                }
                else{
                    for(int i=0;i<sz; i++){
                        printf("%c",c[(i*2+j)%sz]);
                    }
                }
                printf("\n");
            }
        }
    }
    
}
