#include <iostream>
#include <unordered_map>
#include <vector>
#include <cmath> 
#include <set>

#define dbg(x) cout << #x << ": " << x << endl

using namespace std;

class Solution {
public:
    string FromWordUsingMask(const string& word, const int mask) {
        string result;
        for (int i = 0; i < word.size(); i++) {
            if ((mask >> i) & 1) {
                result.push_back(word[i]);
            }
        }
        return result;
    }

    int numTilePossibilities2(string tiles) {
        set<string> total;
        sort(tiles.begin(), tiles.end());
        do {
            int top = (1 << tiles.size());  // [1, 2**size)
            for (int mask = 1; mask < top; mask++) {
                const string current = FromWordUsingMask(tiles, mask);
                total.insert(current);
            }
        } while (next_permutation(tiles.begin(), tiles.end()));
        
        return total.size();
    }

    int numTilePossibilities(string tiles) {
        set<string> total;
        sort(tiles.begin(), tiles.end());
            int top = (1 << tiles.size());  // [1, 2**size)
            for (int mask = 1; mask < top; mask++) {
                string current = FromWordUsingMask(tiles, mask);
                do {
                    total.insert(current);
                } while (next_permutation(current.begin(), current.end()));
            }
        
        return total.size();
    }
};

struct Test {
    string tiles;
    int expected_output;
};

int main(void) {
    vector<Test> tests = {
        {
            "ABC",
            15
        },
        {
            "AAB",
            8
        },
        {
            "ABCD",
            64
        },
        {
            "AACD",
            34
        },
        {
            "AACC",
            18
        },
        {
            "AACCD",
            89
        }
    };

    bool succeed = true;
    int i = 0;

    for (auto test : tests) {
        Solution sol;
        int got = sol.numTilePossibilities(test.tiles);
        if (got != test.expected_output) {
            succeed = false;
            cout << "Failed in test #" << i << endl;
            cout << "Got " << got << ", expected " << test.expected_output << endl;
        }
        i++;
    }

    if (succeed) cout << "Good Job" << endl;
    else cout << "Keep trying" << endl;

    return 0;
}