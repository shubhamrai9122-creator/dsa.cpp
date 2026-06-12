class Solution {
  public:
    vector<int> calculateSpan(vector<int>& v) {
        // code here
        stack<int>st;
        int n= v.size();
        vector<int>ans(n);
        for(int i=0;i<n;i++){
            while(!st.empty() && v[st.top()]<=v[i]){
                st.pop();
            }
            if(st.empty()){
                ans[i]= i+1;
            }
            else{
                ans[i]=i-st.top();
            }
            st.push(i);
        }
        return ans;
        
    }
};