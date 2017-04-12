
#include <iostream>
#include <string>
using namespace std;

int kr,kc,sr,sc;
int N;

bool cmp(int kr, int kc, int sr, int sc){
    if(kr==sr && kc==sc) return true;
    return false;
}
bool isOut(int r, int c){
    if(r < 1 || c < 1 || r > 8 || c > 8) return true;
    return false;
}
int main(){
    char c;
    scanf(" %c",&c);
    kc=c-'A'+1;
    scanf("%d",&kr);
    scanf(" %c",&c);
    sc=c-'A'+1;
    scanf("%d",&sr);
    scanf("%d",&N);
    
    while(N--){
        string s;
        cin>>s;
        if(s=="R") {
            if(!isOut(kr, kc+1)) {
                kc++;
                if(cmp(kr, kc, sr, sc)){
                    if(!isOut(sr, sc+1)) sc++;
                    else kc--;
                }
            }
        }
        
        else if(s=="L") {
            if(!isOut(kr, kc-1)) {
                kc--;
                if(cmp(kr, kc, sr, sc)){
                    if(!isOut(sr, sc-1)) sc--;
                    else kc++;
                }
            }
        }
        
        else if(s=="B") {
            if(!isOut(kr-1, kc)) {
                kr--;
                if(cmp(kr, kc, sr, sc)){
                    if(!isOut(sr-1, sc)) sr--;
                    else kr++;
                }
            }
        }
        
        else if(s=="T") {
            if(!isOut(kr+1, kc)) {
                kr++;
                if(cmp(kr, kc, sr, sc)){
                    if(!isOut(sr+1, sc)) sr++;
                    else kr--;
                }
            }
        }
        
        else if(s=="RT") {
            if(!isOut(kr+1, kc+1)) {
                kr++, kc++;
                if(cmp(kr, kc, sr, sc)){
                    if(!isOut(sr+1, sc+1)) sr++,sc++;
                    else kr--, kc--;
                }
            }
        }
        
        else if(s=="LT") {
            if(!isOut(kr+1, kc-1)) {
                kr++, kc--;
                if(cmp(kr, kc, sr, sc)){
                    if(!isOut(sr+1, sc-1)) sr++,sc--;
                    else kr--, kc++;
                }
            }
        }
        
        else if(s=="RB") {
            if(!isOut(kr-1, kc+1)) {
                kr--, kc++;
                if(cmp(kr, kc, sr, sc)){
                    if(!isOut(sr-1, sc+1)) sr--, sc++;
                    else kr++, kc--;
                }
            }
        }
        
        else if(s=="LB") {
            if(!isOut(kr-1, kc-1)) {
                kr--, kc--;
                if(cmp(kr, kc, sr, sc)){
                    if(!isOut(sr-1, sc-1)) sr--, sc--;
                    else kr++, kc++;
                }
            }
        }
        printf("%c%d %c%d\n",kc+'A'-1,kr,sc+'A'-1,sr);
    }
    
    printf("%c%d\n",kc+'A'-1,kr);
    printf("%c%d\n",sc+'A'-1,sr);
}
