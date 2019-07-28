/*
Evaluate the value of an arithmetic expression in Reverse Polish 
Notation.

Valid operators are +, -, *, /. Each operand may be an integer or 
another expression.

Problem source: https://leetcode.com/problems/evaluate-reverse-polish-notation/description/
*/

#include <iostream>
#include <vector>
#include <string>
#define dbg(x) cout << #x << ": " << x << endl

using namespace std;

struct Node {
    string value;
    Node* parent, *right, *left;
    Node(string _value, Node* _parent) {
        value = _value;
        parent = _parent;
        right = NULL;
        left = NULL;
    } 
};

bool isOperator(string s) {
    return s == "+" || s == "-" || s == "*" || s == "/";
}

void print(Node* n) {
    if (n == NULL) return;
    cout << n->value << " ";
    print(n->left);
    print(n->right);
}

void constructTree(Node* currNode, vector<string> &tokens, int idx) {
    // dbg(idx); dbg(currNode->value);
    if (idx < 0) return;
    if (isOperator(currNode->value)) { // can I have childrens?
        // dbg("Can have childrens");
        if (currNode->right == NULL) { // always go to right first
            // dbg("Go to right");
            Node* right = new Node(tokens[idx], currNode);
            currNode->right = right;
            return constructTree(right, tokens, idx - 1);
        }
        if (currNode->left == NULL) {
            // dbg("Go to left");
            Node* left = new Node(tokens[idx], currNode);
            currNode->left = left;
            return constructTree(left, tokens, idx - 1);
        }
        // right and left are not null
        // dbg("Go to parent");
        return constructTree(currNode->parent, tokens, idx);
    } else { // Go back to dad
        // dbg("Go to parent");
        return constructTree(currNode->parent, tokens, idx);
    }
}

int sum(int a, int b) {
    // dbg("sum");
    return a + b;
}

int rest(int a, int b) {
    // dbg("rest");
    return a - b;
}

int mult(int a, int b) {
    // dbg("mult");
    return a * b;
}

int divi(int a, int b) {
    // dbg("divi");
    return a / b;
}

int calc(Node* currNode) {
    // dbg(currNode->value);
    int left, right;
    if (isOperator(currNode->value)) {
        // dbg("isOperator");
        if (isOperator(currNode->right->value)) {
            // dbg("right isOperator");
            right = calc(currNode->right);
        } else {
            // dbg("right !isOperator");
            right = stoi(currNode->right->value);
        }
        // dbg(right);
        if (isOperator(currNode->left->value)) {
            left = calc(currNode->left);
        } else {
            left = stoi(currNode->left->value);
        }
        // dbg(left);
    } else return stoi(currNode->value);

    if (currNode->value == "+") return sum(left,right);
    if (currNode->value == "-") return rest(left,right); 
    if (currNode->value == "*") return mult(left,right); 
    if (currNode->value == "/") return divi(left,right); 
}

void deleteAll(Node* currNode) {
    if (!isOperator(currNode->value)) {
        delete currNode;
    } else {
        deleteAll(currNode->left);
        deleteAll(currNode->right);
        delete currNode;
    }
}

int evalRPN(vector<string>& tokens) {
    Node* root = new Node(tokens[tokens.size() - 1], NULL);
    constructTree(root, tokens, tokens.size() - 2);
    // print(root);
    int sol = calc(root);
    deleteAll(root);
    return sol;
}

int main(void) {
    vector<vector<string> > input = {
        {"10","6","9","3","+","-11","*","/","*","17","+","5","+"},
        {"2", "1", "+", "3", "*"},
        {"4", "13", "5", "/", "+"},
        {"2", "3", "+"}
    };

    vector<int> expected = {
        22, 
        9,
        6,
        5
    };

    bool succeed = true;

    for (int i = 0; i < input.size(); i++) {
        int output = evalRPN(input[i]);
        if (output == expected[i]) {
            cout << "Succeed" << endl;
        } else {
            cout << "Failure" << endl;
            cout << "Expected " << expected[i] << endl;
            cout << "Received " << output << endl;
            succeed = false;
        }
    }

    if (succeed) {
        cout << "Good job" << endl;
    }

    return 0;
}