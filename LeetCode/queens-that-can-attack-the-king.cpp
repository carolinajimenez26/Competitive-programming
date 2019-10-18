#include <iostream>
#include <vector>
#include <set>
#include <cmath>

using namespace std;

class Solution {
public:
    bool IsValid(int row, int col) {
        return row >= 0 && row < 8 && col >= 0 && col < 8;
    }

    vector<vector<int>> queensAttacktheKingSlower(vector<vector<int>>& queens, vector<int>& king) {
        vector<vector<int> > result;
        set<vector<int> > queens_set;
        for (auto vi : queens) {
            queens_set.insert(vi);
        }
        vector<int> dirs_rows({-1, -1, 0, 1, 1,  1,  0, -1});
        vector<int> dirs_cols({ 0,  1, 1, 1, 0, -1, -1, -1});
        // up, up-right, right, right-down, down, down-left, left, left-up

        for (int dir = 0; dir < dirs_rows.size(); dir++) { // O (8)
            int delta_row = dirs_rows[dir];
            int row = king[0] + delta_row;
            int delta_col = dirs_cols[dir];
            int col = king[1] + delta_col;
            while (IsValid(row, col)) { // O(col || row)
                if (queens_set.find({row, col}) != queens_set.end()) { // that queen exists, O(log queens)
                    result.push_back({row, col});
                    break;
                }
                row += delta_row;
                col += delta_col;
            }
        }
        return result;
    }

    vector<vector<int>> CollectSolutions(const vector<vector<pair<int, int> > >& solutions) {
        vector<vector<int>> result;
        vector<int> dirs_rows({-1, -1, 0, 1, 1,  1,  0, -1});
        vector<int> dirs_cols({ 0,  1, 1, 1, 0, -1, -1, -1});
        // up, up-right, right, right-down, down, down-left, left, left-up

        for (int dir = 0; dir < dirs_rows.size(); dir++) { // O (8)
            int row = 1 + dirs_rows[dir];
            int col = 1 + dirs_cols[dir];
            if (solutions[row][col].first != -1) {
                result.push_back({solutions[row][col].first, solutions[row][col].second});
            }
        }
        return result;
    }

    double EuclideanDistance(const pair<int, int>& pos1, const pair<int, int>& pos2) {
        double x = (pos1.first - pos2.first) * (pos1.first - pos2.first);
        double y = (pos1.second - pos2.second) * (pos1.second - pos2.second);
        return sqrt(x + y);
    } 

    // returns true if pos1 is closer to target than pos2
    bool CloserThan(const pair<int, int>& pos1, const pair<int, int>& pos2, const pair<int, int>& target) {
        if (EuclideanDistance(pos1, target) < EuclideanDistance(pos2, target)) {
            return true;
        }
        return false;
    }

    // find if pos is for example at the right up of target and knowing that return what would it be 
    // the position in the matrix solution 
    pair<int, int> FindPositionIn(const vector<vector<pair<int, int>>>& matrix, pair<int, int> pos,
                                 pair<int, int> target) {
        if (pos.first < target.first && pos.second < target.second) { // left up diagonal
            return {0,0};
        }
        if (pos.first < target.first && pos.second == target.second) { // up
            return {0,1};
        }
        if (pos.first < target.first && pos.second > target.second) { // up right diagonal
            return {0,2};
        }
        if (pos.first == target.first && pos.second > target.second) { // right
            return {1,2};
        }
        if (pos.first > target.first && pos.second > target.second) { // right down diagonal
            return {2,2};
        }
        if (pos.first > target.first && pos.second == target.second) { // down
            return {2,1};
        }
        if (pos.first > target.first && pos.second < target.second) { // left down diagonal
            return {2,0};
        }
        if (pos.first == target.first && pos.second < target.second) { // left
            return {1,0};
        }
        return {-1,-1}; // error
    }

    // returns true if pos shares a diaglonal, row or col with target_pos
    bool Attacks(pair<int, int> pos, pair<int, int> target_pos) {
        return (pos.first == target_pos.first) || (pos.second == target_pos.second) ||
               (abs(target_pos.first - pos.first) == abs(target_pos.second - pos.second));
    }

    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        vector<vector<pair<int, int> > > solutions(3, vector<pair<int, int> >(3, {-1, -1}));
        pair<int, int> king_pos = {king[0], king[1]};
        for (auto position_v : queens) {
            pair<int, int> queen_position = {position_v[0], position_v[1]};
            if (Attacks(queen_position, king_pos)) {
                pair<int, int> position_solution = FindPositionIn(solutions, queen_position, king_pos);
                pair<int, int> current_solution = solutions[position_solution.first][position_solution.second];
                bool taken = current_solution.first != -1;
                if (!taken || (taken && CloserThan(queen_position, current_solution, king_pos))) {
                    solutions[position_solution.first][position_solution.second] = queen_position;
                }
            }
        }
        return CollectSolutions(solutions);
    }
};

void Print(const vector<vector<int>>& vvi) {
    for (auto vi : vvi) {
        for (auto i : vi) {
            cout << i << " ";
        }
        cout << endl;
    }
}

int main(void) {
    Solution sol;
    vector<vector<int>> queens = {{0,0},{1,1},{2,2},{3,4},{3,5},{4,4},{4,5}}; 
    vector<int> king = {3,3};
    vector<vector<int>> out = sol.queensAttacktheKing(queens, king);
    Print(out);
    return 0;
}