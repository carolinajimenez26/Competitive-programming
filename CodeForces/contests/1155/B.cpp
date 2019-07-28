#include <iostream>
#include <vector>
#include <queue>
#define endl '\n'

#define dbg(x) cout << #x << ": " << (x) << endl

using namespace std;

void print(const vector<bool>& deleted) {
    for (auto e : deleted) cout << e << " ";
    cout << endl;
}

void Player1Moves(queue<int>& nums_except8, queue<int>& eights,
                  vector<bool>& deleted) {
    int x;
    if (nums_except8.size() > 0) {
        x = nums_except8.front();
        nums_except8.pop();
    } else {
        x = eights.front();
        eights.pop();
    }
    deleted[x] = true;
}

void Player2Moves(queue<int>& eights, vector<bool>& deleted) {
    int x = eights.front();
    eights.pop();
    deleted[x] = true;
}

bool IsValidPhoneNumber(const vector<bool>& deleted, 
                        const string& input) {
    for (int i = 0; i < deleted.size(); i++) {
        if (!deleted[i]) {
            if (input[i] == '8') return true;
            else return false;
        }
    }
    return false;
}

bool PlayerOneWins(queue<int>& nums_except8, queue<int>& eights,
                   string& input) {
    int turns = input.size() - 11;
    bool player1_turn = true;
    vector<bool> deleted(input.size(), false);
    while (turns--) {
        // dbg(turns);
        if (eights.size() == 0) return false;
        if (player1_turn) {
            Player1Moves(nums_except8, eights, deleted);
        } else {
            Player2Moves(eights, deleted);
        }
        player1_turn = !player1_turn;
        // print(deleted);
    }
    return IsValidPhoneNumber(deleted, input);
}

int main() {
    int n;
    cin >> n;
    char c;
    queue<int> nums_except8, eights;
    string input = "";
    for (int i = 0; i < n; i++) {
        cin >> c;
        input.push_back(c);
        if (c == '8') {
            eights.push(i);
        } else {
            nums_except8.push(i);
        }
    }
    bool succeed = PlayerOneWins(nums_except8, eights, input);
    if (succeed) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}