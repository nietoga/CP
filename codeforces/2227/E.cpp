#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

#define DARR(x, n) // cout << #x << ": "; for (long long i = 0; i < n; i++) cout << x[i] << " "; cout << endl;
#define D(x) // cout << #x << " = " << x << endl;

using namespace std;

int main() {
  long long tc; cin >> tc;

  while (tc--) {
    long long n; cin >> n;

    vector<long long> v;
    long long _sum = 0;

    for (long long i = 0; i < n; i++) {
      long long x; cin >> x;
      v.push_back(x);
      _sum += x;
    }

    DARR(v, n);

    vector<long long> suf_min(n);
    suf_min[n - 1] = v[n - 1];
    _sum -= suf_min[n - 1];

    for (long long i = n - 2; i >= 0; i--) {
      suf_min[i] = min(suf_min[i + 1], v[i]);
      _sum -= suf_min[i];
    }

    DARR(suf_min, n);

    long long mx = -1;
    long long cnt = 1;

    vector<long long> cnts(n);
    vector<long long> mxs(n);

    for (long long i = 1; i < n; i++) {
      cnts[i - 1] = cnt;

      if (suf_min[i] == suf_min[i - 1]) {
        cnt++;
      } else {
        mx = max(mx, cnt);
        cnt = 1;
      }

      mxs[i - 1] = mx;
    }

    mx = max(mx, cnt);

    DARR(cnts, n);
    DARR(mxs, n);

    D(_sum);
    D(mx);

    cout << _sum + mx - 1 << endl;
  }
}
