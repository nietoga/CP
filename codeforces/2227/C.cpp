#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n; cin >> n;

  while (n--) {
    int sz; cin >> sz;
    int a[sz];
    for (int i = 0; i < sz; i++) {
      cin >> a[i];
    }

    vector<int> mul3;
    vector<int> mul2;
    vector<int> mul6;
    vector<int> other;

    for (int i = 0; i < sz; i++) {
      if (a[i] % 6 == 0) {
        mul6.push_back(a[i]);
      } else if (a[i] % 3 == 0) {
        mul3.push_back(a[i]);
      } else if (a[i] % 2 == 0) {
        mul2.push_back(a[i]);
      } else {
        other.push_back(a[i]);
      }
    }

    vector<int> result;
    for (int i : mul6) result.push_back(i);
    for (int i : mul3) result.push_back(i);
    for (int i : other) result.push_back(i);
    for (int i : mul2) result.push_back(i);

    for (int i = 0; i < result.size(); i++) {
      cout << result[i] << " ";
    }
    cout << endl;
  }
}
