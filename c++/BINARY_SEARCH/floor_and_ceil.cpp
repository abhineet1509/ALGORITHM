#include <iostream>
#include <vector>
using namespace std;

int findFloor(const vector<int>& arr, int target) {
    int low = 0, high = arr.size() - 1;
    int floorVal = -1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == target)
            return arr[mid]; // exact match is floor
        else if (arr[mid] < target) {
            floorVal = arr[mid]; // candidate
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return floorVal;
}

int findCeil(const vector<int>& arr, int target) {
    int low = 0, high = arr.size() - 1;
    int ceilVal = -1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == target)
            return arr[mid]; // exact match is ceil
        else if (arr[mid] > target) {
            ceilVal = arr[mid]; // candidate
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return ceilVal;
}

int main() {
    vector<int> arr = {1, 2, 4, 6, 10, 12};
    int target;
    cout << "Enter target: ";
    cin >> target;

    int floorVal = findFloor(arr, target);
    int ceilVal = findCeil(arr, target);

    cout << "Floor: ";
    if (floorVal != -1)
        cout << floorVal << endl;
    else
        cout << "No floor found\n";

    cout << "Ceil: ";
    if (ceilVal != -1)
        cout << ceilVal << endl;
    else
        cout << "No ceil found\n";

    return 0;
}
