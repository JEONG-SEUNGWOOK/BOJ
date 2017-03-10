
#include <cstdio>
#include <vector>
using namespace std;

int N;
vector<pair<char, char>> v[26];

void preOrder(char root){
    char left = v[root-'A'].front().first;
    char right = v[root-'A'].front().second;
    
    printf("%c",root);
    if(left != '.') preOrder(left);
    if(right != '.') preOrder(right);
}

void inOrder(char root){
    char left = v[root-'A'].front().first;
    char right = v[root-'A'].front().second;
    
    if(left != '.') inOrder(left);
    printf("%c",root);
    if(right != '.') inOrder(right);
}

void postOrder(char root){
    char left = v[root-'A'].front().first;
    char right = v[root-'A'].front().second;
    
    if(left != '.') postOrder(left);
    if(right != '.') postOrder(right);
    printf("%c",root);
}
int main(){
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        char n,l,r;
        scanf(" %c %c %c",&n,&l,&r);
        v[n-'A'].push_back(make_pair(l,r));
    }
    
    preOrder('A');
    printf("\n");
    inOrder('A');
    printf("\n");
    postOrder('A');
    printf("\n");
    
}
