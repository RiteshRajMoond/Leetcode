#include <unordered_map>
using namespace std;

class Node {
public:
    int key, value;
    Node *prev, *next;

    Node(int key, int value) : key(key), value(value), next(nullptr), prev(nullptr) {}
};

class LRUCache {
    int max_size, cur_size;
    Node *head, *tail;
    unordered_map<int, Node*> mp; // key -> node

    void remove_last() {
        if (!tail) return;

        mp.erase(tail->key); // Remove from map

        Node* temp = tail;
        if (tail == head) { // Single element
            head = tail = nullptr;
        } else {
            tail = tail->prev;
            tail->next = nullptr;
        }
        delete temp;
    }

    void move_to_front(Node* node) {
        if (node == head) return;

        // Remove node from its position
        if (node == tail) {
            tail = tail->prev;
            tail->next = nullptr;
        } else {
            node->prev->next = node->next;
            if (node->next) node->next->prev = node->prev;
        }

        // Move to front
        node->next = head;
        node->prev = nullptr;
        head->prev = node;
        head = node;
    }

    void insert_at_start(int key, int val) {
        Node* temp = new Node(key, val);
        if (!head) {
            head = tail = temp;
        } else {
            temp->next = head;
            head->prev = temp;
            head = temp;
        }
        mp[key] = head;
    }

public:
    LRUCache(int capacity) {
        max_size = capacity;
        cur_size = 0;
        head = tail = nullptr;
    }

    int get(int key) {
        if (mp.find(key) == mp.end()) return -1;

        Node* node = mp[key];
        move_to_front(node);
        return node->value;
    }

    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            Node* node = mp[key];
            node->value = value;
            move_to_front(node);
            return;
        }

        if (cur_size == max_size) {
            remove_last();
            cur_size--;
        }

        insert_at_start(key, value);
        cur_size++;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
