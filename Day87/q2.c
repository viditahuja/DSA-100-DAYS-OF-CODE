#include <stdio.h>

int max(int arr[], int n) {
    int m = arr[0];
    for(int i = 1; i < n; i++) {
        if(arr[i] > m)
            m = arr[i];
    }
    return m;
}

long long hoursNeeded(int arr[], int n, int k) {
    long long hours = 0;
    for(int i = 0; i < n; i++) {
        hours += (arr[i] + k - 1) / k;
    }
    return hours;
}

int main() {
    int n;
    scanf("%d", &n);

    int piles[n];
    for(int i = 0; i < n; i++)
        scanf("%d", &piles[i]);

    int h;
    scanf("%d", &h);

    int low = 1, high = max(piles, n);
    int ans = high;

    while(low <= high) {
        int mid = (low + high) / 2;

        if(hoursNeeded(piles, n, mid) <= h) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    printf("%d", ans);
    return 0;
}