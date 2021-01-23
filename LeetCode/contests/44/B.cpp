#include <iostream>
#include <vector>
#include <unordered_set>
#include <map>
#include <set>
using namespace std;

struct Node {
  int id;
  vector<Node*> neighs;
  unordered_set<int> languages;
  map<Node*, bool> can_communicate;

  Node(int id): id(id) {}

  void Print() {
    cout << id << "->";
    for (auto neigh : neighs) {
      cout << neigh->id << ", ";
    }
    cout << ". Languages: (";
    for (auto language : languages) {
      cout << language << ", ";
    }
    cout << "). " << endl;
  }

  bool CanCommunicate(Node* other) {
    if (can_communicate.count(other)) {
      return can_communicate[other];
    }

    for (auto lang : languages) {
      if (other->languages.count(lang)) {
        can_communicate[other] = true;
        other->can_communicate[this] = true;
        return true;
      }
    }
    can_communicate[other] = false;
    other->can_communicate[this] = false;
    return false;
  }

  bool Knows(int language) {
    return languages.count(language) > 0;
  }
};

class Graph {
public:
  Graph(int nodes) {
    for (int i = 0; i < nodes; i++) {
      graph.push_back(new Node(i));
    }
  }

  void AddEdge(int from, int to) {
    assert(IsValid(from));
    assert(IsValid(to));
    graph[from]->neighs.emplace_back(graph[to]);
  }

  int GetSize() const {
    return graph.size();
  }

  void Print() {
    cout << "-----" << endl;
    for (auto node : graph) {
      node->Print();
    }
    cout << "-----" << endl;
  }

  void AddLanguagues(int node_id, const vector<int>& node_languages) {
    assert(IsValid(node_id));
    graph[node_id]->languages = unordered_set<int>(node_languages.begin(), node_languages.end());
  }

  void FixCommsWithLang(int language) {
    vector<bool> visited(graph.size(), false);
    needs_to_learn.clear();
    for (int i = 0; i < graph.size(); i++) {
      if (!visited[i]) {
        FixCommsWithLang(visited, graph[i], language);
      }
    }
  }

  int GetNumPeopleNeedsToLearn() {
    return needs_to_learn.size();
  }

  ~Graph() {
    for (int i = 0; i < graph.size(); i++) {
      delete graph[i];
    }
  }
private:
  vector<Node*> graph;
  set<Node*> needs_to_learn;

  bool IsValid(int idx) {
    return idx >= 0 && idx < graph.size();
  }

  void FixCommsWithLang(vector<bool>& visited, Node* person, int language) {
    visited[person->id] = true;
    for (auto neigh : person->neighs) {
      if (!visited[neigh->id]) {
        FixCommsWithLang(visited, neigh, language);
      }
      if (!person->CanCommunicate(neigh)) {
        if (!person->Knows(language)) {
          needs_to_learn.insert(person);
        }
        if (!neigh->Knows(language)) {
          needs_to_learn.insert(neigh);
        }
      }
    }
  }
};

class Solution {
public:
  int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
    Graph graph(languages.size());
    CreateConnections(graph, friendships); // O (n * n)
    AddLanguagues(graph, languages); // O (n * n)
    // graph.Print();
    int best = graph.GetSize(); // everyone has to learn a new language
    for (int language = 1; language <= n; language++) { // O (n)
      graph.FixCommsWithLang(language); // O ()
      // graph.Print();
      best = min(best, graph.GetNumPeopleNeedsToLearn());
    }
    return best;
  }
private:
  void CreateConnections(Graph& graph, const vector<vector<int>>& friendships) {
    for (auto edge : friendships) {
      int u = edge[0] - 1;
      int v = edge[1] - 1;
      graph.AddEdge(u, v);
      graph.AddEdge(v, u);
    }
  }

  void AddLanguagues(Graph& graph, const vector<vector<int>>& languages) {
    assert("There should be information of languagues for all nodes" && graph.GetSize() == languages.size());
    for (int node = 0; node < languages.size(); node++) {
      graph.AddLanguagues(node, languages[node]);
    }
  }
};

struct Test {
  int n;
  vector<vector<int>> languages;
  vector<vector<int>> friendships;
  int expected;
};

int main(void) {
  vector<Test> tests = {
    { 2, {{1},{2},{1,2}}, {{1,2},{1,3},{2,3}}, 1 },
    { 3, {{2},{1,3},{1,2},{3}}, {{1,4},{1,2},{3,4},{2,3}}, 2 }, 
  };
  int tc = 0;
  bool succeed = true;
  for (auto test : tests) {
    Solution sol;
    int out = sol.minimumTeachings(test.n, test.languages, test.friendships);
    if (out != test.expected) {
      cout << "Failed on test #" << tc << ". Found: " << out << ", expected: " << test.expected << endl;
      succeed = false;
    }
    tc++;
  }
  cout << (succeed ? "Good job" : "Keep trying") << endl;
  return 0;
}