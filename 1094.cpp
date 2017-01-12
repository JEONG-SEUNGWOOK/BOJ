

#include <iostream>
using namespace std;

int main(){
    int X,cnt=0, sum=0;
    int XX,bar=64;
    cin >> X;
    XX=X;
    while(sum!=X){
        if(bar <= XX){
            cnt++;
            sum+=bar;
            XX-=bar;
        }
        bar = bar/2;
    }
    cout<<cnt<<'\n';
}

