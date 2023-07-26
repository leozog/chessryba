/*#pragma once
#include <memory>
#include <vector>
#include <unordered_set>

template <typename T>
class bush
{
private:
    std::shared_ptr<bush<T>::node> root;
    using node_hash_table = std::unordered_set<std::weak_ptr<bush<T>::node>, bush<T>::node::hash, bush<T>::node::equal_to>;
    node_hash_table hash_table;

public:
    class node
    {
        friend class bush;

    private:
        node_hash_table &hash_table;

        node(node_hash_table &hash_table, uint32_t hash_val, std::unique_ptr<T> &&x);

    public:
        ~node();

        std::unique_ptr<T> x;
        std::vector<std::shared_ptr<bush<T>::node>> front;
        std::vector<std::weak_ptr<bush<T>::node>> back;

        T &bush<T>::node::operator->();
        void add_front(std::shared_ptr<bush<T>::node> &n);

        struct hash
        {
            std::size_t operator()(std::weak_ptr<bush<T>::node> const &n) const noexcept;
        };

        struct equal_to
        {
            constexpr bool operator()(const std::weak_ptr<bush<T>::node> &lhs, const std::weak_ptr<bush<T>::node> &rhs) const;
        };
    };

    std::shared_ptr<bush<T>::node> &bush<T>::get_root();
    void move_root(std::shared_ptr<bush<T>::node> &n);
};
*/