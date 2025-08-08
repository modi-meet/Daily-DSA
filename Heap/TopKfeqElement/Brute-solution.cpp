#include <bits/stdc++.h>
using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k) {
    vector<int> result;
    set<int> uniqueNums(nums.begin(), nums.end());

    vector<pair<int,int>> freqList;
    for (int val : uniqueNums) {
        int countFreq = count(nums.begin(), nums.end(), val);
        freqList.push_back({countFreq, val});
    }

    sort(freqList.rbegin(), freqList.rend());
    for (int i = 0; i < k; i++)
        result.push_back(freqList[i].second);
    return result;
}

int main() {
    vector<int> nums = {1,1,1,2,2,3};
    int k = 2;
    auto ans = topKFrequent(nums, k);
    for (int x : ans) cout << x << " ";
}
