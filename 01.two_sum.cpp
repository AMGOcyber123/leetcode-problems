class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> store;
        unordered_map<int,int> s;
        for(int i = 0; i < n; i++)
        {
            /*
                -> create a hashmap to store 
                -> nums[i] = complement or target - nums[i];
                -> store initial index 
                -> find if complement present in array
                -> yes , store its index and current i 's  index
                -> return   
            */
            int complement = target-nums[i];
            if(s.find(complement) != s.end())
            {
                store.push_back(s[complement]);
                store.push_back(i);
                return store;
            }
            s[nums[i]] = i;
        }
        return store;
    }
};