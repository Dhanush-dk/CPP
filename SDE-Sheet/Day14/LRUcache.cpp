//Leetcode

class LRUCache {
public:
    class Node{
        public:
            int key;
            int val;
            Node* next;
            Node* prev;
            Node(int key, int val){
                this->key = key;
                this->val = val;
            }
    };
    
    Node* head = new Node(-1,-1);
    Node* tail = new Node(-1,-1);
    
    int capacity;
    unordered_map<int, Node*> map;
    
    LRUCache(int capacity) {
        this->capacity = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    void addNode(Node* newnode){
        newnode->next = head->next;
        newnode->prev = head;
        newnode->next->prev = newnode;
        head->next = newnode;
    }
    
    void deleteNode(Node *delnode){
        Node* delprev = delnode->prev;
        Node* delnext = delnode->next;
        delprev->next = delnext;
        delnext->prev = delprev;
    }
    
    int get(int key) {
        if(map.find(key) != map.end()){
            Node *resNode = map[key];
            int res = resNode->val;
            map.erase(key);
            deleteNode(resNode);
            addNode(resNode);
            map[key] = head->next;
            return res;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(map.find(key) != map.end()){
            Node* nodeAddress = map[key];
            map.erase(key);
            deleteNode(nodeAddress);
        }
        if(map.size() == capacity){
            map.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        addNode(new Node(key,value));
        map[key] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */