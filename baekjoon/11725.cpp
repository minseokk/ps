#include <iostream>
#include <list> 
#include <stack>

using namespace std;

class Pair {
    public:
    int a, b;

    Pair(int _a, int _b) {
        a = _a;
        b = _b;
    }
};

int main () {
    int n;
    int res[100000];
    list<Pair> input_list;
    list<Pair>::iterator iter; 
    stack<int> stack;
    int tmp_a, tmp_b;

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n-1; i++) {
        cin >> tmp_a;
        cin >> tmp_b;
        input_list.push_back(Pair(tmp_a, tmp_b));
    }

    stack.push(1);

    while (!stack.empty()) {
        for (iter = input_list.begin(); iter != input_list.end();) {
            if (iter->a == stack.top()) {
                res[iter->b] = stack.top();
                stack.push(iter->b);
                input_list.erase(iter);
                iter = input_list.begin();
                continue;
            } else if (iter->b == stack.top()) {
                res[iter->a] = stack.top();
                stack.push(iter->a);
                input_list.erase(iter);
                iter = input_list.begin();
                continue;
            }
            iter++;
        }
        stack.pop();
    }

    for (int i = 2; i <= n; i++) {
        cout << res[i] << "\n";
    }

    return 0;
}