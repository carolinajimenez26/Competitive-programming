#include <bits/stdc++.h>
using namespace std;
unordered_map<string, pair<string, string> > M;
/*
The rules of the game are:
  scissors cuts paper;
  paper covers rock;
  rock crushes lizard;
  lizard poisons Spock;
  Spock smashes scissors;
  scissors decapitates lizard;
  lizard eats paper;
  paper disproves Spock;
  Spock vaporizes rock;
  rock crushes scissors.

pedra = rock,
papel = paper,
tesoura = scissors,
lagarto = lizard,
Spock = Spock
*/

void init(){
  M["tesoura"] = make_pair("papel","lagarto");
  M["papel"] = make_pair("pedra","Spock");
  M["pedra"] = make_pair("lagarto","tesoura");
  M["lagarto"] = make_pair("Spock","papel");
  M["Spock"] = make_pair("tesoura","pedra");
}

int main(void){
  int cases;
  string sheldon, raj;
  pair<string, string> compair;
  init();
  cin >> cases;
  for(int i = 1; i <= cases; i++){
    cin >> sheldon >> raj;
    if (sheldon == raj) cout << "Caso #" << i << ": De novo!" << endl;
    else {
      compair = M[sheldon];
      if (compair.first == raj || compair.second == raj) cout << "Caso #" << i << ": Bazinga!" << endl;
      else cout << "Caso #" << i << ": Raj trapaceou!" << endl;
    }
  }
  return 0;
}
