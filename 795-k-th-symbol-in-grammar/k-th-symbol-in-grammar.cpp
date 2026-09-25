class Solution {
public:
    int solve(int k,bool res) {
        if(k==1)
            return res?1:0;
        if(k%2==1){
            return solve(k/2+1,res);
        }else
            return solve(k/2,!res);
    }
    int kthGrammar(int n, int k) {
        bool res=false;
        return solve(k,res);
    }
};