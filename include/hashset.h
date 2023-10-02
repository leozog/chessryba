#pragma once
#include <utility>
#include <vector>
#include <list>

template <typename Key, class Hash, class KeyEqual>
class hashset
{
public:
    struct node
    {
        size_t hash;
        Key key;

        std::list<std::weak_ptr<hashset::node>> &bucket_ref;
        typename std::list<std::weak_ptr<hashset::node>>::iterator bucket_iter;

        node(std::list<std::weak_ptr<hashset::node>> &bucket, size_t hash, Key key);
        ~node();

        bool compare(size_t hash, Key key);
    };

private:
    std::vector<std::list<std::weak_ptr<hashset::node>>> buckets;

public:
    hashset(size_t n_of_buckets);
    std::pair<std::shared_ptr<node>, bool> get_node(const Key x);
};

// hashset::node
template <typename Key, class Hash, class KeyEqual>
hashset<Key, Hash, KeyEqual>::node::node(std::list<std::weak_ptr<node>> &bucket, size_t hash, Key key) : bucket_ref{bucket}, bucket_iter{bucket.insert(bucket.end(), std::weak_ptr<node>())}, hash{hash}, key{key}
{
}

template <typename Key, class Hash, class KeyEqual>
hashset<Key, Hash, KeyEqual>::node::~node()
{
    bucket_ref.erase(bucket_iter);
}

template <typename Key, class Hash, class KeyEqual>
bool hashset<Key, Hash, KeyEqual>::node::compare(size_t hash, Key key)
{
    if (this->hash != hash)
        return false;
    return KeyEqual{}(this->key, key);
}
// hashset::node

// hashset
template <typename Key, class Hash, class KeyEqual>
hashset<Key, Hash, KeyEqual>::hashset(size_t n_of_buckets)
{
    buckets.resize(n_of_buckets);
}

template <typename Key, class Hash, class KeyEqual>
std::pair<std::shared_ptr<typename hashset<Key, Hash, KeyEqual>::node>, bool> hashset<Key, Hash, KeyEqual>::get_node(const Key x)
{
    size_t hash = Hash{}(x);
    std::list<std::weak_ptr<hashset::node>> &bucket = buckets[hash % buckets.size()];

    for (typename std::list<std::weak_ptr<hashset::node>>::iterator it = bucket.begin(); it != bucket.end(); ++it)
    {
        if (it->lock()->compare(hash, x))
            return std::make_pair(it->lock(), false);
    }
    std::shared_ptr<hashset::node> n = std::make_shared<hashset::node>(bucket, hash, x);
    bucket.back() = n;
    return std::make_pair(n, true);
}
// hashset