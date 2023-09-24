#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define MAX 100001
bool visited[MAX];
int path[MAX];
vector<int> graph[MAX];
int state[MAX];
int n, m;
int BFS(int s) {
    queue<int> a;
    a.push(s);
    visited[s] = true;
    int temp = 0;
    int prevSta = 0;
    int res = 0;
    while (!a.empty()) {
        int u = a.front();
        a.pop();
        for (int i = 0; i < graph[u].size(); i++) {
            int v = graph[u][i];
            if (visited[v] == false) {
                visited[v] = true;
                path[v] = u;
                a.push(v);
            }
        }
        if (u != 1 && graph[u].size() == 1) {
            while (u != -1) {
                if (state[u] == 1) {
                    temp++;
                    prevSta = 1;
                } else {
                    temp = 0;
                    prevSta = 0;
                }
                u = path[u];
                temp = max(prevSta, temp);
                if (u == -1 && temp <= m)
                    res++;
            }
        }
    }
    return res;
}
int main() {
    int i, u, v;
    cin >> n >> m;
    for (i = 1; i <= n; i++) {
        cin >> state[i];
        path[i] = -1;
        visited[i] = false;
    }
    for (i = 0; i < n - 1; i++) {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    cout << BFS(1);
    return 0;
}