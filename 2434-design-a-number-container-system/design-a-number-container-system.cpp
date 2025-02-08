class NumberContainers {
public:
    NumberContainers() {}

    unordered_map<int, int> mp; // idx -> num
    set<pair<int, int>> st; // number, idx

    
    void change(int index, int number) {
        if(!mp.count(index)) {
            mp[index] = number;
            st.insert({number, index});
        } else {
            int cur_num = mp[index];
            mp[index] = number;
            st.erase({cur_num, index});
            st.insert({number, index});
        }
    }
    
    int find(int number) {
        auto it = st.lower_bound({number, -1});
        if(it != st.end() && it->first == number) return it->second;
        else return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */