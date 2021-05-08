class Solution {
public:
    void dfs(vector<string>& res,string &s,int open,int close,int n){
        if(close+open==n*2){
            res.push_back(s);
            return;
        }
        if(open<n){
            s.push_back('(');
            dfs(res,s,open+1,close,n);
            s.pop_back();
        }
        if(open>close){
            s.push_back(')');
            dfs(res,s,open,close+1,n);
            s.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string s;
        dfs(res,s,0,0,n);
        return res;
    }
};
