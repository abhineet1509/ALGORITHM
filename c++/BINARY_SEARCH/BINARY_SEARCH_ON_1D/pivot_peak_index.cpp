#include <iostream>
#include <vector>
using namespace std;

// ----------------------
// Pivot Index Function
// ----------------------
// how many times the array has been rotated
int findPivotIndex(vector<int>& arr) {
    int low = 0, high = arr.size() - 1;

    while (low < high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] > arr[high]) {
            low = mid + 1;   
        } else {
            high = mid;     
        }
    }

    return low; 
}

// ----------------------
// Peak Element Function
// ----------------------
int findPeakElement(vector<int>& nums) {
    int low = 0, high = nums.size() - 1;

    while (low < high) {
        int mid = low + (high - low) / 2;

        if (nums[mid] < nums[mid + 1]) {
            low = mid + 1;   
        } else {
            high = mid;     
        }
    }

    return low; 
}

// ----------------------
// Main Function
// ----------------------
int main() {
    // For Pivot
    vector<int> rotated = {7, 8, 9, 1, 2, 3, 4, 5, 6};
    int pivot = findPivotIndex(rotated);
    cout << "Pivot index: " << pivot << ", Value: " << rotated[pivot] << endl;

    // For Peak
    vector<int> unsorted = {1, 3, 5, 4, 2, 6, 1};
    int peak = findPeakElement(unsorted);
    cout << "Peak index: " << peak << ", Value: " << unsorted[peak] << endl;

    return 0;
}
