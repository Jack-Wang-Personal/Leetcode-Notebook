class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<int> res(T.size(),0);
        stack<int> stk;
        for(int i=0;i<T.size();i++){
            while(!stk.empty() && T[i]>T[stk.top()]){
                res[stk.top()]=i-stk.top();
                stk.pop();
            }
            stk.push(i);
            
        }
        return res;
    }
};
