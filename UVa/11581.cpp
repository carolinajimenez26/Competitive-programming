#include <bits/stdc++.h>
using namespace std;

void print(int *M) {
  cout << "My matrix contain" << endl;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      cout << M[i * 3 + j] << " ";
    }
    cout << endl;
  }
  cout << endl;
}

int* op(int *grid) {
  int *new_grid = (int*)malloc(3 * 3 * sizeof(int));
  memcpy(new_grid, grid, 3 * 3 * sizeof(int));

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (j - 1 >= 0) new_grid[i * 3 + j] += grid[i * 3 + (j - 1)];
      if (j + 1 < 3) new_grid[i * 3 + j] += grid[i * 3 + (j + 1)];
      if (i - 1 >= 0) new_grid[i * 3 + j] += grid[(i - 1) * 3 + j];
      if (i + 1 < 3) new_grid[i * 3 + j] += grid[(i + 1) * 3 + j];
      if(grid[i * 3 + j]) new_grid[i * 3 + j] -= 1;
      new_grid[i * 3 + j] %= 2;
    }
  }
  return new_grid;
}

bool isInf(int *M) {
  int zeros = 0;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (!M[i * 3 + j]) zeros++;
    }
  }
  return zeros == 9 ? true : false;
}

void solver(int *grid) {
  int counter = -1;
  while (!isInf(grid)) {
    grid = op(grid);
    // print(grid);
    counter++;
  }
  cout << counter << endl;
}

int main (void) {
  int tc;
  int *grid = (int*)malloc(3 * 3 * sizeof(int));
  cin >> tc;
  while (tc--) {
    string line;
    for (int i = 0; i < 3; i++) {
      cin >> line;
      for (int j = 0; j < 3; j++) {
        grid[i * 3 + j] = line[j] - '0';
      }
    }
    // print(grid);
    solver(grid);
  }
  return 0;
}
