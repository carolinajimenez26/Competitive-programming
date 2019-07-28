#include <iostream>
#include <vector>

using namespace std;

bool allVisited(vector<bool> &visited) {
  for (bool b : visited) if (!b) return false;
  return true;
}

void visit(vector<vector<int>>& rooms, vector<bool> &visited, int room) {
  visited[room] = true;
  vector<int> keys = rooms[room];
  for (int i = 0; i < keys.size(); i++) {
    int next_room = keys[i];
    if (!visited[next_room]) visit(rooms, visited, next_room);
  }
}

bool canVisitAllRooms(vector<vector<int>>& rooms) {
  vector<bool> visited(rooms.size());
  visit(rooms, visited, 0);
  return allVisited(visited);
}

int main(void) {
  vector<vector<int>> input = {{1,3},{3,0,1},{2},{0}};
  cout << canVisitAllRooms(input) << endl;
  return 0;
}
