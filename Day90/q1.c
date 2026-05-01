#include <stdio.h>

int isPossible(int arr[], int n, int k, int maxTime) {
    int painters = 1, total = 0;

    for (int i = 0; i < n; i++) {
        total += arr[i];

        if (total > maxTime) {
            painters++;
            total = arr[i];

            if (painters > k)
                return 0;
        }
    }
    return 1;
}

int painterPartition(int arr[], int n, int k) {
    int low = arr[0], high = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] > low)
            low = arr[i];
        high += arr[i];
    }

    int ans = high;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (isPossible(arr, n, k, mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("%d", painterPartition(arr, n, k));

    return 0;
}