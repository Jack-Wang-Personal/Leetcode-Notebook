class Solution {
public:
    int getlen(string& s, int n, int m){
        while(n>=0 && m<s.size() && s[n]==s[m]){
            n--;
            m++;
        }
        return m-n-1;
    }
    string longestPalindrome(string s) {
        int left=0,len;
        int maxlen=0;
        for(int i=0;i<s.size();i++){
            len=getlen(s,i,i);
            if(len>maxlen){
                maxlen=len;
                left=i-len/2;
            }
            len=getlen(s,i,i+1);
            if(len>maxlen){//
                maxlen=len;
                left=i+1-len/2;
            }
        }
        return s.substr(left,maxlen);
    }
};