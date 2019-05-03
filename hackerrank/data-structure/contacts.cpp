// https://www.hackerrank.com/challenges/contacts/problem

#include <bits/stdc++.h>

using namespace std;

const int ALPH = 26;

class Node {
public:
  class Node *children[ALPH] = {nullptr};
  int wordsBellow = 0;
  bool isEndOfWord = false;
};

void add(Node *root, string s) {
  Node *n = root;

  for (int i = 0; i < s.size(); ++i) {
    int idx = s[i] - 'a';
    if (!n->children[idx]) {
      n->children[idx] = new Node();
    }
    n = n->children[idx];
    n->wordsBellow++;
  }
  n->isEndOfWord = true;
}

int search(Node *root, string s) {
  Node *n = root;
  for (int i = 0; i < s.size(); ++i) {
    int idx = s[i] - 'a';
    if (!n->children[idx]) {
      return 0;
    }
    n = n->children[idx];
  }

  if (n == NULL) {
    return 0;
  }

  return n->wordsBellow;
}

int main() {
  int N;
  string op, name;
  Node root;

  scanf("%d", &N);
  while (N--) {
    cin >> op >> name;
    if (op[0] == 'a') {
      add(&root, name);
    } else {
      cout << search(&root, name) << endl;
    }
  }
  return 0;
}
