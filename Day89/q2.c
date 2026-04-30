#include <stdio.h>

int isPossible(int arr[], int n, int days, int capacity) {
    int requiredDays = 1;
    int load = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] > capacity)
            return 0;

        if (load + arr[i] <= capacity) {
            load += arr[i];
        } else {
            requiredDays++;
            load = arr[i];

            if (requiredDays > days)
                return 0;
        }
    }
    return 1;
}

int minCapacity(int arr[], int n, int days) {
    int sum = 0, max = 0;

    for (int i = 0; i < n; i++) {
        sum += arr[i];
        if (arr[i] > max)
            max = arr[i];
    }

    int low = max, high = sum, ans = sum;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (isPossible(arr, n, days, mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return ans;
}

int main() {
    int n, days;
    scanf("%d %d", &n, &days);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("%d\n", minCapacity(arr, n, days));

    return 0;
}