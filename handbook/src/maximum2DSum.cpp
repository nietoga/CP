const int MAXN = 105;
const int INF = 1 << 30;
int n;
int arr[MAXN][MAXN];

int
main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
            if (i > 0) arr[i][j] += arr[i-1][j];
            if (j > 0) arr[i][j] += arr[i][j-1];
            if (i > 0 && j > 0) arr[i][j] -= arr[i-1][j-1];
        }   
    }
    int maxi = -1*INF;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = i; k < n; k++) {
                for (int l = j; l < n; l++) {
                    int sub = arr[k][l];
                    if (i > 0) sub -= arr[i-1][l];
                    if (j > 0) sub -= arr[k][j-1];
                    if (i > 0 && j > 0) sub += arr[i-1][j-1];
                    maxi = max(maxi, sub);
                }   
            }   
        }   
    }
    cout << maxi << endl;
    return 0;
}