#include <iostream>
#include <algorithm>
using namespace std;
 
const int MAX_N = 200005; 
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n, q;
        cin >> n >> q;
        static int a[MAX_N], b[MAX_N];
        static int max_val[MAX_N];
        static long long prefix[MAX_N + 1];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
        for (int i = 0; i < n; i++) 
            cin >> b[i];
        int current_max = 0;
        for (int i = n - 1; i >= 0; i--) {
            current_max = max(current_max, max(a[i], b[i]));
            max_val[i] = current_max;
        }
        prefix[0] = 0;
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + max_val[i];
        }
        for (int i = 0; i < q; i++) {
            int l, r;
            cin >> l >> r;
            long long sum = prefix[r] - prefix[l - 1];
            cout << sum;
            if (i < q - 1) 
                cout << ' ';
            else 
                cout << '\n';
        }
    }
    
    return 0;
}