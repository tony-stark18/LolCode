class Solution {
public:
    int modify(int num,int digMap[]){
        if(num==0) return digMap[0];
        int ans = 0;
        stack<int> st;
        while(num>0){
            st.push(num%10);
            num = num/10;
        }
        while(!st.empty()){
            ans = ans*10+digMap[st.top()];
            st.pop();
        }
        return ans;
    }
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        int digMap[10];
        for(int i=0;i<10;i++){
            digMap[i]=mapping[i];
        }
        vector<pair<int,int>> res;
        for(int num:nums){
            res.push_back({modify(num,digMap),num});
        }
        sort(res.begin(),res.end(),[](const pair<int,int>& p1,const pair<int,int>& p2){
            if(p1.first==p2.first) return false;
            return p1.first<p2.first;
        });
        vector<int> ans;
        for(auto i:res){
            ans.push_back(i.second);
        }
        return ans;
    }
};