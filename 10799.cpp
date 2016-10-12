
#include <iostream>
#include <string>
using namespace std;

int main(){
    string bracket;
    int rod=0, sum=0;
    bool leisure = false;

    cin>>bracket;
    for(int i=0; i<bracket.size(); i++){
        char b = bracket.at(i);
        if(b == '('){
            rod++;sum++;
            leisure=true;
        }
        else{
            --rod;
            if(leisure){
                --sum;
                sum += rod;
                leisure = false;
            }
        }
        
    }
    printf("%d",sum);
    return 0;
}
