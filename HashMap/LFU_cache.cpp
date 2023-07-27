// LFU cache
class Node {
public:
    int key, value, cnt;
    Node *next;
    Node *prev;
    Node(int _key, int _val) {
        key = _key;
        value = _val;
        cnt = 1;
    }
};
class List {
public:
    int size;
    Node *head;
    Node *tail;
    List() {
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
        size = 0;
    }
    void addFront(Node *node) {
        Node *t = head->next;
        node->next = t;
        node->prev = head;
        t->prev = node;
        head->next = node;
        size++;
    }
    void removeNode(Node *delnode) {
        Node *delprev = delnode->prev;
        Node *delnext = delnode->next;
        delprev->next = delnext;
        delnext->prev = delprev;
        size--;
    }
};

class LFUCache {
public:
    int maxSizeCache, minFreq, curSize;
    map<int, Node *> keyNode;
    map<int, List *> freqMap;
    LFUCache(int capacity) {
        maxSizeCache = capacity;
        minFreq = 0;
        curSize = 0;
    }
    void updateFreqMap(Node *node) {
        keyNode.erase(node->key);              // remove from keynode
        freqMap[node->cnt]->removeNode(node);  // remove node from previous list
        // calculate min freq
        if (node->cnt == minFreq and freqMap[node->cnt]->size == 0) {
            minFreq++;
        }
        // make new temp list and with next freq.
        List *nextHigherFreqList = new List();
        if (freqMap.find(node->cnt + 1) != freqMap.end()) {
            nextHigherFreqList = freqMap[node->cnt + 1];
        }
        nextHigherFreqList->addFront(node);  // add node front of the list
        node->cnt += 1;                      // making new cnt for that node to maintain new freq
        freqMap[node->cnt] =
            nextHigherFreqList;     // update that list in freq Map
        keyNode[node->key] = node;  // update that key in keynode map
    }

    int get(int key) {
        if (keyNode.find(key) != keyNode.end()) {
            Node *node = keyNode[key];
            int val = node->value;
            updateFreqMap(node);
            return val;
        }
        return -1;
    }

    void put(int key, int value) {
        if (maxSizeCache == 0) return;
        if (keyNode.find(key) != keyNode.end()) {
            Node *node = keyNode[key];
            node->value = value;
            updateFreqMap(node);
        } else {
            // if capasity is full then remove LFU if tie then LRU
            if (curSize == maxSizeCache) {
                List *minFreqlist = freqMap[minFreq];
                keyNode.erase(minFreqlist->tail->prev->key);
                freqMap[minFreq]->removeNode(minFreqlist->tail->prev);
                curSize--;
            }
            curSize++;
            // new key value has to be added who is not there previouly
            minFreq = 1;
            List *listFreq = new List();
            if (freqMap.find(minFreq) != freqMap.end()) {
                listFreq = freqMap[minFreq];
            }
            Node *node = new Node(key, value);
            listFreq->addFront(node);
            keyNode[key] = node;
            freqMap[minFreq] = listFreq;
        }
    }
};
