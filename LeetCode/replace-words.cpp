#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <sstream>
#include <map>

using namespace std;

class Node {
private:
  map<char, Node*> edges;
  int frecuency;
  bool final_node;

  void Add(string &s, int id) {
    this->frecuency++;
    if (id == s.size()) {
      this->final_node = true;
      return;
    }
    if (this->edges.count(s[id]) == 0) this->edges[s[id]] = new Node();
    this->edges[s[id]]->Add(s, id + 1);
  }

  bool FindPrefix(const string& s, int s_idx, string& result) {
    if (this->final_node) {
      return true;
    }
    if (s_idx == s.size()) {
      return false;
    }
    if (this->edges.count(s[s_idx]) == 0) {
      return false;
    }
    result.push_back(s[s_idx]);
    return this->edges[s[s_idx]]->FindPrefix(s, s_idx + 1, result);
  }
public:
  Node () : frecuency(0), edges(), final_node(false) {};

  void Add(string& s) {
    Add(s, 0);
  }
  string FindPrefix(const string& s) {
    string result;
    bool found = FindPrefix(s, 0, result);
    return (found ? result : s);
  }

  void Print() {
    for (auto edge : edges) {
      cout << edge.first << endl;
      if (!final_node) {
        edge.second->Print();
      }
    }
    cout << endl;
  }
};

class Solution {
private:
  Node* prefix_tree;
public:
  vector<string> Split(string &s) {
    stringstream ss;
    ss << s;
    vector<string> v;
    string tok;
    while (ss >> tok)
      v.push_back(tok);
    return v;
  }

  string replaceWordsSlow(vector<string>& dict, string sentence) {
    set<string> dic_set;
    string result = "";
    for (auto s : dict) { // O (dict.size())
      dic_set.insert(s);
    }

    vector<string> sentence_split = Split(sentence);

    for (auto s : sentence_split) { // O (sentence_split.size()) = O (sentence.size())
      string curr;
      for (auto c : s) { // O (sentence.size())
        curr.push_back(c);
        if (dic_set.find(curr) != dic_set.end()) {
          break;
        }
      }
      if (dic_set.find(curr) == dic_set.end()) { // O (log sentence.size())
        result.append(s); // O (s) = O (sentence.size())
      } else {
        result.append(curr);
      }
      result.push_back(' ');
    }
    result.pop_back();
    return result;
  }

  string replaceWords(vector<string>& dict, string sentence) {
    string result = "";
    prefix_tree = new Node();

    for (auto s : dict) {
      prefix_tree->Add(s);
    }
    // prefix_tree->Print();

    vector<string> sentence_split = Split(sentence);

    for (auto s : sentence_split) {
      string prefix = prefix_tree->FindPrefix(s);
      result.append(prefix);
      result.push_back(' ');
    }
    result.pop_back();
    return result;
  }
};

int main(void) {
  // vector<string> dic = {"cat", "cato", "catar", "bat", "bata", "batata", "rat"};
  // string sentence = "the cattle was rattled by the battery";
  // string expected = "the cat was rat by the bat";

  // vector<string> dic = {"e","k","c","harqp","h","gsafc","vn","lqp","soy","mr","x","iitgm","sb","oo","spj","gwmly","iu","z","f","ha","vds","v","vpx","fir","t","xo","apifm","tlznm","kkv","nxyud","j","qp","omn","zoxp","mutu","i","nxth","dwuer","sadl","pv","w","mding","mubem","xsmwc","vl","farov","twfmq","ljhmr","q","bbzs","kd","kwc","a","buq","sm","yi","nypa","xwz","si","amqx","iy","eb","qvgt","twy","rf","dc","utt","mxjfu","hm","trz","lzh","lref","qbx","fmemr","gil","go","qggh","uud","trnhf","gels","dfdq","qzkx","qxw"};
  // string sentence = "ikkbp miszkays wqjferqoxjwvbieyk gvcfldkiavww vhokchxz dvypwyb bxahfzcfanteibiltins ueebf lqhflvwxksi dco kddxmckhvqifbuzkhstp wc ytzzlm gximjuhzfdjuamhsu gdkbmhpnvy ifvifheoxqlbosfww mengfdydekwttkhbzenk wjhmmyltmeufqvcpcxg hthcuovils ldipovluo aiprogn nusquzpmnogtjkklfhta klxvvlvyh nxzgnrveghc mpppfhzjkbucv cqcft uwmahhqradjtf iaaasabqqzmbcig zcpvpyypsmodtoiif qjuiqtfhzcpnmtk yzfragcextvx ivnvgkaqs iplazv jurtsyh gzixfeugj rnukjgtjpim hscyhgoru aledyrmzwhsz xbahcwfwm hzd ygelddphxnbh rvjxtlqfnlmwdoezh zawfkko iwhkcddxgpqtdrjrcv bbfj mhs nenrqfkbf spfpazr wrkjiwyf cw dtd cqibzmuuhukwylrnld dtaxhddidfwqs bgnnoxgyynol hg dijhrrpnwjlju muzzrrsypzgwvblf zbugltrnyzbg hktdviastoireyiqf qvufxgcixvhrjqtna ipfzhuvgo daee r nlipyfszvxlwqw yoq dewpgtcrzausqwhh qzsaobsghgm ichlpsjlsrwzhbyfhm ksenb bqprarpgnyemzwifqzz oai pnqottd nygesjtlpala qmxixtooxtbrzyorn gyvukjpc s mxhlkdaycskj uvwmerplaibeknltuvd ocnn frotscysdyclrc ckcttaceuuxzcghw pxbd oklwhcppuziixpvihihp";
  // string expected = "i miszkays w gvcfldkiavww v dvypwyb bxahfzcfanteibiltins ueebf lqhflvwxksi dc k w ytzzlm gximjuhzfdjuamhsu gdkbmhpnvy i mengfdydekwttkhbzenk w h ldipovluo a nusquzpmnogtjkklfhta k nxzgnrveghc mpppfhzjkbucv c uwmahhqradjtf i z q yzfragcextvx i i j gzixfeugj rnukjgtjpim h a x h ygelddphxnbh rvjxtlqfnlmwdoezh z i bbfj mhs nenrqfkbf spfpazr w c dtd c dtaxhddidfwqs bgnnoxgyynol h dijhrrpnwjlju muzzrrsypzgwvblf z h q i daee r nlipyfszvxlwqw yoq dewpgtcrzausqwhh q i k bqprarpgnyemzwifqzz oai pnqottd nygesjtlpala q gyvukjpc s mxhlkdaycskj uvwmerplaibeknltuvd ocnn f c pxbd oklwhcppuziixpvihihp";
  
  vector<string> dic = {"i","mxjfu"};
  string sentence = "miszkays";
  string expected = "miszkays";
  
  Solution sol;
  string out = sol.replaceWords(dic, sentence);
  cout << out << endl;
  if (out != expected) {
    cout << "Keep trying" << endl;
  } else {
    cout << "Good job" << endl;
  }
  return 0;
}