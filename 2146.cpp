/*
#include <cstdio>
#include <vector>
using namespace std;

int map[102][102], no=2, N, ans=987654321;
int pr[4] = { 1,-1,0,0 };
int pc[4] = { 0,0,1,-1 };
int visited[102][102];

struct Edge {
    int r, c, no;
};

vector<Edge> v;

void counting(int r, int c, int no) {
    visited[r][c] = 1;
    bool isPushed = false;
    for (int i = 0; i < 4; i++) {
        int nr = r + pr[i], nc = c + pc[i];
        if (visited[nr][nc]) continue;
        if (nr < 0 || nc < 0 || nr >= N || nc >= N) continue;
        if (!isPushed && map[nr][nc] == 0) {
            Edge edge;
            edge.r = r, edge.c = c, edge.no = no;
            v.push_back(edge);
            isPushed = true;
        }
        if (map[nr][nc]) counting(nr, nc, no);
    }
}

int ABS(int n) {
    if (n < 0) return -1 * n;
    else return n;
}

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            scanf("%d", &map[i][j]);
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!visited[i][j] && map[i][j]) {
                counting(i, j, no++);
            }
        }
    }
    
    for (int i = 0; i < v.size()-1; i++) {
        int A_X = v[i].r, A_Y = v[i].c, A_No = v[i].no;
        for (int j = i + 1; j < v.size(); j++) {
            int B_X = v[j].r, B_Y = v[j].c, B_No = v[j].no;
            if (A_No != B_No) {
                int len = ABS(B_X - A_X) + ABS(B_Y - A_Y) - 1;
                if (len < ans) ans = len;
                
            }
        }
    }
    printf("%d\n", ans);
}
*/
