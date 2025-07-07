class RandomizedSet {
public:
unordered_map<int,int>m;
vector<int>v;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(m.find(val)!=m.end())
        {
            return false;
        }
        else
        {
            v.push_back(val);
            m[val]=v.size()-1;
            return true;
        }
    }
    
    bool remove(int val) {
        auto it=m.find(val);  
        // it->first h key(element) and it->second h value(index)
        if(it!=m.end())
        {
            swap(v[it->second],v[v.size()-1]);
            v.pop_back();
            m[v[it->second]]=it->second;  // updating  the index on un_map of swaped element
            m.erase(val); // erasing val element from un_map that was deleted in vector
            return true;
        }
        else
        {
            return false;
        }

        
    }
    
    int getRandom() {
        return v[rand()%v.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */