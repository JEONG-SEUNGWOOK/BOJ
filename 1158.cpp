
#include <iostream>
#include <queue>
using namespace std;

int N, M;
vector<int> v;
queue<int> q1;
queue<int> q2;
int main(){
    cin>>N>>M;
    
    for(int i=1; i<=N; i++)
        q1.push(i);
    
    int cur=1;
    cout<<"<";
    
    while(!(q1.empty() && q2.empty())){
        while(!q1.empty()){
            if(cur!=M){
                q2.push(q1.front());
                q1.pop();
                cur++;
            }
            else{
                cout<<q1.front();
                q1.pop();
                cur=1;
                if(q1.empty() && q2.empty()) cout<<">";
                else cout<<", ";
            }
        }
        while(!q2.empty()){
            if(cur!=M){
                q1.push(q2.front());
                q2.pop();
                cur++;
            }
            else{
                cout<<q2.front();
                q2.pop();
                cur=1;
                if(q1.empty() && q2.empty()) cout<<">";
                else cout<<", ";
            }
        }
    }
}

