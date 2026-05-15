class TimeMap {
    unordered_map<string,vector<pair<string,int>>> hash;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        hash[key].push_back({value,timestamp});
        return;
    }
    
    string get(string key, int timestamp) {
        if(!hash.count(key)) return "";
        int l=0,r=hash[key].size()-1;
        while((r-l)>1){
            int mid=l+(r-l)/2;
            if(hash[key][mid].second==timestamp) return hash[key][mid].first;
            else if(hash[key][mid].second>timestamp) r=mid-1;
            else l=mid;
        }
        if(hash[key][r].second<=timestamp) return hash[key][r].first;
        else if(hash[key][l].second<=timestamp) return hash[key][l].first;
        else return "";
    }
};
