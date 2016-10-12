
#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;
int cur=1;
string ch[110];
void b3(){
    string temp = ch[cur];
    ch[cur] = ch[cur+1];
    ch[++cur] = temp;
    cout<<3;
}
void b4(){
    string temp = ch[cur];
    ch[cur] = ch[cur-1];
    ch[--cur] = temp;
    cout<<4;
}
int main(){
    int N;
    scanf("%d", &N);
    for(int i=1; i<=N; i++)
        cin>>ch[i];
    
    //1단계
    for(int i=1; i<=N;i++){
        if(ch[cur]=="KBS1") break;
        ++cur;
        cout<<1;
    }
    //2단계
    for(int i=1; i<=N;i++){
        if(ch[1]=="KBS1")break;
        b4();
    }
    //3단계
    for(int i=1; i<=N;i++){
        if(ch[2]=="KBS2") break;
        if(ch[cur]=="KBS2") break;
        ++cur;
        cout<<1;
    }
    //4단계
    for(int i=1; i<=N;i++){
        if(ch[2]=="KBS2")break;
        b4();
    }
    return 0;
}

