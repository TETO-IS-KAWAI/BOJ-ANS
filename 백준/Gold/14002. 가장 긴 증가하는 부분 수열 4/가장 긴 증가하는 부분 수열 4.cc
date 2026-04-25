#include <stdio.h>
#include <vector>
#include <algorithm>

int n;
int arr[1001], dp[1001], prev[1001];
std::vector<int> result;

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        dp[i] = 1;
        prev[i] = -1;
    }

    int maxLength = 1, lastIndex = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j] && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
                prev[i] = j;
            }
        }
        if (dp[i] > maxLength) {
            maxLength = dp[i];
            lastIndex = i;
        }
    }

    while (lastIndex != -1) {
        result.push_back(arr[lastIndex]);
        lastIndex = prev[lastIndex];
    }

    std::reverse(result.begin(), result.end());

    printf("%d\n", maxLength);
    for (int num : result) {
        printf("%d ", num);
    }
}