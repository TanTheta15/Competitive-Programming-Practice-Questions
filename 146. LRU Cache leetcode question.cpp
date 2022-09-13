/*    146. LRU Cache
Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

Implement the LRUCache class:

LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
int get(int key) Return the value of the key if the key exists, otherwise return -1.
void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.
The functions get and put must each run in O(1) average time complexity.

 

Example 1:

Input
["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
Output
[null, null, null, 1, null, -1, null, -1, 3, 4]

Explanation
LRUCache lRUCache = new LRUCache(2);
lRUCache.put(1, 1); // cache is {1=1}
lRUCache.put(2, 2); // cache is {1=1, 2=2}
lRUCache.get(1);    // return 1
lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
lRUCache.get(2);    // returns -1 (not found)
lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
lRUCache.get(1);    // return -1 (not found)
lRUCache.get(3);    // return 3
lRUCache.get(4);    // return 4
*/
class LRUCache {
public:
    class Node{
    public:
        int key_, val_;
        Node *next, *prev;

        Node(int key_, int val_){
            this -> key_ = key_;
            this -> val_ = val_;
        }
    };
    
    Node *head = new Node(-1, -1);
    Node *tail = new Node(-1, -1);
    
    unordered_map<int, Node*> mp;
    int cap;
    LRUCache(int capacity) {
        cap = capacity;
        head -> next = tail;
        head -> prev = NULL;
        tail -> prev = head;
        tail -> next = NULL;
    }
    
    void addNode(Node *node){
        Node *curr = head -> next;
        node -> next = curr;
        node -> prev = head;
        head -> next = node;
        curr -> prev = node;
    }
    
    void deleteNode(Node *node){
        Node *delNext = node -> next;
        Node *delPrev = node -> prev;
        delPrev -> next = delNext;
        delNext -> prev = delPrev;
    }
    
    int get(int key) {
        if(mp.find(key) != mp.end()){
            Node *resNode = mp[key];
            int res = resNode -> val_;
            mp.erase(key);
            deleteNode(resNode);
            addNode(resNode);
            mp[key] = head -> next;
            return res;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
            Node *resNode = mp[key];
            deleteNode(resNode);
            mp.erase(key);
        }
        if(mp.size() == cap){
            mp.erase(tail -> prev -> key_);
            deleteNode(tail -> prev);
        }
        addNode(new Node(key, value));
        mp[key] = head -> next;
    }
};
