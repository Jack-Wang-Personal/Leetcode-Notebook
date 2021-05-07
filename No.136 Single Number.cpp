class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int sum=0;
        for(auto n:nums){
            sum^=n;
        }
        return sum;
    }
};