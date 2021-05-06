class Solution {
public:
    void swap(vector<int>& nums,int a,int b){
        int temp=nums[a];
        nums[a]=nums[b];
        nums[b]=temp;
    }
    void backtrack(vector<int>& nums, vector<vector<int>>& res, int n,int index){
        if(n-1==index) res.push_back(nums);
        for(int i=index;i<n;i++){
            swap(nums,index,i);
            backtrack(nums,res,n,index+1);
            swap(nums,i,index);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> res;
        backtrack(nums,res,n,0);
        return res;
    }
};