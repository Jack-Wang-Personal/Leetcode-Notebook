class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        if(nums.size()<3) return res;
        sort(nums.begin(),nums.end());
        
        for(int one=0;one<nums.size()-2;one++){
            if(one>0 && nums[one]==nums[one-1]) continue;
            int target=-nums[one];
            int left=one+1;
            int right=nums.size()-1;
            while(left<right){
                if(left>one+1 && nums[left]==nums[left-1]) {left++; continue;}
                if(right<nums.size()-1 && nums[right]==nums[right+1]) {right--; continue;}
                if(target>nums[left]+nums[right]){
                    left++;
                }else if(target<nums[left]+nums[right]){
                    right--;
                }else{
                    res.push_back({nums[one],nums[left],nums[right]});
                    left++;
                }

            }
        }
        return res;
    }
};