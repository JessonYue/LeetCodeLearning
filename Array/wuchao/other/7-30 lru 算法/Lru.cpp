#include <map>
class Node{
public:
    Node(int key,int value){
        this->key = key;
        this->value = value;
    }

    Node* after;
    Node* before;
    int key;
    int value;
};
using std::map;
class LRUCache {
    int capacity;
public:
    Node* head;
    Node* tail;
    map<int,Node*> cacheMap;
    int size = 0;
    LRUCache(int capacity) {
        this->capacity = capacity;
        head = static_cast<Node*>(malloc(sizeof(Node)));
        tail = static_cast<Node*>(malloc(sizeof(Node)));
        head->after = tail;
        tail->before = head;
    }

    int get(int key) {
        Node* entity = cacheMap[key];
        if(entity!= nullptr){
            if(!isYoungest(entity)){
                remove(entity);
                insertToHead(entity);
            }
            return entity->value;
        }
        return -1;
    }

    void put(int key, int value) {
        Node* entity = cacheMap[key];
        if(entity== nullptr){
            Node* node = static_cast<Node*>(malloc(sizeof(Node)));
            entity = node;
            entity->key = key;
            entity->value = value;
            cacheMap[key] = entity;
            insertToHead(entity);
            size++;
        } else {
            cacheMap[key]->value = value;
            if(!isYoungest(entity)){
                remove(entity);
                insertToHead(entity);
            }
        }
        if(size>capacity){
            removeEldest();
        }

    }

    bool isYoungest(Node* node){
        return head->after == node;
    }

    void removeEldest(){
        Node* eldest = tail->before;
        remove(eldest);
        cacheMap.erase(eldest->key);
        size--;
    }

    void remove(Node* node){
        Node* before = node->before;
        Node* after = node->after;
        before->after = after;
        after->before = before;
    }

    void insertToHead(Node* node){
        Node* after = head->after;
        head->after = node;
        node->before = head;
        node->after = after;
        after->before = node;
    }
};