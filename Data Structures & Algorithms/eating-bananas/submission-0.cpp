class Solution {
public:

    int calculateTime(int mid,vector<int>& piles){
        int total_time=0;
        for(int i=0;i<piles.size();i++){
            total_time=total_time+(piles[i]/mid);
            if(piles[i]%mid!=0)
                total_time+=1;
        }
        return total_time;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        long long end=0;
        for(int i:piles)
            end+=i;
        long long start=1;
        int ans=-1;
        while(start<=end){
            long long mid=(start+end)/2;
            int time=calculateTime(mid,piles);
            cout<<time;
            if(time<=h){
                ans=mid;
                end=mid-1;
            }else{
                start=mid+1;
            }
        }
        return ans;
    }
};
