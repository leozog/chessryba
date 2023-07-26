/*#include "bush.h"

// bush::node
template <typename T>
bush<T>::node::node(node_hash_table &hash_table, uint32_t hash_val, std::unique_ptr<T> &&x)
    : hash_table{hash_table},
      x{std::move(x)}
{
    hash_table.insert(std::make_pair());
}

template <typename T>
bush<T>::node::~node()
{
    hash_table.erase(hash_table_iterator);
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
std::size_t bush<T>::node::hash::operator()(std::weak_ptr<bush<T>::node> const &n) const noexcept
{
    return n->x->hash();
}

template <typename T>
constexpr bool bush<T>::node::equal_to::operator()(const std::weak_ptr<bush<T>::node> &lhs, const std::weak_ptr<bush<T>::node> &rhs) const
{
    return lhs->x->operator==(rhs->x);
}
// bush::node

// bush
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
// bush*/