/*
In a 2 dimensional array grid, each value grid[i][j] represents the 
height of a building located there. We are allowed to increase the 
height of any number of buildings, by any amount (the amounts can be 
different for different buildings). Height 0 is considered to be a 
building as well. 

At the end, the "skyline" when viewed from all four directions of the 
grid, i.e. top, bottom, left, and right, must be the same as the 
skyline of the original grid. A city's skyline is the outer contour 
of the rectangles formed by all the buildings when viewed from a 
distance. See the following example.

What is the maximum total sum that the height of the buildings can be 
increased?
*/

#include <iostream>
#include <vector>
#define dbg(x) cout << #x << ": " << x << endl

using namespace std;

void print(vector<int> v) {
    for (auto e : v) {
        cout << e << " ";
    }
    cout << endl;
}

int getMax(vector<int> v) {
    int max = v[0];
    for (auto e : v) {
        if (e > max) max = e;
    }
    return max;
}

int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
    int cols = grid[0].size();
    int rows = grid.size();
    // dbg(rows); dbg(cols);
    vector<int> maxLeftRight(rows);
    vector<int> maxUpDown(cols);

    for (int i = 0; i < rows; i++) {
        maxLeftRight[i] = getMax(grid[i]);
    }
    // print(maxLeftRight);

    vector<int> tmp(rows);

    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) {
            tmp[j] = grid[j][i];
        }
        // print(tmp);
        maxUpDown[i] = getMax(tmp);
    }

    // print(maxUpDown);

    int sol = 0;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            // dbg(grid[i][j]);
            int min_n = min(maxLeftRight[i],maxUpDown[j]);
            // dbg(min_n);
            sol += min_n - grid[i][j];
        }
    }

    return sol;
}

int main(void) {
    // vector<vector<int> > grid = {
    //     {3,0,8,4},
    //     {2,4,5,7},
    //     {9,2,6,3},
    //     {0,3,1,0}
    // };
    // int expected = 35;

    // vector<vector<int> > grid = {
    //     {3,0,8,4},
    //     {2,4,5,7}
    // };
    // int expected = 10;

    // vector<vector<int> > grid = {
    //     {3,0},
    //     {2,4},
    //     {9,2},
    //     {0,3}
    // };
    // int expected = 10;

    // vector<vector<int> > grid = {
    //     {3},
    //     {2},
    //     {9},
    //     {0}
    // };
    // int expected = 0;

    vector<vector<int> > grid = {
        {3,0,8,4}
    };
    int expected = 0;

    cout << maxIncreaseKeepingSkyline(grid) << endl;
    return 0;
}