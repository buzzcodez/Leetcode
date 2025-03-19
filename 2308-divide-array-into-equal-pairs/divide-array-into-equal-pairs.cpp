class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int, int> freq;
        for(int x : nums)
            freq[x]++;
        for(auto x : freq)
            if(x.second % 2)
                return false;
        return true;
    }
};