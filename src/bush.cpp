#include "bush.h"

template <typename T>
bush<T>::node::node(std::map<uint32_t, std::weak_ptr<bush<T>::node>> &hash_map, uint32_t hash_val, std::unique_ptr<T> &&x)
    : hash_map{hash_map},
      x{std::move(x)}
{
    hash_map.insert(std::pair());
}

template <typename T>
bush<T>::node::~node()
{
    hash_map.erase(hash_map_iterator);
}

template <typename T>
T &bush<T>::node::operator->()
{
    return *x;
}

template <typename T>
void bush<T>::node::add_front(std::shared_ptr<bush<T>::node> &n)
{
    front.push_back(n);
    n->back.push_back(std::make_weak(*this));
}

template <typename T>
std::shared_ptr<bush<T>::node> &bush<T>::get_root()
{
    return root;
}

template <typename T>
void bush<T>::move_root(std::shared_ptr<bush<T>::node> &n)
{
    root = n;
}