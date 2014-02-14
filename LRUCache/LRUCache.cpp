//============================================================================
// LRU Cache 
// 
// Design and implement a data structure for Least Recently Used (LRU) cache.
// It should support the following operations: get and set.
//
// get(key) - Get the value (will always be positive) of the key if the key 
// exists in the cache, otherwise return -1.
// set(key, value) - Set or insert the value if the key is not already present. 
// When the cache reached its capacity, it should invalidate the least 
// recently used item before inserting a new item.
//
//============================================================================

#include <iostream>
#include <list>
#include <unordered_map>

using namespace std;

class LRUCache{
public:
    LRUCache(int capacity) {
        _cap = capacity;
    }

    int get(int key) {
        if (!_map.count(key)) return -1;
        auto it = _map[key];
        _list.push_front(*it);
        _list.erase(it);
        it = _list.begin();
        _map[key] = it;
        return it->second;
    }

    void set(int key, int value) {
        if (_map.count(key)) _list.erase(_map[key]), _map.erase(key);
        else if (_map.size() == _cap) _map.erase(_list.back().first), _list.pop_back();
        _list.push_front(make_pair(key, value));
        _map[key] = _list.begin();
    }

private:
    int _cap;
    list<pair<int, int> > _list;
    unordered_map<int, list<pair<int, int> >::iterator> _map;
};

int main() {
    return 0;
}
