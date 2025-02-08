class NumberContainers {
public:
    unordered_map<int,int> ind_map;
    unordered_map<int,set<int>> map;
    NumberContainers() {   
        ind_map.clear();
        map.clear();
    }
    
    void change(int index, int number) {
        if(ind_map[index]==number) return;
        map[number].insert(index);
        if(ind_map.find(index)!=ind_map.end()){
            int num = ind_map[index];
            map[num].erase(index);
            if(map[num].size()==0){
                map.erase(num);
            }
        }
        ind_map[index]=number;
    }
    
    int find(int number) {
        if(map.find(number)==map.end()){
            return -1;
        } 
        return *(map[number].begin());
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */