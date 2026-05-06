#include <iostream>
#include <vector>
using namespace std;

pair<int, int> findMinMax(vector<int>& arr, int low, int high) {
    
    // Base case: only one element
    if (low == high) {
        return {arr[low], arr[low]};
    }

    // Base case: two elements
    if (high == low + 1) {
        if (arr[low] < arr[high])
            return {arr[low], arr[high]};
        else
            return {arr[high], arr[low]};
    }

    
    // Divide
    int mid = (low + high) / 2;
    auto left = findMinMax(arr, low, mid);
    auto right = findMinMax(arr, mid + 1, high);

    // Conquer (combine results)
    int minimum = min(left.first, right.first);
    int maximum = max(left.second, right.second);

    return {minimum, maximum};
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    auto result = findMinMax(arr, 0, n - 1);

    cout << "Minimum = " << result.first << endl;
    cout << "Maximum = " << result.second << endl;

    return 0;
}