#include <iostream>
#include <vector>

const int MAX = 200005;

int main() {
    int n, k, q;
    std::cin >> n >> k >> q;

    std::vector<int> diff(MAX, 0);
    std::vector<int> admissible(MAX, 0);
    std::vector<int> pref(MAX, 0);

    for (int i = 0; i < n; i++) {
        int l, r;
        std::cin >> l >> r;
        diff[l]++;
        diff[r + 1]--;
    }

    int count = 0;
    for (int i = 0; i < MAX; i++) {
        count += diff[i];
        if (count >= k) {
            admissible[i] = 1;
        } else {
            admissible[i] = 0;
        }
    }

    pref[0] = admissible[0];
    for (int i = 1; i < MAX; i++) {
        pref[i] = pref[i - 1] + admissible[i];
    }

    for (int i = 0; i < q; i++) {
        int a, b;
        std::cin >> a >> b;
        int ans = (a == 0) ? pref[b] : pref[b] - pref[a - 1];
        std::cout << ans << std::endl;
    }

    return 0;
}