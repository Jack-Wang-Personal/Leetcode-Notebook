class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int tempsum=0,maxsum=nums[0];
        for(int i=0;i<nums.size();i++){
            tempsum+=nums[i];
            maxsum=max(tempsum,maxsum);
            if(tempsum<=0){
                tempsum=0;
            }
            
        }
        return maxsum;
    }
};