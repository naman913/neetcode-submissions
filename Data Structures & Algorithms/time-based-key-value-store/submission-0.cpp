class TimeMap {
public:

    unordered_map<string,vector<pair<int,string>>>mapi;
    TimeMap() {
        mapi.clear();
    }
    
    void set(string key, string value, int timestamp) {
        mapi[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        if (mapi.find(key) == mapi.end()) return "";
        const vector<pair<int,string>>&arr=mapi[key];
        int start=0;
        int end=arr.size()-1;
        int ans=-1;
        while(start<=end){
            int mid=(start+end)/2;
            if(arr[mid].first<=timestamp){
                ans=mid;
                start=mid+1;
            }else{   
                end=mid-1;
            }
        }
        return ans == -1 ? "" : arr[ans].second;
    }
};
