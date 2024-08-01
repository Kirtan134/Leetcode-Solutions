class LFUCache {
private:
    class node{
    public:
        int key,val,cnt;
        node* next;
        node* prev;
        node(int _key, int _val){
            key = _key;
            val = _val;
            cnt=1;
        }
    };

    class List{
    public:
        int size;
        node* head;
        node* tail;
        List(){
            head = new node(-1,-1);
            tail = new node(-1,-1);
            head->next=tail;
            tail->prev=head;
            size=0;
        }
    
        void addFront(node* newnode){
            node* temp = head -> next;
            newnode -> next = temp;
            newnode -> prev = head;
            head -> next = newnode;
            temp -> prev = newnode;
            size++;
        }
    
        void deleteNode(node* delnode){
            node* delprev = delnode -> prev;
            node* delnext = delnode -> next;
            delprev -> next = delnext;
            delnext -> prev = delprev;
            size--;
        } 
    };    
    map<int,node*> mp1; // key to node
    map<int,List*> mp2; // frequency to list of nodes
    int cap, minFreq, currSize;

public:
    LFUCache(int capacity) {
        cap = capacity;
        minFreq=0;
        currSize=0;
    }
    
    void updateMp2(node* temp){
        mp1.erase(temp->key);
        mp2[temp->cnt] -> deleteNode(temp);
        if(temp->cnt == minFreq && mp2[temp->cnt]->size == 0) minFreq++;
        List* nextHigherFreqList = new List();
        if(mp2.find(temp->cnt+1)!=mp2.end()){
            nextHigherFreqList = mp2[temp->cnt+1];
        }
        temp->cnt += 1;
        nextHigherFreqList->addFront(temp);
        mp2[temp->cnt]= nextHigherFreqList;
        mp1[temp->key]=temp;
    }

    int get(int key) {
        if(mp1.find(key) != mp1.end()){
            node* temp = mp1[key];
            int ans = temp->val;
            updateMp2(temp);
            return ans;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp1.find(key) != mp1.end()){
            node* temp = mp1[key];
            temp->val = value;
            updateMp2(temp);
        }
        else{
            if(currSize == cap){
                List* l = mp2[minFreq];
                mp1.erase(l->tail->prev->key);
                mp2[minFreq]-> deleteNode(l->tail->prev);
                currSize--;
            }
            currSize++;
            minFreq=1;
            List* listFreq = new List();
            if(mp2.find(minFreq) != mp2.end()){
                listFreq = mp2[minFreq];
            }
            node* temp = new node(key,value);
            listFreq->addFront(temp);
            mp1[key]=temp;
            mp2[minFreq]=listFreq;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */