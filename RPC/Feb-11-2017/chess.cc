#include<bits/stdc++.h>
using namespace std;

int count_whites;

char tablero[26][26];

string tostring(int &n){
  stringstream ss;
  ss << n;
  string out;
  ss >> out;
  return out;
}

string mapeo(pair<int,int> s, int x) {
  int n = x - s.second;
  string second = tostring(n);
  char letter[26] = {'a', 'b', 'c', 'd', 'e', 'f',
  'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q',
  'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
  return letter[s.first] + second;
}

void go_back(vector< pair <int,int> > whites) {
  if (whites.size() > 0) {
    whites.pop_back(); // elimina el último elemento del vector
    count_whites++;
  }
}

pair <vector< pair <int,int> >, vector< pair <int,int> > > pos_mov(int x, int y){

  vector< pair <int,int> > valid_pos;
  vector< pair <int,int> > whites;

  if(tablero[x+1][y-1] == 'W' && tablero[x+2][y-2] == '_'){
    whites.push_back ( make_pair(x+1, y-1) );
    valid_pos.push_back ( make_pair(x+2, y-2));
  }
  if(tablero[x-1][y-1] == 'W' && tablero[x-2][y-2] == '_'){
    whites.push_back ( make_pair(x-1, y-1) );
    valid_pos.push_back ( make_pair(x-2, y-2));
  }
  if(tablero[x+1][y+1] == 'W' && tablero[x+2][y+2] == '_'){
    whites.push_back ( make_pair(x+1, y+1) );
    valid_pos.push_back ( make_pair(x+2, y+2));
  }
  if(tablero[x-1][y+1] == 'W' && tablero[x-2][y+2] == '_'){
    whites.push_back ( make_pair(x-1, y+1) );
    valid_pos.push_back ( make_pair(x-2, y+2));
  }
  return make_pair(valid_pos,whites);
}

void print_table() {
  cout << "-----------" << endl;
  for(int i=0; i<5; i++){
    for(int j=0; j<5; j++){
      cout << tablero[i][j];
    }
    cout << endl;
  }
  cout << "-----------" << endl;
}

pair<int,int> DFS(pair<int,int> initial_node) {

  stack< pair<int,int> > s; //movimientos de b
  s.push(initial_node);
  while (!s.empty()) {
    //print_table();
    pair<int, int> e = s.top(); s.pop();
    cout << "e : " << e.first << " , " << e.second << endl;

    cout << "count_whites : " << count_whites << endl;

    if (count_whites == 0) { // encontramos la salida
      //cout << "ultimo : " << initial_node.first << " , " << initial_node.second << endl;
      return initial_node;
    }

    count_whites--; // si nos movimos es porque nos comimos una blanca

    pair < vector< pair <int,int> >, vector< pair <int,int> > > neighs = pos_mov(e.first,e.second);
    cout << "tiene vecinos : " << neighs.first.size() << endl;
    if (neighs.first.size() == 0) { // no tiene vecinos
      go_back(); // despinta y aumenta contador
    }
    for (int i = 0; i < neighs.first.size(); i++) {
      s.push(neighs.first[i]);
    }
    //cout << "Debe borrar : " << neighs.second[neighs.second.size()-1] << endl;
    neighs.second.pop_back();
  }
  return make_pair(-1,-1);

}

int main(){
  int x;
  vector< pair <int,int> > blacks;
  pair<int,int> ans, solution;
  int ans2 = 0;
  cin >> x;
  for(int i=0; i<x; i++){
    for(int j=0; j<x; j++){
      cin >> tablero[i][j];
      if (tablero[i][j] == 'W') count_whites++;
      if (tablero[i][j] == 'B') blacks.push_back(make_pair(i,j));
    }
  }

  for (int i = 0; i < blacks.size(); i++) {
    cout << "DFS" << endl;
    ans = DFS(blacks[i]);
    cout << "ans : " << ans.first << " , " << ans.second << endl;
    if (ans.first != -1) { // no hay solución
      ans2++;
      solution = ans;
    }
    if (ans2 > 1) break;
  }

  if (ans2 == 0) cout << "None" << endl;
  else if (ans2 > 1) cout << "Multiple" << endl;
  else cout << mapeo(solution,x) << endl;
  return 0;
}
