/** 问题描述：
 *  设计并实现 LRU 缓存的数据结构，并支持 get 和 put 操作。
 *  get(key) 操作：如果密钥存在于缓存中，则获取密钥的值，否则返回 -1 。
 *  put(key, value) 操作：如果该键值不存在，则插入此键值。当缓存容量满时，使最少使用的键值无效，并插入新键值。
 *  时间复杂度为 O(1) 。
 */

#include <iostream>
#include <list>
#include<unordered_map>

using namespace std;

class LRUCache
{
    /*
        这题不会，脑瓜子嗡嗡的。
        利用unordered_map保存键和值。
        it表示某个地址，不存在则位于cache.end。
        利用list去判断当前键值的使用率。
        如果超出容量，则删除used中最后一个元素，即使用率最小的元素，并且used弹出此元素，将当前插入键值插入到used中。
        由于删除erase操作的复杂度为O(1)，则该算法也是这个复杂度。
    */

public:
    LRUCache(int capacity) : _capacity(capacity) {}
    
    int get(int key) 
    {
        auto it = cache.find(key);
        if (it == cache.end()) 
            return -1;
        touch(it);
        return it->second.first;
    }
    
    void put(int key, int value) 
    {
        auto it = cache.find(key);
        if (it != cache.end()) 
            touch(it);
        else 
        {
			if (cache.size() == _capacity) 
            {
				cache.erase(used.back());
				used.pop_back();
			}
            used.push_front(key);
        }
        cache[key] = { value, used.begin() };
    }
    
private:
    typedef list<int> LI;
    typedef pair<int, LI::iterator> PII;
    typedef unordered_map<int, PII> HIPII;
    
    void touch(HIPII::iterator it) 
    {
        int key = it->first;
        used.erase(it->second.second);
        used.push_front(key);
        it->second.second = used.begin();
    }
    
    HIPII cache;
    LI used;
    int _capacity;
};

int main(int argc, char const *argv[])
{
    LRUCache *cache = new LRUCache(2);
    cache->put(1, 1);
    cache->put(2, 2);
    assert(cache->get(1) == 1);       // returns 1
    cache->put(3, 3);    // evicts key 2
    assert(cache->get(2) == -1);       // returns -1 (not found)
    cache->put(4, 4);    // evicts key 1
    assert(cache->get(1) == -1);       // returns -1 (not found)
    assert(cache->get(3) == 3);       // returns 3
    assert(cache->get(4) == 4);       // returns 4
    return 0;
}
