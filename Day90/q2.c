#include <stdio.h>

int isPossible(int arr[], int n, int k, int maxSum) {
    int count = 1, sum = 0;

    for (int i = 0; i < n; i++) {
        sum += arr[i];

        if (sum > maxSum) {
            count++;
            sum = arr[i];

            if (count > k)
                return 0;
        }
    }
    return 1;
}

int splitArray(int arr[], int n, int k) {
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
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    scanf("%d", &k);

    printf("%d", splitArray(arr, n, k));

    return 0;
}