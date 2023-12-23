// https://leetcode.com/problems/subsets-ii/ 

class Solution {
private:
    void subsetsWithDupHelper(vector<int>&nums, int idx, vector<int>subset,set<vector<int>>&subsets){

        if(idx == nums.size()){
            sort(subset.begin(),subset.end());
            subsets.insert(subset);
            return;
        }
        // pick nums[idx]
        subset.push_back(nums[idx]);
        subsetsWithDupHelper(nums,idx+1,subset,subsets);

        // not pick nums[idx]
        subset.pop_back();
        subsetsWithDupHelper(nums,idx+1,subset,subsets);

        return;
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int>subset;
        set<vector<int>>subsets;
        vector<vector<int>>res;

        subsetsWithDupHelper(nums,0,subset,subsets);

        for(auto it = subsets.begin(); it != subsets.end(); it++){
            res.push_back(* it);
        }

        return res;
    }
};
