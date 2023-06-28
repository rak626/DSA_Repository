
// LRU Cache

class LRUCache {
public:
    class node {
    public:
        int key;
        int val;
        node *prev;
        node *next;
        node(int _key, int _val) {
            key = _key;
            val = _val;
        }
    };

    int cap;
    node *head = new node(-1, -1);
    node *tail = new node(-1, -1);
    unordered_map<int, node *> hashMap;

    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }

    void deleteNode(node *cur) {
        node *curprev = cur->prev;
        node *curnext = cur->next;
        curprev->next = curnext;
        curnext->prev = curprev;
    }
    void addNodeAfterHead(node *cur) {
        node *temp = head->next;
        cur->next = temp;
        cur->prev = head;
        temp->prev = cur;
        head->next = cur;
    }

    int get(int __key) {
        // find - remove - add after head
        if (hashMap.find(__key) != hashMap.end()) {
            node *foundNode = hashMap[__key];
            int foundNodeVal = foundNode->val;
            hashMap.erase(__key);
            deleteNode(foundNode);
            addNodeAfterHead(foundNode);
            hashMap[__key] = head->next;
            return foundNodeVal;
        }
        return -1;
    }

    void put(int __key, int value) {
        if (hashMap.find(__key) != hashMap.end()) {
            node *foundNode = hashMap[__key];
            hashMap.erase(__key);
            deleteNode(foundNode);
        }
        if (cap == hashMap.size()) {
            // delete tail node and insert after head
            hashMap.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        node *newNode = new node(__key, value);
        addNodeAfterHead(newNode);
        hashMap[__key] = head->next;
    }
};

// optimised code shorter version same logic

class LRUCache {
    int capacity;
    list<pair<int, int>> li;
    unordered_map<int, list<pair<int, int>>::iterator> um;

public:
    LRUCache(int capacity) : capacity{capacity} {}

    int get(int key) {
        if (um.find(key) == um.end()) return -1;
        li.splice(li.begin(), li, um[key]);
        return um[key]->second;
    }

    void put(int key, int value) {
        if (get(key) != -1) {
            um[key]->second = value;
            return;
        }

        if (um.size() == capacity) {
            int delKey = li.back().first;
            li.pop_back();
            um.erase(delKey);
        }

        li.emplace_front(key, value);
        um[key] = li.begin();
    }
};
