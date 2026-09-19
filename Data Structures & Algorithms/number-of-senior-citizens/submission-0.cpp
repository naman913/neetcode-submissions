class Solution {
public:
    int countSeniors(vector<string>& details) {
        int cnt=0;
        for(string str:details){
            int k=0;
            for(int i=11;i<=12;i++){
                k=k*10+str[i]-'0';
            }
            if(k>60)
                cnt++;
        }
        return cnt;
        
    }
};