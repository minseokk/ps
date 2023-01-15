#include <iostream>
#include <vector>

using namespace std;
int MAX_SIZE = 1001;
int MAX = 1000001;

int main() {
    // v: number of nodes, m: number of edges
    // J: Jiheon's location, S: Sungha's location
    int v, m, J, S, a, b, c;
    int graph[MAX_SIZE][MAX_SIZE]; 

    cin >> v >> m;

    if (v == 2) {
        cout << -1;
        return 0;
    }

    for (int i = 1; i <= v; i++) {
        for (int j = 1; j <= v; j++) {
            graph[i][j] = MAX;
        }
    }

    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;

        if (graph[a][b] > c) {
            graph[a][b] = c;
            graph[b][a] = c;
        }
    }

    cin >> J >> S;

    for (int mid = 1; mid <= v; mid++) {
        for (int start = 1; start <= v; start++) {
            for (int end = 1; end <= v; end++) {
                if (start == end) {
                    continue;
                }
                if (graph[start][end] > graph[start][mid] + graph[mid][end]) {
                    graph[start][end] = graph[start][mid] + graph[mid][end];
                    graph[end][start] = graph[start][mid] + graph[mid][end];
                }
            }
        }
    }

    /*
    for (int i = 1; i <= v; i++) {
        for (int j = 1; j <= v; j++) {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
    */

    // md: Shortest path between J and S.
    int md = MAX;

    for (int i = 1; i <= v; i++) {
        if (i == S || i == J) {
            continue;
        }
        if (graph[J][i] + graph[i][S] < md) {
            md = graph[J][i] + graph[i][S];
        }
    }

    int candidate = -1;

    for (int i = 1; i <= v; i++) {
        if (i == S || i == J) {
            continue;
        }
        if (graph[J][i] + graph[i][S] == md && graph[J][i] <= graph[i][S]) {
            if (candidate > 0) {
                if (graph[J][i] < graph[J][candidate]) {
                    candidate = i;
                } else if (graph[J][i] == graph[J][candidate] && i < candidate) {
                    candidate = i;
                }
            } else {
                candidate = i;
            }
        }
    }

    cout << candidate;

    return 0;
}