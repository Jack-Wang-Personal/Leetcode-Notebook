class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int maxL=0;
        vector<int> maxLeft(n);
        for(int i=0;i<n;i++){
            maxL=max(maxL,height[i]);
            maxLeft[i]=maxL;
        }
        int maxR=0;
        vector<int> maxRight(n);
        for(int i=n-1;i>=0;i--){
            maxR=max(maxR,height[i]);
            maxRight[i]=maxR;
        }
        int v=0;
        for(int i=0;i<n;i++){
            v+=(min(maxLeft[i],maxRight[i])-height[i]);
        }
        return v;
    }
};