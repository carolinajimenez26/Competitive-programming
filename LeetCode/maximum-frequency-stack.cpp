#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
#include <stack>
#define dbg(x) cout << #x << ": " << (x) << endl
using namespace std;

struct my_key {
    int frec;
    int last_pos;
    int id;
    bool operator<(const my_key& other) const {
        if (frec == other.frec) {
            return last_pos > other.last_pos;
        }
        return frec > other.frec;
    }
};

class FreqStack {
private:
    unordered_map<int, stack<int>> positions; // id -> positions
    unordered_map<int, int> nums_frec; // id -> frec
    // map<int, set<pair<int, int>, classcomp > > frecs; // Frecs -> set -> {last_pos, id}
    set<my_key> frecs;
    
    int time;

    void printStack(stack<int> st) {
        while (!st.empty()) {
            cout << st.top() << " ";
            st.pop();
        }
    }

    void printPositions() {
        cout << "Number Positions" << endl;
        for (auto e : positions) {
            cout << e.first << " -> ";
            printStack(e.second);
            cout << endl;
        }
        cout << endl;
    }

    void printNumFrec() {
        cout << "Number Frecuency" << endl;
        for (auto e : nums_frec) {
            cout << e.first << " -> " << e.second << endl;
        }
        cout << endl;
    }

    void printSet() {
        cout << "Set of Frecuencies, last position and ID" << endl;
        for (auto key : frecs) {
            cout << key.frec << " " << key.last_pos << " " << key.id << endl;
        }
        cout << endl;
    }

public: 
    FreqStack() : time(0) {}

    void push(int n) {
        int last_frec = nums_frec[n]; // O (1)
        nums_frec[n] += 1; // O (1)

        int last_element_stack = 
            positions[n].size() == 0 ? -1 : positions[n].top(); // O (1)

        positions[n].push(time); // O (1)
        time++;

        my_key p{last_frec, last_element_stack, n};
        
        auto it = frecs.find(p);
        if (it != frecs.end()) {
            frecs.erase(it);
        }

        p = {last_frec + 1, positions[n].top(), n};
        frecs.insert(p); // O (log frecs.size * log set.size)
    }

    int pop() {
        auto first = frecs.begin();

        int most_frecuent = first->id;

        int last_frec = nums_frec[most_frecuent]; // O (1)
        nums_frec[most_frecuent] -= 1; // O (1)

        positions[most_frecuent].pop(); // O (1)
        
        frecs.erase(first); // O (log frecs.size)
        if (nums_frec[most_frecuent]) { // O (1)
            my_key p{last_frec - 1, positions[most_frecuent].top(), most_frecuent }; 
            frecs.insert(p);
        }
        return most_frecuent;
    }

    void print() {
        cout << "****************" << endl;
        printPositions();
        printNumFrec();
        printSet();
        cout << "Time " << time << endl;
        cout << "****************" << endl;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 */

int main(int argc, char const *argv[]) {
    FreqStack* obj = new FreqStack();
    obj->push(5);
    obj->push(7);
    obj->push(5);
    obj->push(7);
    obj->push(4);
    obj->push(5);
    // obj->print();
    cout << obj->pop() << endl;
    // obj->print();
    cout << obj->pop() << endl;
    cout << obj->pop() << endl;
    // obj->print();
    cout << obj->pop() << endl;
    // obj->print();
    return 0;
}
