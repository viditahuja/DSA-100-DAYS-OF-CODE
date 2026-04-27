#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int low = 0, high = n, ans = 0;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (mid * mid == n) {
            ans = mid;
            break;
        } else if (mid * mid < n) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    printf("%d", ans);
    return 0;
}