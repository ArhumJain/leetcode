// INCOMPLETE SOLUTION, 
// WRONG
typedef struct CacheSlot {
    int value;
    int set;
    struct CacheSlot* next; // newer
    struct CacheSlot* prev; // older
} CacheSlot;
typedef struct {
    int capacity;
    CacheSlot* oldest;
    CacheSlot* newest;
    struct CacheSlot* map[10001];
} LRUCache;

LRUCache* lRUCacheCreate(int capacity) {
    LRUCache* cache = calloc(1, sizeof(LRUCache));
    cache->capacity = capacity;
    return cache;
}

int lRUCacheGet(LRUCache* obj, int key) {
    if (obj->map[key] != NULL && obj->map[key]->set != 0) {
        if (obj->map[key]->prev != NULL) {
            obj->map[key]->prev->next = obj->map[key]->next;
            if (obj->map[key]->next != NULL) {
                obj->map[key]->next->prev = obj->map[key]->prev;
            }
        }
        obj->newest->next = obj->map[key];
        obj->map[key]->prev = obj->newest;
        obj->newest = obj->map[key];
        return obj->map[key]->value;
    } else return -1;
}

void lRUCachePut(LRUCache* obj, int key, int value) {
    if (obj->map[key] != NULL && obj->map[key]->set) {
        if (obj->map[key]->prev != NULL) {
            obj->map[key]->prev->next = obj->map[key]->next;
            if (obj->map[key]->next != NULL) {
                obj->map[key]->next->prev = obj->map[key]->prev;
            }
        }
    } else {
        if (obj->map[key] == NULL) obj->map[key] = calloc(1, sizeof(CacheSlot));
        obj->map[key]->set = 1;
        if (obj->capacity != 0) {
            obj->capacity--;
        } else {
            obj->oldest->set = 0;
            obj->oldest = obj->oldest->next;
            obj->oldest->prev->next = NULL;
            obj->oldest->prev->prev = NULL;
            obj->oldest->prev = NULL;
        }
    }
    if (obj->newest != NULL) {
        obj->map[key]->prev = obj->newest;
        obj->newest->next = obj->map[key];
    }
    obj->newest = obj->map[key];
    obj->map[key]->value = value;
    if (obj->oldest == NULL) {
        obj->oldest = calloc(1, sizeof(CacheSlot));
        obj->oldest = obj->map[key];
        obj->oldest->next = obj->newest;
    }
}

void lRUCacheFree(LRUCache* obj) {
    for (int i = 0; i < 10001; i++) {
        if (obj->map[i] != NULL) free(obj->map[i]);
    }
    free(obj);
    return;
}

/**
 * Your LRUCache struct will be instantiated and called as such:
 * LRUCache* obj = lRUCacheCreate(capacity);
 * int param_1 = lRUCacheGet(obj, key);
 
 * lRUCachePut(obj, key, value);
 
 * lRUCacheFree(obj);
*/
