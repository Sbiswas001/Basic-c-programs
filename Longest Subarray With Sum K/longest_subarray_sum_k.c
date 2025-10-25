#include <stdio.h>

int longestSubarrayWithSumK(int a[], long long k, int n) {
    int l = 0, r = 0;
    long long sum = 0;
    int ans = 0;

    while (r < n) {
        sum += a[r];

        while (l <= r && sum > k) {
            sum -= a[l];
            l++;
        }

        if (sum == k) {
            int length = r - l + 1;
            if (length > ans) {
                ans = length;
            }
        }

        r++;
    }

    return ans;
}

int main() {
    int n;
    long long k;
    scanf("%d %lld", &n, &k);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("%d\n", longestSubarrayWithSumK(arr, k, n));
    return 0;
}
