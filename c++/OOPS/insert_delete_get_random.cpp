#include <bits/stdc++.h>
using namespace std;

class RandomizedSet {
private:
    vector<int> nums;
    unordered_map<int, int> valToIndex;
    mt19937 rng; // random number generator

public:
    RandomizedSet() {
        rng = mt19937(random_device{}());
    }

    bool insert(int val) {
        if (valToIndex.count(val)) return false;
        nums.push_back(val);
        valToIndex[val] = nums.size() - 1;
        return true;
    }

    bool remove(int val) {
        if (!valToIndex.count(val)) return false;
        int index = valToIndex[val];
        int lastVal = nums.back();
        nums[index] = lastVal;
        valToIndex[lastVal] = index;
        nums.pop_back();
        valToIndex.erase(val);
        return true;
    }

    int getRandom() {
        uniform_int_distribution<int> dist(0, nums.size() - 1);
        return nums[dist(rng)];
    }
};

int main() {
    RandomizedSet rs;
    cout << rs.insert(1) << endl;    // true
    cout << rs.remove(2) << endl;    // false
    cout << rs.insert(2) << endl;    // true
    cout << rs.getRandom() << endl;  // 1 or 2
    cout << rs.remove(1) << endl;    // true
    cout << rs.insert(2) << endl;    // false
    cout << rs.getRandom() << endl;  // 2
    return 0;
}
