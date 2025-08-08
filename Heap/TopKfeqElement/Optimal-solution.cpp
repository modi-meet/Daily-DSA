#include <bits/stdc++.h>
using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int,int> freq;
    for (int num : nums) freq[num]++;

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> minHeap;
    for (auto &p : freq) {
        minHeap.push({p.second, p.first});
        if ((int)minHeap.size() > k)
            minHeap.pop();
    }

    vector<int> result;
    while (!minHeap.empty()) {
        result.push_back(minHeap.top().second);
        minHeap.pop();
    }
    reverse(result.begin(), result.end());
    return result;
}

int main() {
    vector<int> nums = {1,1,1,2,2,3};
    int k = 2;
    auto ans = topKFrequent(nums, k);
    for (int x : ans) cout << x << " ";
}
