// https://www.hackerrank.com/challenges/no-prefix-set/problem
#include <bits/stdc++.h>

using namespace std;

const int ALPH = 'j' - 'a' + 1;

class Trie {
public:
  Trie *children[ALPH] = {nullptr};
  bool isEndNode = false;

  bool add(string input) {
    bool flag = false;
    Trie *n = this;
    for (int i = 0; i < input.size(); ++i) {
      int idx = input[i] - 'a';
      if (!n->children[idx]) {
        n->children[idx] = new Trie();
      }
      n = n->children[idx];
      if (n->isEndNode)
        flag = true;
    }
    n->isEndNode = true;

    for (int i = 0; i < ALPH; ++i) {
      if (n->children[i] != NULL) {
        flag = true;
        break;
      }
    }

    return flag;
  }
};

int main() {
  int N;
  string input;
  Trie root;
  bool flag = false;

  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> input;

    if (root.add(input)) {
      if (!flag) {
        cout << "BAD SET" << endl;
        cout << input << endl;
        flag = true;
      }
    }
  }

  if (!flag) {
    cout << "GOOD SET" << endl;
  }
}
