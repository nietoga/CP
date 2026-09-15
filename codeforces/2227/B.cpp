#include <iostream>

using namespace std;

int main() {
  int n; cin >> n;

  while (n--) {
    int len; cin >> len;
    string s; cin >> s;

    // im stupid: remove whole string, reinsert anywhere = arbitrary permutation.
    // so L == R is enough; prefix balance / crossing-zero stuff is irrelevant.
    int open = 0, close = 0;
    for (char c : s) {
      if (c == '(') open++;
      else close++;
    }

    cout << (open == close ? "YES" : "NO") << endl;
  }
}
