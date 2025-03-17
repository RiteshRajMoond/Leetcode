class Node {
public:
    int key, value;
    Node* prev, *next;
    Node(int key, int value) : key(key), value(value), prev(nullptr), next(nullptr) {}
};

class LRUCache {
    int cur_size, max_size;
    Node* head, *tail;
    unordered_map<int, Node*> mp;

    void insert(int key, int value){
        Node* node = new Node(key, value);
        if(!head) {
            head = tail = node;
            return;
        }

        node->next = head;
        head->prev = node;
        head = node;
    }

    void delete_last(){
        if(!head) return;
        mp.erase(tail->key);
        if(!head->next) {
            Node* temp = head;
            head = tail = nullptr;
            delete temp;
            return;
        }

        tail = tail->prev;
        tail->next = nullptr;
    }

    void move_to_front(Node* node){
        if(head == node) return;
        if(tail == node) {
            tail = tail->prev;
            tail->next = nullptr;
        } else {
            node->next->prev = node->prev;
            node->prev->next = node->next;
        }

        node->next = head;
        node->prev = nullptr;
        head->prev = node;
        head = node;
    }
public:
    LRUCache(int capacity) {
        max_size = capacity;
        cur_size = 0;
        head = tail = nullptr;
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end()) return -1;

        Node* node = mp[key];
        move_to_front(node);
        return node->value;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()) {
            Node* node = mp[key];
            node->value = value;
            move_to_front(node);
            return;
        } 

        if(cur_size == max_size) {
            delete_last();
            cur_size--;
        }

        insert(key, value);
        mp[key] = head;
        cur_size++;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */