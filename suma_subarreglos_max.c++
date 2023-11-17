#include <iostream>
#include <climits>
#include <vector>

using namespace std;

int maxSubarraySum(const vector<int>& arr, int start, int end) {
    if (start == end) {
        return arr[start];
    }

    int mid = (start + end) / 2;

    int leftMax = INT_MIN;
    int currentSum = 0;
    for (int i = mid; i >= start; --i) {
        currentSum += arr[i];
        leftMax = max(leftMax, currentSum);
    }

    int rightMax = INT_MIN;
    currentSum = 0;
    for (int i = mid + 1; i <= end; ++i) {
        currentSum += arr[i];
        rightMax = max(rightMax, currentSum);
    }

    int crossMax = leftMax + rightMax;

    int maxLeft = maxSubarraySum(arr, start, mid);
    int maxRight = maxSubarraySum(arr, mid + 1, end);

    return max(max(crossMax, maxLeft), maxRight);
}

int findMaxSubarraySum(const vector<int>& arr) {
    int n = arr.size();
    int maxSum = INT_MIN;

    for (int groupSize = 2; groupSize <= n; ++groupSize) {
        cout << "En grupos de " << groupSize << ":" << endl;

        for (int i = 0; i <= n - groupSize; ++i) {
            int j = i + groupSize - 1;
            int sum = maxSubarraySum(arr, i, j);

            // mostrar el resultado de la suma del subarreglo
            for (int k = i; k <= j; ++k) {
                cout << arr[k];
                if (k < j) {
                    cout << " + ";
                }
            }

            cout << " = " << sum << endl;

            // actualizar la suma máxima
            maxSum = max(maxSum, sum);
        }

        cout << endl;
    }

    return maxSum;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6};

    int result = findMaxSubarraySum(arr);

    cout << "\nLa suma máxima es: " << result << endl;

    return 0;
}
