// Question : https://practice.geeksforgeeks.org/problems/subset-sums2234/1

class Solution
{
private:
    // Recurrsive function : gives 2 conditions : in one arr[idx] is included inside subset vector
    // and in the other arr[idx] is not added in subset vector
    void subsetSumsHelper(vector<int>&arr, int idx,vector<int>&subset, vector<int>&res){
        // Base condition : if idx >= arr.size() that means index is out of bounds
        if(idx >=arr.size()){
            int sum = 0;
            for(auto it : subset) sum+=it;
            res.push_back(sum);
            return;
        }
        
        // push the current arr[idx] in subset
        subset.push_back(arr[idx]);
        subsetSumsHelper(arr,idx+1,subset,res);
        
        // pop the last added element from subset
        subset.pop_back();
        subsetSumsHelper(arr,idx+1,subset,res);
        
        return;
    }
public:
    vector<int> subsetSums(vector<int> arr, int N)
    {
        vector<int>subset,res;
        subsetSumsHelper(arr,0,subset,res);
        sort(res.begin(),res.begin()+res.size());
        return res;
    }
};