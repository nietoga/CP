#include<iostream>
#include<vector>

using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;

        vector<int> v(n);
        for (int i = 0; i < n; i++) cin >> v[i];

        long long base = 0;
        int cur_min = INT_MAX;
        long long gain = 0, cur_gain = 0;

        for (int i = n-1; i >= 0; i--) {
            if (v[i] < cur_min) {
                cur_min = v[i];
                cur_gain = 0;
            }
            else {
                base += v[i] - cur_min;
                gain = max(gain, ++cur_gain);
            }
        }

        cout << base + gain << "\n";
    }

    return 0;
}