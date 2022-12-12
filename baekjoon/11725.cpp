#include <iostream>
#include <vector> 
#include <stack>

using namespace std;

int main () {
    int n;
    int res[100000];
    bool visited[100000] = {false};
    stack<int> stack;
    int tmp_a, tmp_b;
    int child;

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    vector<int> graph[n+1];

    for (int i = 0; i < n-1; i++) {
        cin >> tmp_a;
        cin >> tmp_b;
        graph[tmp_a].push_back(tmp_b);
        graph[tmp_b].push_back(tmp_a);
    }

    stack.push(1);
    visited[1] = true;

    while (!stack.empty()) {
        for (int i = 0; i < graph[stack.top()].size();) {
            child = graph[stack.top()][i];
            if (!visited[child]) {
                visited[child] = true;
                res[child] = stack.top();
                stack.push(child);
                i = 0;
                continue;
            }
            i++;
        }
        tmp_a = stack.top();
        stack.pop();
    }

    for (int i = 2; i <= n; i++) {
        cout << res[i] << "\n";
    }

    return 0;
}