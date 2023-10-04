#pragma once
#include <memory>
#include <vector>

template <typename T>
class bush
{
public:
    struct node
    {
        std::vector<std::shared_ptr<node>> link;
        T x;

        node(const T &x);
    };

private:
    std::shared_ptr<node> root;

public:
    bush(const T &new_root);

    std::shared_ptr<bush::node> get_root() const;
    void move_root(std::shared_ptr<node> new_root);
};

// bush::node
template <typename T>
bush<T>::node::node(const T &x) : x{x}
{
}
// bush::node

// bush
template <typename T>
bush<T>::bush(const T &new_root) : root{std::make_shared<node>(new_root)}
{
}

template <typename T>
std::shared_ptr<typename bush<T>::node> bush<T>::get_root() const
{
    return root;
}

template <typename T>
void bush<T>::move_root(std::shared_ptr<bush::node> new_root)
{
    root = new_root;
}
// bush