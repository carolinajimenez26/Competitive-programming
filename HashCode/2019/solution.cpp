#include<bits/stdc++.h>
#define dbg(x) cout << #x << ": " << x << endl
using  namespace std;

struct Photo {
  int id, id2;
  vector<string> tags;
  char op;
  bool used;
  Photo(int _id, vector<string> _tags, char _op) : id(_id), tags(_tags), op(_op)
  {
    used = false;
    id2 = -1;
  }

  void setPhoto(int _id) {
    id2 = _id;
  }

  void print() {
    cout << "************" << endl;
    cout << "id1 " << id << " , id2 " << id2 << endl;
    cout << "tags: ";
    for (int i = 0; i < tags.size(); i++) {
      cout << tags[i] << " ";
    }
    cout << endl;
    cout << "op " << op;
    cout << "used " << used << endl;
    cout << "************" << endl;
  }
};

void print(vector<Photo> vp) {
  cout << "--------------------" << endl;
  for (int i = 0; i < vp.size(); i++) {
    vp[i].print();
  }
  cout << "--------------------" << endl;
}

void print(vector<int> v) {
  for (auto e : v) cout << e << " ";
  cout << endl;
}

void printSol(vector<Photo> v) {
  cout << v.size() << endl;
  for (int i = 0; i < v.size(); i++) {
    cout << v[i].id;
    if (v[i].id2 != -1) cout << " " << v[i].id2;
    cout << endl;
  }
}

vector<string> commonTags(const Photo& a, const Photo& b) {
  set<string> sol;

  for (int i = 0; i < a.tags.size(); i++) {
    sol.insert(a.tags[i]);
  }

  for (int i = 0; i < b.tags.size(); i++) {
    sol.insert(b.tags[i]);
  }

  return {sol.begin(), sol.end()};
}

void addRestNotUsed(vector<Photo>& verticals, vector<Photo>& all){
  int id = -1;
  for (int i = 0; i < verticals.size(); i++) {
    if (verticals[i].used == false) {
      if (id == -1) {
        id = i;
      } else {
        Photo p(verticals[id].id, commonTags(verticals[id], verticals[i]), 'H');
        p.setPhoto(i);
        verticals[id].used = true;
        verticals[i].used = true;
        id = -1;
      }
    }
  }
}

void createAndAddImages(vector<Photo>& verticals, vector<Photo>& all) {

  vector<string> max_commonTags;
  Photo max_p(-1, {}, 'H');

  for (int i = 0; i < verticals.size(); i++) {
    verticals[i].used = true;
    if (verticals[i].used) continue;
    max_commonTags = {};
    for (int j = 0; j < verticals.size(); j++) {
      if (!verticals[j].used) {
        vector<string> v_commonTags = commonTags(verticals[i], verticals[j]);
        if (v_commonTags.size() > max_commonTags.size()) {
          max_commonTags = v_commonTags;
          max_p = verticals[j];
        }
      }
    }

    if (max_commonTags.size() == 0) {
      verticals[i].used = false;
    } else {
      Photo p(verticals[i].id, max_commonTags, 'H');
      p.setPhoto(max_p.id);
      max_p.used = true;
      all.push_back(p);
    }

  }

  addRestNotUsed(verticals, all);
}

int score(Photo p1, Photo p2) {
  int sum1 = 0, sum2 = p1.tags.size(), sum3 = p2.tags.size(), sol = 0;

  for(int i = 0; i < p1.tags.size(); i++){
    if(p2.tags.size() < i){
      for(int j = 0; j < p2.tags.size(); j++){
        if(p1.tags[i] == p2.tags[j]){
          sum1++;
          sum2--;
          sum3--;
        }
      }
    }
  }

  if(sum1 < sum2){
    if(sum1 < sum3) sol = sum1;
    else sol = sum3;
  }
  else {
    if(sum2 < sum3) sol = sum2;
    else sol = sum3;
  }
  return sol;
}

int getScore(const vector<Photo>& photos){
  int scoreTotal = 0;

  for (int i = 0; i < photos.size(); i += 2) {
    scoreTotal += score(photos[i], photos[i + 1]);
  }

  return scoreTotal;
}


vector<Photo> getBestCombination(vector<int> indexes, const vector<Photo>& photos) {
  vector<int> best_combination;
  vector<Photo> sol;

  sort(indexes.begin(), indexes.end());

  int max_score = numeric_limits<int>::min();
  int max_iteration = 50;

  do {
    // print(indexes);
    if (getScore(photos) > max_score) {
      best_combination = indexes;
    }
    max_iteration--;
  } while (next_permutation(indexes.begin(), indexes.end()) && max_iteration >= 0);

  for (int i = 0; i < best_combination.size(); i++) {
    sol.push_back(photos[best_combination[i]]);
  }

  return sol;
}

vector<Photo> slideshow(vector<Photo>& horizontals, vector<Photo>& verticals){

  vector<Photo> all = horizontals;
  createAndAddImages(verticals, all);
  // print(all);

  vector<int> indexes(all.size());

  for (int i = 0; i < indexes.size(); i++) {
    indexes[i] = i;
  }

  return getBestCombination(indexes, all);
}

int main() {
  int N, tagsNumber, id = 0;
  char op;
  cin >> N;
  vector<Photo> horizontals, verticals;
  while (N--) {
    cin >> op;
    cin >> tagsNumber;
    vector<string> tags(tagsNumber);
    for (int i = 0; i < tagsNumber; i++) {
      cin >> tags[i];
    }
    Photo p(id, tags, op);
    op == 'H' ? horizontals.push_back(p) : verticals.push_back(p);
    id++;
  }
  vector<Photo> sol = slideshow(horizontals, verticals);
  printSol(sol);

  return 0;
}
