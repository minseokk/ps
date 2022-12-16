#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    int tmp_a, tmp_b;
    int child;
    stack<int> stack;
    bool indegree[32001] = { false };
    bool visited[32001] = { false };
    int res[32001];

    cin >> n >> m;

    vector<int> input[n+1];

    for (int i = 0; i < m; i++) {
        cin >> tmp_a >> tmp_b;
        input[tmp_a].push_back(tmp_b);
        indegree[tmp_b] = true;
    }

    for (int i = 1; i <= n; i++) {
        if (!indegree[i]) {
            stack.push(i);
        }
    }

    tmp_b = n;

    while (!stack.empty()) {
        for (int i = 0; i < input[stack.top()].size();) {
            child = input[stack.top()][i];
            if (!visited[child]) {
                visited[child] = true;
                stack.push(child);
                i = 0;
                continue;
            }
            i++;
        }
        res[tmp_b] = stack.top();
        tmp_b--;
        stack.pop();
    }

    for (tmp_b++; tmp_b <= n; tmp_b++) {
        cout << res[tmp_b] << " ";
    }

    return 0;
}