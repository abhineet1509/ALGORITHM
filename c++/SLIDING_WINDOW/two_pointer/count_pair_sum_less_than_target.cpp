#include <bits/stdc++.h>
using namespace std;


int countPairs(vector<int> &arr, int target) {
    sort(arr.begin(), arr.end());
    int i = 0, j = arr.size() - 1;
    int count = 0;

    while (i < j) {
        if (arr[i] + arr[j] < target) {
            count += (j - i);
            i++; 
        } else {
            j--;  
        }
    }
    return count;
}


int main() {
    vector<int> arr = {1, 3, 2, 5, 4};
    int target = 7;
    
    cout << "Array: ";
    for (int x : arr) cout << x << " ";
    cout << "\nTarget: " << target << endl;
    
    // Sort to show sorted array
    vector<int> sorted = arr;
    sort(sorted.begin(), sorted.end());
    cout << "Sorted: ";
    for (int x : sorted) cout << x << " ";
    cout << "\n\n";
    
    int result = countPairs(arr, target);
    cout << "Count of pairs with sum < " << target << " = " << result << endl;
    
   
    cout << "\nValid pairs:\n";
    sorted = arr;
    sort(sorted.begin(), sorted.end());
    int pairs = 0;
    for (int i = 0; i < sorted.size(); i++) {
        for (int j = i + 1; j < sorted.size(); j++) {
            if (sorted[i] + sorted[j] < target) {
                cout << "  (" << sorted[i] << ", " << sorted[j] << ") = " 
                     << sorted[i] + sorted[j] << " < " << target << endl;
                pairs++;
            }
        }
    }
    cout << "\nTotal pairs verified: " << pairs << endl;
    
    return 0;
}
