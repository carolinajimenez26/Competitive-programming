#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

struct Slice {
  int start_row;
  int end_row;
  int start_col;
  int end_col;
  Slice(int _start_row, int _end_row, int _start_col, int _end_col) : start_row(_start_row),
    end_row(_end_row), start_col(_start_col), end_col(_end_col) {}

  void print() {
    cout << start_row << " " << end_row << " " << start_col << " " << end_col << endl;
  }
};

struct Slices {
  vector<Slice> slices;
  int min_ingredients;
  int max_cells;
  Slices() min_ingredients(-1), max_cells(-1) {}

  void addSlice(Slice s) {
    slices.push_back(s);
  }

  vector<Slice> getSlices() {
    return slices;
  }

  void print() {
    cout << slices.size() << endl;
    for (auto slice : slices) {
      slice.print();
    }
  }
};

struct Pizza {
  vector<vector<int>> pizza_information;
  int tomatoes_amount;
  int mushrooms_amount;
  vector<pair<int,int>> tomatoes_positions;
  vector<pair<int,int>> mushrooms_positions;
  vector<vector<bool>> visited;
  Slices slices;
  Pizza(vector<vector<int>> _pizza, int min_ingredients, int max_cells,
        vector<pair<int,int>> _mushrooms, vector<pair<int,int>> _tomatoes) :
    pizza_information(_pizza), tomatoes_positions(_tomatoes), mushrooms_positions(_mushrooms) {
      visited.resize(pizza.size(), vector<bool>(pizza[0].size(), false));
      tomatoes_amount = _tomatoes.size();
      mushrooms_amount = _mushrooms.size();
      slices.min_ingredients = min_ingredients;
      slices.max_cells = max_cells;
  }

  bool positionExists(pair<int,int> pos) {
    return pos.first >= 0 && pos.first < pizza_information.size() &&
           pos.second >= 0 && pos.second < pizza_information[0].size();
  }

  void addSlice(Slice s) {
    slices.addSlice(s);
  }

  vector<Slice> getSlices() {
    return slices.getSlices();
  }

  void printSlices() {
    slices.print();
  }
};

pair<int, int> getValidPosition(const pair<int, int>& pos, const Pizza& pizza) {
  pair<int, int> result = pos;
  const int delta_row[] = {0, 1, 0, -1};
  const int delta_col[] = {1, 0, -1, 0};

  for (int i = 0; i < 4; i++) {
    result.first += delta_row[i];
    result.second += delta_col[i];
    if (pizza.positionExists(result) && !pizza.visited[result.first][result.second])
      return result;
    result.first -= delta_row[i];
    result.second -= delta_col[i];
  }
  return make_pair(-1,-1);
}

void growUntil() {

}

void getMinimumSol(pair<int,int> current_pos, Pizza& pizza) {
  int how_much_to_grow = min_ingredients * 2 - 1;

  pair<int, int> valid_pos = getValidPosition(current_pos, pizza);

  if (valid_pos.first == -1) return;
  how_much_to_grow--; // now is even
  Slice slice();

  growUntil(pizza, slice);
}

void cutPizza(Pizza& pizza) {

  vector<pair<int,int>> bigger_amount = (pizza.tomatoes_amount > pizza.mushrooms_amount ?
                                         tomatoes_positions : mushrooms_positions);

  for (int i = 0; i < bigger_amount.size(); i++) {
    getMinimumSol(bigger_amount[i], pizza);
  }
}

int main(void) {
  int R, C, L, H;
  cin >> R >> C >> L >> H;
  vector<vector<int>> input(R, vector<char>(C));
  vector<pair<int,int>> T, M;
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      cin >> input[i][j];
      if (pizza[i][j] == 'T') T.push_back(make_pair(i,j));
      else M.push_back(make_pair(i,j));
    }
  }
  Pizza pizza(input, L, H, M, T);
  cutPizza(pizza);
  pizza.printSlices();
  return 0;
}
