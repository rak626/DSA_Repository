
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



/* 

To summarize:
- Time Complexity (both versions): O(1) for both `get` and `put` functions.
- Space Complexity (both versions): O(n), where n is the capacity of the cache.

Let's analyze the time complexity and space complexity for both the original and optimized versions of the LRU Cache implementation.

Original Version:
1. The `get` function:
   - Accessing elements in an unordered_map takes an average time complexity of O(1).
   - Deleting a node from the doubly linked list and adding it after the head also takes O(1) time.
   - Overall, the `get` function takes O(1) time.

2. The `put` function:
   - The same operations for accessing and deleting a node from the doubly linked list and the unordered_map have a time complexity of O(1).
   - The `addNodeAfterHead` function also takes O(1) time.
   - Overall, the `put` function takes O(1) time.

The time complexity for both the `get` and `put` functions is O(1).

Now, let's look at the space complexity:
1. The `node` class is used to create nodes for the doubly linked list. Each node contains two integers, so it takes O(1) space per node.
2. The `cap` variable takes O(1) space.
3. The doubly linked list, `head`, and `tail` nodes take O(1) space.
4. The unordered_map stores pointers to nodes in the doubly linked list, so it takes O(n) space, where n is the number of elements in the cache.

The overall space complexity is O(n), where n is the capacity of the cache.

Optimized Version:
1. The `get` function:
   - Accessing elements in the unordered_map takes O(1) time.
   - Moving an element to the front of the linked list using the `splice` function takes O(1) time.
   - Overall, the `get` function takes O(1) time.

2. The `put` function:
   - The `get` function is called first, which takes O(1) time.
   - If the key is already in the cache, updating the value in the list and map takes O(1) time.
   - If the key is not in the cache, a new element is added to the front of the list and inserted into the unordered_map, both of which take O(1) time.
   - If the cache is full, the least recently used element is removed from the back of the list, and its entry is removed from the unordered_map, which also takes O(1) time.
   - Overall, the `put` function takes O(1) time.

The space complexity for the optimized version:
1. The list `li` stores pairs of key-value, so it takes O(n) space, where n is the number of elements in the cache.
2. The unordered_map `um` stores pointers to elements in the list, so it also takes O(n) space.

The overall space complexity is O(n), where n is the capacity of the cache.


 */