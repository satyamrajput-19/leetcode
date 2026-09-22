class Solution {
public:
    int calPoints(vector<string>& op) {
        stack<int> st;
        for(string ch : op){
            if(ch =="+") {
                int a=st.top();st.pop();
                int sum=a+st.top();
                st.push(a);
                st.push(sum);
            }else if(ch=="D"){
                st.push(st.top()*2);
            }else if(ch=="C"){
                st.pop();
            }else{
                st.push(stoi(ch));
            }
        }
        int sum=0;
        while(!st.empty()){
            sum += st.top();st.pop();
        }
        return sum;
    }
};