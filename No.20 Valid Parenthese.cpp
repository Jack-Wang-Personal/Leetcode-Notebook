class Solution {
public:
    bool isValid(string s) {
        if(s.size()%2!=0) return false;
        stack<char> stk;
        unordered_map<char,char> mp;
        mp[')']='(';
        mp['}']='{';
        mp[']']='[';
        for(auto c:s){
            if(mp.count(c)==0){
                stk.push(c);
            }else{
                if(stk.empty() || mp[c]!=stk.top()) return false;
                stk.pop();
            }
        }
        if(!stk.empty()) return false;
        return true;
    }
};