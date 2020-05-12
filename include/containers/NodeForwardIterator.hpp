//
// Created by edat44 on 5/12/20.
//

#ifndef GAME_NODEFORWARDITERATOR_HPP
#define GAME_NODEFORWARDITERATOR_HPP

namespace game::containers {

template <typename Type, typename UnqualifiedType = std::remove_cv_t<Type>>
class NodeForwardIterator : public std::iterator<std::forward_iterator_tag,
        UnqualifiedType,
        std::ptrdiff_t,
        Type*,
        Type&> {
public:
    explicit NodeForwardIterator (Node<Type>* temp) : itr(temp) {}
    explicit NodeForwardIterator (nullptr_t) : itr(nullptr) {}

    NodeForwardIterator() = default;

    void swap(NodeForwardIterator& other) noexcept {
        std::swap(itr, other.itr);
    }

    NodeForwardIterator& operator++() { // Pre-increment
        assert(itr != nullptr && "Out-of-bounds iterator increment!");
        itr = itr->mNext;
        return *this;
    }

    NodeForwardIterator operator++(int) { // Post-increment
        assert(itr != nullptr && "Out-of-bounds iterator increment!");
        NodeForwardIterator tmp(*this);
        itr = itr->mNext;
        return tmp;
    }

    template <typename OtherType>
    bool operator == (const NodeForwardIterator<OtherType>& rhs) const {
        return itr == rhs.itr;
    }

    template <typename OtherType>
    bool operator!=(const NodeForwardIterator<OtherType>& rhs) const {
        return !(*this == rhs);
    }

    Type& operator*() const {
        assert(itr != nullptr && "Invalid iterator dereference");
        return itr->mData;
    }

    Type& operator->() const {
        assert(itr != nullptr && "Invalid iterator dereference");
        return itr->mData;
    }

    Node<Type>* GetNode() const {
        return itr;
    }

    // One-way conversion to const iterator;
    explicit operator NodeForwardIterator<const Type>() const {
        return NodeForwardIterator<const Type>(itr);
    }

private:
    Node<Type>* itr;
};

} // ns game::containers


#endif //GAME_NODEFORWARDITERATOR_HPP
