#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

#define DARR(x, n) // cout << #x << ": "; for (int i = 0; i < n; i++) cout << x[i] << " "; cout << endl;
#define D(x) // cout << #x << " = " << x << endl;

using namespace std;

int calcmex(vector<int> &v, int i, int j) {
  set<int> nums;

  // open i, j while same
  while (i >= 0 && j < v.size()) {
    int l = v[i];
    int r = v[j];

    if (l == r) {
      nums.insert(l);
      i--;
      j++;
    } else {
      break;
    }
  }

  int mex = 0;
  for (int k : nums) {
    if (k == mex) {
      mex++;
    }
  }

  return mex;
}

int main() {
  int tc; cin >> tc;

  while (tc--) {
    int n; cin >> n;
    vector<int> v;

    for (int i = 0; i < n * 2; i++) {
      int x; cin >> x;
      v.push_back(x);
    }

    DARR(v, n * 2);

    int globalmax = 0;
    for (int i = 0; i < n * 2; i++) {
      // soy el centro del palindromo
      int maxmex = calcmex(v, i, i);
      globalmax = max(globalmax, maxmex);
      D(maxmex);
      D(globalmax);

      // soy un lado del palindromo
      maxmex = calcmex(v, i, i + 1);
      globalmax = max(globalmax, maxmex);
      D(maxmex);
      D(globalmax);
    }

    D(globalmax);
    cout << globalmax << endl;
  }
}
