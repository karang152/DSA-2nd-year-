//https://leetcode.com/problems/top-k-frequent-elements/submissions/955244253/




class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freqMap;
        for (int num : nums) {
            freqMap[num]++;
        }
        
        vector<pair<int, int>> freqPairs;
        for (auto it = freqMap.begin(); it != freqMap.end(); ++it) {
            freqPairs.push_back({it->second, it->first});
        }
        
        sort(freqPairs.rbegin(), freqPairs.rend());
        
        vector<int> result;
        for (int i = 0; i < k; i++) {
            result.push_back(freqPairs[i].second);
        }
        
        return result;
    }
};
