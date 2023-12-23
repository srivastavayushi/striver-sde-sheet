// https://leetcode.com/problems/combination-sum/

class Solution {
private :
    void combinationSumHelper(int idx, int target, vector<int>& candidates, vector<int>&ds,vector<vector<int>>&res){

        if(idx >= candidates.size()){
            if(target == 0){
                for(auto it:ds) cout<<it<<" ";
                res.push_back(ds);
            }
            return;
        }
        
        // pick candidates[idx] and call the function again for same idx since same number can be chosen unlimited number of times with reduced target
        if(candidates[idx] <= target){
            ds.push_back(candidates[idx]);
            combinationSumHelper(idx,target - candidates[idx],candidates,ds,res);
            // remove the last used idx since it wont be used in not-pick
            ds.pop_back();
        }

        // not pick
        combinationSumHelper(idx+1,target,candidates,ds,res);

        return;
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>ds;
        vector<vector<int>>res;
        combinationSumHelper(0,target,candidates,ds,res);
        return res;
    }
};
