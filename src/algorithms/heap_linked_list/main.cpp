#include <fmt/format.h>

#include <assert.h>
#include <iostream>
#include <memory>

template<typename T>
struct Node
{
  T value;
  Node *next;
};

template<typename T>
class LinkedList
{
private:
  Node<T> m_head;

public:
  LinkedList(T value)
  {
    this->m_head = Node<T>{ value, nullptr };
  }

  ~LinkedList()
  {
    while (true) {
      try {
        this->pop();
      } catch (std::out_of_range &ex) {
        break;
      }
    }
  }

  void append(T value)
  {
    auto p = &this->m_head;

    while (p->next)
      p = p->next;

    auto node = new Node<T>{ value, nullptr };
    p->next = node;

    fmt::print("append | node: {}, value: {}\n", fmt::ptr(node), node->value);
  }

  void insert(size_t index, T value)
  {
    auto p = &this->m_head;

    if (index > 0) {
      for (size_t i = 0; i < index - 1; i++) {
        if (!p) throw std::out_of_range("insert operation out of bounds of the linked list");
        p = p->next;
      }
    }

    auto node = new Node<T>{ value, p->next };
    fmt::print("insert | node: {}, value: {}, next: {}\n", fmt::ptr(node), node->value, fmt::ptr(node->next));

    if (index > 0) {
      p->next = node;
    } else {
      this->m_head = *node;
    }
  }

  void pop()
  {
    Node<T> *previous = nullptr;
    auto actual = &this->m_head;

    if (!actual->next)
      throw std::out_of_range("Ilegal pop of the head of the linked list");

    while (actual->next) {
      previous = actual;
      actual = actual->next;
    }

    fmt::print("pop | node: {}, value: {}\n", fmt::ptr(actual), actual->value);

    delete actual;
    previous->next = nullptr;
  }

  void remove(size_t index)
  {
    Node<T> *previous = nullptr;
    auto actual = &this->m_head;

    for (size_t i = 0; i < index; i++) {
      if (!actual) throw std::out_of_range("remove operation out of bounds of the linked list");
      previous = actual;
      actual = actual->next;
    }

    if (previous) {
      fmt::print("remove | node: {}, value: {}\n", fmt::ptr(actual), actual->value);
      previous->next = actual->next;
    } else {
      fmt::print("remove | node: {}, value: {}\n", fmt::ptr(&this->m_head), this->m_head.value);
      this->m_head = *actual->next;
    }

    delete actual;
  }

  void print_all()
  {
    auto p = &this->m_head;
    while (p) {
      fmt::print("print | addr: {}, value: {}, next: {}\n", fmt::ptr(p), p->value, fmt::ptr(p->next));
      p = p->next;
    }
  }

private:
  Node<T> create_node(T value) const
  {
    return Node<T>{ value, nullptr };
  }
};

int main()
{
  auto linked_list = LinkedList<uint32_t>(0);
  linked_list.append(1);
  linked_list.append(2);
  linked_list.append(3);
  linked_list.append(4);
  return 0;
}