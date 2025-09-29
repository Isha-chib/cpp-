#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minCoins(int n, int c, vector<int>& a) {
    sort(a.begin(), a.end());
    int min_cost = n;

    for (int k = 0; k <= n; ++k) {
        int cost = 0;
        // Destroy last k bags at the end
        for (int i = n - k; i < n; ++i) {
            int times_doubled = i - (n - k);
            long long weight = a[i];
            weight <<= times_doubled; // weight * 2^times_doubled
            if (weight > c) cost++;
        }
        // Destroy first n - k bags earlier
        for (int i = 0; i < n - k; ++i) {
            if (a[i] > c) cost++;
        }
        min_cost = min(min_cost, cost);
    }

    return min_cost;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, c;
        cin >> n >> c;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        cout << minCoins(n, c, a) << endl;
    }
    return 0;
}