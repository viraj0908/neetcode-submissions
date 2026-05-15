class LRUCache {

public:

    class ListNode {

    public:

        int key;
        int value;

        ListNode* next;
        ListNode* prev;

        ListNode(int k, int v){

            key = k;
            value = v;

            next = nullptr;
            prev = nullptr;
        }
    };

    unordered_map<int, ListNode*> hash;

    ListNode* head;
    ListNode* tail;

    int cap;

    LRUCache(int capacity) {

        cap = capacity;

        head = new ListNode(-1,-1);
        tail = new ListNode(-1,-1);

        head->next = tail;
        tail->prev = head;
    }

    void remove(ListNode* node){

        ListNode* prv = node->prev;
        ListNode* nxt = node->next;

        prv->next = nxt;
        nxt->prev = prv;
    }

    void insertFront(ListNode* node){

        ListNode* first = head->next;

        head->next = node;

        node->prev = head;
        node->next = first;

        first->prev = node;
    }

    int get(int key) {

        if(!hash.count(key)){
            return -1;
        }

        ListNode* curr = hash[key];

        remove(curr);
        insertFront(curr);

        return curr->value;
    }

    void put(int key, int value) {

        if(hash.count(key)){

            ListNode* curr = hash[key];

            curr->value = value;

            remove(curr);
            insertFront(curr);

            return;
        }

        if(hash.size() == cap){

            ListNode* lru = tail->prev;

            remove(lru);

            hash.erase(lru->key);

            delete lru;
        }

        ListNode* curr = new ListNode(key, value);

        insertFront(curr);

        hash[key] = curr;
    }
};