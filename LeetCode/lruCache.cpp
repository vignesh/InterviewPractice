class Node {
    public:
    int key;
    int val;
    Node* next;
    Node* prev;
    Node(int k, int v): key(k), val(v), next(NULL), prev(NULL) {}
};

class DLL {
    Node* head;
    Node* tail;
    
    bool isEmpty() {
        bool empty = (tail) ? false : true;
        return empty;
    }
    
    public:
    DLL(): head(NULL), tail(NULL) {}

    Node* addNode(int key, int val) {
        Node *node = new Node(key, val);
        if (!head && !tail) {
            head = node;
            tail = node;
        }
        else {
            node->next = head;
            head->prev = node;
            head = node;
        }
        return node;
    }
    
    void moveToHead(Node *node) {
        //node is already the most revently visited
        if (node == head) {
            return;
        }
        else if (node == tail) {
            tail = tail->prev;
            tail->next = NULL;
        }
        else {
            node->next->prev = node->prev;
            node->prev->next = node->next;
        }
        node->next = head;
        //can set node->prev to null, because we know its at the top/front of the queue
        node->prev = NULL;
        head->prev = node;
        head = node;
    }
    
    void popTail() {
        //Empty queue
        if (isEmpty()) {
            return;
        }
        else if (head==tail) {
            delete tail;
            tail = NULL;
            head = NULL;
        }
        else {
            Node *temp = tail;
            tail = tail->prev;
            tail->next = NULL;
            delete temp;
        }
    }
    
    Node* getTail() {
        return tail;
    }
};

class LRUCache {
    int capacity;
    int size;
    unordered_map<int, Node*> cache;
    DLL* queue;

    public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        size = 0;
        queue = new DLL();
        cache = unordered_map<int, Node*>();
    }
    
    int get(int key) {
        //key not in cache
        if(!cache[key]) {
            return -1;
        }
        //update val for key
        int val = cache[key]->val;
        //key already exists mvoe to head
        queue->moveToHead(cache[key]);
        return val;
    }
    
    void put(int key, int value) {
        if (cache[key]) {
            cache[key]->val = value;
            //key already exists move to head
            queue->moveToHead(cache[key]);
            return;
        }
        //cache is full 
        else if (capacity==size) {
            int k = queue->getTail()->key;
            cache.erase(k);
            queue->popTail();
            size--;
        }
        //add node
        Node * node = queue->addNode(key, value);
        size++;
        cache[key] = node;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */