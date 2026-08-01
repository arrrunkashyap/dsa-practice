class LRUCache {
private:
    class Node {
    public:
        int key, value;
        Node *prev, *next;

        Node(int k, int v) {
            key = k;
            value = v;
            prev = next = nullptr;
        }
    };

    int capacity;

    unordered_map<int, Node*> mp;

    Node *head, *tail;

    void remove(Node* node) {
        Node* prev = node->prev;
        Node* next = node->next;

        prev->next = next;
        next->prev = prev;
    }

    void insert(Node* node) {
        node->next = head->next;
        node->prev = head;

        head->next->prev = node;
        head->next = node;
    }

public:
    LRUCache(int capacity) {

        this->capacity = capacity;

        head = new Node(0,0);
        tail = new Node(0,0);

        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {

        if(mp.find(key) == mp.end())
            return -1;

        Node* node = mp[key];

        remove(node);
        insert(node);

        return node->value;
    }

    void put(int key, int value) {

    // If key already exists, remove its old node
        if (mp.find(key) != mp.end()) {
            Node* node = mp[key];
            remove(node);
            mp.erase(key);
            delete node;
        }

    // Insert new node at front
        Node* newNode = new Node(key, value);
        insert(newNode);
        mp[key] = newNode;

    // Remove least recently used if capacity exceeded
        if (mp.size() > capacity) {
            Node* lru = tail->prev;
            remove(lru);
            mp.erase(lru->key);
            delete lru;
        }
    }
};
           

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */