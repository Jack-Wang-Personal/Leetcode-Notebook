class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size()==0) return {};
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> merge;
        for(int i=0;i<intervals.size();i++){
            int l=intervals[i][0];
            int r=intervals[i][1];
            if(merge.size()==0 || merge.back()[1]<l){
                merge.push_back({l,r});

            }else{
                merge.back()[1]=max(r,merge.back()[1]);
            }
        }
        return merge;
    }
};
