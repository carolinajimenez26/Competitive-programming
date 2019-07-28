#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cout << #x << ": " << x << endl

void print(unordered_multimap<int, pair<int, int> > M) {
  cout << "--------" << endl;
  for (auto& it : M) {
    cout << "Contestant: " << it.first << endl;
    cout << "Problem resolved: " << it.second.first << endl;
    cout << "Time: " << it.second.second << endl;
  }
  cout << endl;
}

void print(unordered_multimap<int, pair<int, vector<int>> > M) {
  cout << "--------" << endl;
  for (auto& it : M) {
    cout << "Contestant: " << it.first << endl;
    cout << "Problem resolved: " << it.second.first << endl;
    cout << "Times: ";
    for (auto& e : it.second.second) cout << e << " ";
    cout << endl;
  }
  cout << endl;
}

void print(map<int, pair<int, int> > M) {
  cout << "--------" << endl;
  for (auto& it : M) {
    cout << "Contestant: " << it.first << endl;
    cout << "Problems resolved: " << it.second.first << endl;
    cout << "Time: " << it.second.second << endl;
  }
  cout << endl;
}

void print(map<int, multimap<int, map<int, int> > >  M) {
  cout << "--------" << endl;
  for (auto& it : M) {
    cout << "Problems resolved: " << it.first << endl;

    for (auto& it2 : it.second) {
      cout << "Penalty time: " << it2.first << endl;

      for (auto& it3 : it2.second) {
        cout << "Contestant: " << it3.first << endl;
      }

    }

  }
  cout << endl;
}

map<int, multimap<int, map<int, int> > > copy(map<int, pair<int, int> > M) { // sort by problems and by contestant id
  map<int, multimap<int, map<int, int> > > cpy;
  // it.second.first : problems resolved
  // it.second.second : penalty time
  // it.first : contestant
  for (auto& it : M) {
    // dbg(it.second.first); dbg(it.second.second); dbg(it.first);
    if (cpy.count(it.second.first)) { // if that problem was resolved already
      map<int, int> tmp3;
      tmp3[it.first] = 1;
      cpy.find(it.second.first)->second.insert(make_pair(it.second.second, tmp3));
    } else {
      map<int, int> tmp;
      tmp[it.first] = 1;
      multimap<int, map<int, int> > tmp2;
      tmp2.insert(make_pair(it.second.second, tmp));
      cpy.insert(make_pair(it.second.first, tmp2));
    }
  }
  return cpy;
}

void solver(unordered_multimap<int, pair<int, int> > &correct,
            unordered_multimap<int, pair<int, vector<int>> > &incorrect,
            map<int, pair<int, int> > &sol) {

  for (auto it : correct) {
    if (sol.count(it.first)) { // contestant exists
      sol[it.first].first++; // problem
      sol[it.first].second += it.second.second; // time
    } else { // contestant doesn't exist yet
      sol[it.first] = make_pair(1, it.second.second);
    }
  }

  for (auto it_c : correct) {
    for (auto it_i : incorrect) {
      if (it_c.first == it_i.first and it_c.second.first == it_i.second.first) { // find by problem
        for (auto e : it_i.second.second) {
          if (e < it_c.second.second) sol[it_c.first].second += 20;
        }
      }
    }
  }

  map<int, multimap<int, map<int, int> > > sol2 = copy(sol); // resolved, penalty time, id, trash

  // print(sol);
  // print(sol2);
  //
  // return;

  string solution = "";
  int tmp_resolved, tmp_t, tmp_id;

  map<int, multimap<int, map<int, int> > >::reverse_iterator rit;
  for (rit = sol2.rbegin(); rit != sol2.rend(); ++rit) {
    tmp_resolved = rit->first;
    // dbg(tmp_resolved);

    for (auto& it1 : rit->second) {
      tmp_t = it1.first;
      // dbg(tmp_t);

      for (auto& it2 : it1.second) {
        tmp_id = it2.first;
        // dbg(tmp_id);
        solution += to_string(tmp_id) + " " + to_string(tmp_resolved) + " "
                    + to_string(tmp_t) + "\n";
      }

    }

  }
  cout << solution;
}

bool exists(unordered_multimap<int, pair<int, int> > M, int id, int p) {
  for (auto& it : M) {
    if (it.first == id and it.second.first == p) {
      return true;
    }
  }
  return false;
}

int main (void) {
  int tc;
  string s;
  stringstream ss;
  getline(cin, s);
  ss << s;
  ss >> tc;
  int contestant, problem, t;
  char L; // ‘C’, ‘I’, ‘R’, ‘U’ or ‘E’. These stand for Correct, Incorrect,
          // clarification Request, Unjudged and Erroneous submission
  getline(cin, s);
  while (tc--) {
    map<int, pair<int, int> > sol; // contestant, problems resolved, penalty time
    unordered_multimap<int, pair<int, int> > correct; // contestant, problem resolved, time
    unordered_multimap<int, pair<int, vector<int>> > incorrect; // contestant, problem, times
    while (true) {
      getline(cin, s);
      if (s == "") {
        break;
      }
      ss.clear();
      ss << s;
      ss >> contestant >> problem >> t >> L;
      if (L == 'R' or L == 'U' or L == 'E') {
        if (!sol.count(contestant)) {
          sol[contestant] = make_pair(0,0);
        }
      } else if (L == 'C') {
        if (!exists(correct, contestant, problem)) { // if that problem does not exists yet in correct
          correct.insert(make_pair(contestant, make_pair(problem, t)));
        }
        // else { // choose which one has better time
        //   for (auto it : correct) {
        //     if (it.second.first == problem and it.first == contestant) {
        //       if (t < it.second.second) {
        //         it.second.second = t;
        //         break;
        //       }
        //     }
        //   }
        // }
      } else if (L == 'I') {
        if (!sol.count(contestant)) {
          sol[contestant] = make_pair(0,0);
        }
        bool flag = false;
        for (auto& it : incorrect) {
          if (it.second.first == problem and it.first == contestant) { // problem already exist
            it.second.second.push_back(t); // add new time
            flag = true;
            break;
          }
        }
        if (!flag) { // that problem does not exist yet
          vector<int> tmp;
          tmp.push_back(t);
          incorrect.insert(make_pair(contestant, make_pair(problem, tmp)));
        }
      }
    }
    // dbg(correct.size());
    // dbg(incorrect.size());
    // cout << "Correct: " << endl;
    // print(correct);
    // cout << endl;
    // cout << "Incorrect: " << endl;
    // print(incorrect);
    // cout << endl;
    // cout << "Others: " << endl;
    // print(sol);
    solver(correct, incorrect, sol);
    if (tc != 0) cout << endl;
  }
  return 0;
}
