class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()>nums2.size()) return findMedianSortedArrays(nums2,nums1);
        int m=nums1.size(),n=nums2.size();
        int left=0,right=m;
        int m1=0,m2=0;
        int k=(m+n+1)/2;

        while(left<=right){
            int i=(left+right)/2;
            int j=k-i;
            int n1_l=(i==0?INT_MIN:nums1[i-1]);
            int n1_r=(i==m?INT_MAX:nums1[i]);
            int n2_l=(j==0?INT_MIN:nums2[j-1]);
            int n2_r=(j==n?INT_MAX:nums2[j]);
            if(n1_l<=n2_r){
                m1=max(n1_l,n2_l);
                m2=min(n1_r,n2_r);
                left=i+1;
            }else{
                right=i-1;
            }

        }
        return (m+n)%2==0?(m1+m2)/2.0:m1;
    }
};