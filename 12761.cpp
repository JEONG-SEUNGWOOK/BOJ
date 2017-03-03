#include<cstdio>
#include<queue>
using namespace std;

int A, B, N, M, ans = 0;
bool visited[100002];
queue<int> q;

int main() {
    scanf("%d%d%d%d", &A, &B, &N, &M);
    q.push(N);
    visited[N] = 1;
    while (!q.empty()) {
        int sz = q.size();
        while (sz--) {
            int pos = q.front();
            q.pop();
            int next[10] = { 1, -1, A, -A, B, -B, pos*A, -pos*A, pos*B, -pos*B };
            if (pos == M) {
                printf("%d\n", ans);
                return 0;
            }
            for (int i = 0; i < 10; i++) {
                int nextPos;
                if (i < 6) nextPos = pos + next[i];
                else nextPos = next[i];
                if (nextPos < 0 || nextPos >100000) continue;
                if (visited[nextPos]) continue;
                visited[nextPos] = 1;
                q.push(nextPos);
            }
        }
        ans++;
    }
}
