class SmallestInfiniteSet {
    set<int> s;
    int curr;
public:
    SmallestInfiniteSet() {
        curr = 1;
    }
    void addBack(int num) {
        if(curr>num) s.insert(num);    
    }
    int popSmallest() {
        if(s.size()){
            int ele = *s.begin();
            s.erase(ele);
            return ele;
        }else{
            curr+=1;
            return curr-1;
        }
    }
    

};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */