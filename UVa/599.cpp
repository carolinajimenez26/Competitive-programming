#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int tonum(string &s) {
  stringstream ss;
  ss << s;
  int out;
  ss >> out;
  return out;
}

vector<char> split(string &s, char tok) {
  stringstream ss;
  ss << s;
  vector<char> v;
  while (ss >> tok)
    v.push_back(tok);
  return v;
}

void print(map<char, vector<char> > graph) {
  for (auto n : graph) {
    cout << n.first << " -> ";
    for (auto i : n.second) {
      cout << i << " ";
    }
    cout << endl;
  }
}

void print(map<char, int> m) {
  for (auto& e : m) {
    cout << e.first << " -> " << e.second << endl;
  }
}

void print(map<int, char> m) {
  for (auto& e : m) {
    cout << e.first << " -> " << e.second << endl;
  }
}

void print(vector<char> v) {
  for (auto& e : v) cout << e;
  cout << endl;
}

int solver(map<char, vector<char> > graph, map<char, int> code, map<int, char> decode) {
  int visited[code.size()], source = 0, trees = 0;
  memset(visited, 0, sizeof(visited));
  stack<char> st;

  for (auto& i : graph) {
    if (!visited[code[i.first]]) {
      visited[code[i.first]] = 1;
      st.push(i.first);
      trees++;
    }
    while(!st.empty()) {
      char v = st.top();
      st.pop();
      if (graph[v].size() == 0) {
        visited[code[v]] = 1;
        continue;
      }
      for(auto& nv : graph[v]) {
        if(!visited[code[nv]]) {
          visited[code[nv]] = 1;
          st.push(nv);
        }
      }
    }
  }
  return trees;
}

int main(){
  int tc, trees, acorns;
  string s;
  getline(cin, s);
  tc = tonum(s);
  s.clear();
  map<char, vector<char> > graph;
  map<char, int> code;
  map<int, char> decode;
  set<char> st;
  while (true) {
    if (tc == 0) break;
    s.clear();
    getline(cin, s);
    if (s[0] == '*') {
      s.clear();
      getline(cin, s); // nodes
      vector<char> splitted = split(s, ',');
      // print(splitted);
      int j = 0;
      for (int i = 0; i < splitted.size(); i += 2, j++) {
        code[splitted[i]] = j;
        decode[j] = splitted[i];
      }
      // print(code);
      // print(decode);
      acorns = ((splitted.size() / 2) + 1) - st.size();
      // print(graph);
      trees = solver(graph, code, decode);
      cout << "There are " << trees << " tree(s) and " << acorns << " acorn(s)." << endl;
      graph.clear();
      st.clear();
      code.clear();
      decode.clear();
      tc--;
    } else { // an edge: (U,V)
      graph[s[1]].push_back(s[3]);
      graph[s[3]].push_back(s[1]);
      st.insert(s[1]);
      st.insert(s[3]);
    }
  }
  return 0;
}
