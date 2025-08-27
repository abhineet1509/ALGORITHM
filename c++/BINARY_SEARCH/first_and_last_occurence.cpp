#include <iostream>
#include <vector>
using namespace std;

int findFirstOccurrence(const vector<int>& arr, int target) {
    int low = 0, high = arr.size() - 1;
    int mid, index = -1;

    while (low <= high) {
        mid = low + (high - low) / 2;

        if (arr[mid] == target) {
            index = mid;
            break;
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    if (index == -1) return -1;

    while (index > 0 && arr[index - 1] == target) {
        index--;
    }

    return index;
}

int findLastOccurrence(const vector<int>& arr, int target) {
    int low = 0, high = arr.size() - 1;
    int mid, index = -1;

    while (low <= high) {
        mid = low + (high - low) / 2;

        if (arr[mid] == target) {
            index = mid;
            break;
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    if (index == -1) return -1;

    while (index < arr.size() - 1 && arr[index + 1] == target) {
        index++;
    }

    return index;
}

int main() {
    vector<int> arr = {1, 2, 5, 5, 5, 6, 7, 8};
    int target = 5;

    int first = findFirstOccurrence(arr, target);
    int last = findLastOccurrence(arr, target);

    if (first == -1) {
        cout << "Target not found.\n";
    } else {
        cout << "First occurrence: " << first << endl;
        cout << "Last occurrence: " << last << endl;
    }

    return 0;
}
