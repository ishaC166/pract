#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cout << "Enter number of files: ";
    cin >> n;

    vector<int> files(n);    //files is name of arr?

    cout << "Enter file sizes:\n";
    for(int i = 0; i < n; i++)
        cin >> files[i];

    // Greedy step: sort in ascending order
    sort(files.begin(), files.end());

    cout << "Optimal order of files:\n";
    for(int f : files)
        cout << f << " ";
    cout << endl;

    // Calculate Mean Retrieval Time
    int totalTime = 0, sum = 0;

    for(int i = 0; i < n; i++) {
        sum += files[i];      // cumulative sum
        totalTime += sum;     // add to total retrieval time
    }

    double mrt = (double) totalTime / n;

    cout << "Mean Retrieval Time = " << mrt << endl;

    return 0;
}