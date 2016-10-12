
#include <stdio.h>

int main(){
    bool self_num[20001];
    int n;
    for(int i=1;i<10000;i++){
        n=i;
        while(n<10000){
            if(n<10)
                n+=n;
            
            else if(n>=10 && n<100)
                n+= n/10 + n%10;
            
            else if(n>=100 && n<1000)
                n+= n/100 + (n/10)%10 + n%10;
            
            else if(n>=1000 && n<10000)
                n+= n/1000 + (n/100)%10 + (n/10)%10 + n%10;
            self_num[n]=true;
        }
    }
    for(int i=1;i<10000;i++)
        if(!self_num[i]) printf("%d\n",i);
}
