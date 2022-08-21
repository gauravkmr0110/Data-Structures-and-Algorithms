class RandomizedCollection {
    unordered_map<int,unordered_set<int>>mp;
    vector<int>nums;
public:
    RandomizedCollection() {
        
    }
    
    bool insert(int val) {
        bool flag = false;
        if(mp[val].size()==0)flag = true;
        nums.push_back(val);
        mp[val].insert(nums.size()-1);
        return flag;
    }
    
    bool remove(int val) {
        if(mp[val].size()==0)return false;
        int it = *mp[val].begin();
        // swap with end element in vector
        int m = nums.size()-1;
        int key = nums.back();
        if(key==val){
            nums.pop_back();
            mp[val].erase(m);
            return true;
        }
        mp[key].erase(m);
        mp[key].insert(it);
        mp[val].erase(it);
        nums[it]=key;
        nums.pop_back();
        cout<<mp[val].size()<<" ";
        return true;
        
    }
    
    int getRandom() {
        long long r1 = rand();
        long long random = r1;
        random = random%nums.size();
        return nums[random];
    }
};
