
#include <iostream>
using namespace std;
pair<int, int> P;

int main(){
    int X,Y,p,q,t,dir=0;
    cin>>X>>Y>>p>>q>>t;
    P.first=p,P.second=q;
    for(int i=0; i<t; i++){
        int np=P.first, nq=P.second;
        if(dir==0){
            if(np==X && nq==Y) --np,--nq,dir=2;
            else if(np==X) --np,++nq, dir=1;
            else if(nq==Y) ++np, --nq, dir=3;
            else ++np, ++nq;
        }
        else if(dir==1){
            if(np==0 && nq==Y) ++np,--nq,dir=3;
            else if(np==0) ++np,++nq,dir=0;
            else if(nq==Y) --np, --nq, dir=2;
            else --np, ++nq;
        }
        else if(dir==2){
            if(np==0 && nq==0) ++np,++nq,dir=0;
            else if(np==0) ++np,--nq,dir=3;
            else if(nq==0) --np,++nq,dir=1;
            else --np,--nq;
        }
        else if(dir==3){
            if(np==X && nq==0) --np,++nq, dir=1;
            else if(np==X) --np,--nq,dir=2;
            else if(nq==0) ++np,++nq,dir=0;
            else ++np,--nq;
        }
        P.first=np, P.second=nq;
    }
    cout<<P.first<<" "<<P.second<<"\n";
}
