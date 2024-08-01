// Time Complexity: O(N)
// Space Complexity: O(1)
class LRUCache {
private:
    class node{
        public:
        int key,val;
        node* next;
        node* prev;
        node(int _key, int _val){
            key = _key;
            val = _val;
        }
    };
    unordered_map<int, node*> mp;
    int cap;
    node* head = new node(-1,-1);
    node* tail = new node(-1,-1);

public:
    LRUCache(int capacity) {
        cap = capacity;
        head -> next = tail;
        tail -> prev = head;
    }

    void addfront(node* newnode){
        node* temp = head -> next;
        newnode -> next = temp;
        newnode -> prev = head;
        head -> next = newnode;
        temp -> prev = newnode;
    }

    void deletenode(node* delnode){
        node* delprev = delnode -> prev;
        node* delnext = delnode -> next;
        delprev -> next = delnext;
        delnext -> prev = delprev;
    }
    
    int get(int key) {
        if(mp.find(key) != mp.end()){
            node* temp = mp[key];
            int ans = temp ->val;
            mp.erase(key);
            deletenode(temp);
            addfront(temp);
            mp[key] = head -> next;
            return ans;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
            node* temp = mp[key];
            mp.erase(key);
            deletenode(temp);
        }
        else if(mp.size()==cap){
            mp.erase(tail->prev->key);
            deletenode(tail->prev);
        }
        addfront(new node(key,value));
        mp[key] = head -> next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */