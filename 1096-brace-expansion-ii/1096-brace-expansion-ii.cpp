class Solution {
pair<set<string>,int> solve(string& expr, int pos){
    set<string> global , local;
    int len = expr.size();
    for (int i=pos;i<len;i++){
        string exp ="";
        while (i<len and expr[i]!='{' and expr[i]!='}' and expr[i]!=',')exp+=expr[i++];
        if (exp.size()>0){
            if (local.empty())local.insert("");
            set<string> temp;
            for (auto p:local)temp.insert(p+exp);
            local.clear();
            for (auto p:temp)local.insert(p);
            temp.clear();
        }
        if (expr[i] == '{'){
            auto [new_set,new_i] = solve(expr,i+1);
            set<string> temp;
            if (local.empty())local.insert("");
            for (auto p:local){
                for (auto q:new_set)temp.insert(p+q);
            }
            local.clear();
            for (auto p:temp)local.insert(p);
            temp.clear();
            i = new_i;
        }
        else if (expr[i] == ',' or expr[i]=='}'){
            for (auto p:local)global.insert(p);
            local.clear();
            if (expr[i] == '}')return {global,i};
        }
    }
    for (auto p:local)global.insert(p);
    local.clear();
    return {global,len};
}
public:
    vector<string> braceExpansionII(string expr) {
        vector<string> ans ;
        set<string> temp = solve(expr,0).first;
        for (auto st:temp)ans.push_back(st);
        return ans ; 
    }
};