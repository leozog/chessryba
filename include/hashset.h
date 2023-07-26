#pragma once
#include <utility>
#include <vector>
#include <list>

template <typename Key, class Hash, class KeyEqual>
class hashset
{
private:
    struct node
    {
        size_t hash;
        Key key;

        node(size_t hash, Key key) : hash{hash}, key{key} {}

        bool operator==(const node &other);
    };

    std::vector<std::list<hashset::node>> buckets;

public:
    struct iterator
    {
    private:
        typename std::list<hashset::node>::iterator ptr;
        std::list<hashset::node> &list_ref;

    public:
        iterator(typename std::list<hashset::node>::iterator ptr, std::list<hashset::node> &list_ref) : ptr{ptr}, list_ref{list_ref} {}

        Key &operator*() const { return ptr->key; }
        Key *operator->() { return &(ptr->key); }
        void erase() { list_ref.erase(ptr); }
    };

    hashset(size_t n_of_buckets);
    std::pair<hashset::iterator, bool> insert(const Key x);
};

template <typename Key, class Hash, class KeyEqual>
bool hashset<Key, Hash, KeyEqual>::node::operator==(const node &other)
{
    if (hash != other.hash)
        return false;
    return KeyEqual{}(key, other.key);
}

template <typename Key, class Hash, class KeyEqual>
hashset<Key, Hash, KeyEqual>::hashset(size_t n_of_buckets)
{
    buckets.resize(n_of_buckets);
}

template <typename Key, class Hash, class KeyEqual>
std::pair<typename hashset<Key, Hash, KeyEqual>::iterator, bool> hashset<Key, Hash, KeyEqual>::insert(const Key x)
{
    size_t hash = Hash{}(x);
    std::list<hashset::node> &bucket = buckets[hash % buckets.size()];
    hashset::node n(hash, x);

    for (typename std::list<hashset::node>::iterator it = bucket.begin(); it != bucket.end(); ++it)
    {
        if (n == *it)
            return std::make_pair(typename hashset<Key, Hash, KeyEqual>::iterator(it, bucket), false);
    }
    return std::make_pair(typename hashset<Key, Hash, KeyEqual>::iterator(bucket.insert(bucket.end(), n), bucket), true);
}