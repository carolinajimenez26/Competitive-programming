#include <bits/stdc++.h>
using namespace std;

struct Query{
  int id;
  int time;
  Query(int _id, int _time) : id(_id), time(_time) {};
  bool operator < (Query o) const {
    if(time != o.time){
      return time > o.time;
    }
    return id > o.id;
  }
};

int tonum(string &s) {
  stringstream ss;
  ss << s;
  int out;
  ss >> out;
  return out;
}

vector<int> split(string s){
  stringstream ss;
  ss << s;
  vector<int> v;
  string tok;
  ss >> tok;
  while (ss >> tok)
    v.push_back(tonum(tok));
  return v;
}

void solver(map<int, int> &periods, int k){
  priority_queue<Query, vector<Query> > pq;
  for(auto it : periods){
    pq.push(Query(it.first, it.second));
  }

  while(k--){
    Query q = pq.top();
    pq.pop();
    printf("%d\n", q.id);
    q.time += periods[q.id];
    pq.push(q);
  }
}

int main(){
  string line;
  int k;
  map<int, int> periods;
  while(getline(cin, line)){
    if(line == "#") break;
    vector<int> v = split(line);
    periods[v[0]] = v[1];
  }
  getline(cin, line);
  k = tonum(line);
  solver(periods, k);
  return 0;
}
