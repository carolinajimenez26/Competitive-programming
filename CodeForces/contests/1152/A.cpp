#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int chestsCanOpen(queue<int>& treasures_even, queue<int>& treasures_odd,
                  queue<int>& keys_even, queue<int>& keys_odd) {

    int result = 0;
    while (!treasures_even.empty() && !keys_odd.empty()) {
        treasures_even.pop();
        keys_odd.pop();
        result++;
    }

    while (!treasures_odd.empty() && !keys_even.empty()) {
        treasures_odd.pop();
        keys_even.pop();
        result++;
    }

    return result;
}

int main(void) {
    int n, m;
    cin >> n >> m;
    vector<int> treasures(n), keys(m);
    queue<int> treasures_even, treasures_odd;
    queue<int> keys_even, keys_odd;
    for (int i = 0; i < n; i++) {
        cin >> treasures[i];
        if (treasures[i] % 2 == 0) {
            treasures_even.push(treasures[i]);
        } else {
            treasures_odd.push(treasures[i]);
        }
    }
    for (int i = 0; i < m; i++) {
        cin >> keys[i];
        if (keys[i] % 2 == 0) {
            keys_even.push(keys[i]);
        } else {
            keys_odd.push(keys[i]);
        }
    }
    cout << chestsCanOpen(treasures_even, treasures_odd, keys_even, keys_odd) << endl;
    return 0;
}