class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        map<int,int> mpp;
        int n = nums.size();
        for(int x : nums)
        {
            mpp[x]++;
        }
        vector<int> ans;
        for( auto it : mpp)
        {
            if(it.second % 2 == 1)
            ans.push_back(it.first);
        }

        sort(ans.rbegin(), ans.rend());

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna