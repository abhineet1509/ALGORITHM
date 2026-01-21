#include <bits/stdc++.h>
using namespace std;

/* ---------------- Top K Frequent Elements ---------------- */
vector<int> topKFrequentElements(vector<int>& nums, int k) {
    unordered_map<int,int> freq;
    for(int i = 0; i < nums.size(); i++)
        freq[nums[i]]++;

    // Min-heap: pair<frequency, number>
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    for(unordered_map<int,int>::iterator it = freq.begin(); it != freq.end(); ++it) {
        pq.push({it->second, it->first});
        if(pq.size() > k) pq.pop();
    }

    vector<int> res;
    while(!pq.empty()) {
        res.push_back(pq.top().second);
        pq.pop();
    }
    reverse(res.begin(), res.end());
    return res;
}

/* ---------------- Top K Frequent Words ---------------- */
vector<string> topKFrequentWords(vector<string>& words, int k) {
    unordered_map<string,int> freq;
    for(int i = 0; i < words.size(); i++)
        freq[words[i]]++;

    // Min-heap: custom comparator
    auto cmp = [](pair<int,string> a, pair<int,string> b) {
        if(a.first == b.first) return a.second < b.second; // reverse lex
        return a.first > b.first; // min-heap
    };
    priority_queue<pair<int,string>, vector<pair<int,string>>, decltype(cmp)> pq(cmp);

    for(unordered_map<string,int>::iterator it = freq.begin(); it != freq.end(); ++it) {
        pq.push({it->second, it->first});
        if(pq.size() > k) pq.pop();
    }

    vector<string> res;
    while(!pq.empty()) {
        res.push_back(pq.top().second);
        pq.pop();
    }
    reverse(res.begin(), res.end());
    return res;
}

/* ---------------- Main Program ---------------- */
int main() {
    // Top K Frequent Elements
    vector<int> nums = {1,1,1,2,2,3};
    int k1 = 2;
    vector<int> ans1 = topKFrequentElements(nums, k1);
    cout << "Top " << k1 << " Frequent Elements: ";
    for(int i = 0; i < ans1.size(); i++) cout << ans1[i] << " ";
    cout << endl;

    // Top K Frequent Words
    vector<string> words = {"i","love","leetcode","i","love","coding"};
    int k2 = 2;
    vector<string> ans2 = topKFrequentWords(words, k2);
    cout << "Top " << k2 << " Frequent Words: ";
    for(int i = 0; i < ans2.size(); i++) cout << ans2[i] << " ";
    cout << endl;

    return 0;
}
