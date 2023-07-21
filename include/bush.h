#pragma once
#include <memory>
#include <vector>
#include <map>

template <typename T>
class bush
{
private:
    std::shared_ptr<bush<T>::node> root;
    std::map<uint32_t, std::weak_ptr<bush<T>::node>> hash_map;

public:
    class node
    {
        friend class bush;

    private:
        std::map<uint32_t, std::weak_ptr<bush<T>::node>> &hash_map;
        std::map<uint32_t, std::weak_ptr<bush<T>::node>>::iterator hash_map_iterator;

        node(std::map<uint32_t, std::weak_ptr<bush<T>::node>> &hash_map, uint32_t hash_val, std::unique_ptr<T> &&x);

    public:
        ~node();

        std::unique_ptr<T> x;
        std::vector<std::shared_ptr<bush<T>::node>> front;
        std::vector<std::weak_ptr<bush<T>::node>> back;

        T &bush<T>::node::operator->();
        void add_front(std::shared_ptr<bush<T>::node> &n);
    };

    std::shared_ptr<bush<T>::node> &bush<T>::get_root();
    void move_root(std::shared_ptr<bush<T>::node> &n);
};
