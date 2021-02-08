class RandomizedSet {
public:
    unordered_map<int,int> m1;
    int s;
     vector<int> v;
    /** Initialize your data structure here. */
    RandomizedSet() {

        m1.clear();
        v.clear();
        s=0;

    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {

       if(m1[val]==0)
        {
            m1[val]=s+1;
            s++;
            v.push_back(val);
            return true;
        }
        return false;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {

       if(m1[val]!=0)
        {
            m1[v[s-1]]=m1[val];
            swap(v[m1[val]-1],v[s-1]);
            s--;
            v.pop_back();
            m1[val]=0;
            return true;
        }
        return false;
    }

    /** Get a random element from the set. */
    int getRandom() {

        int r=rand()%s;
        return v[r];

    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
