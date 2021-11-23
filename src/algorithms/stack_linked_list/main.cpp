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
    this->m_head = this->create_node(value);
  }

  void insert(Node<T> *at, Node<T> *node)
  {
    auto after = at->next;
    at->next = node;
    node->next = after;
    fmt::print("insert | previous: {}, node: {}, after: {}\n", fmt::ptr(at), fmt::ptr(node), fmt::ptr(after));
  }

  void append(Node<T> *node)
  {
    auto p = &this->m_head;

    while (p->next)
      p = p->next;

    p->next = node;

    fmt::print("push | previous: {}, node: {}\n", fmt::ptr(p), fmt::ptr(node));
  }

  void remove(Node<T> *node)
  {
    auto previous = &this->m_head;
    assert(previous != node);

    auto p = previous->next;
    while (p != node) {
      previous = p;
      p = p->next;
    }

    previous->next = p->next;

    fmt::print("remove | node: {}\n", fmt::ptr(node));
  }

  void pop()
  {
    Node<T> *previous = nullptr;
    auto node = &this->m_head;

    while (node->next) {
      previous = node;
      node = node->next;
    }

    previous->next = nullptr;

    fmt::print("pop | node: {}\n", fmt::ptr(node));
  }

  void print_all()
  {
    auto p = &this->m_head;
    while (p) {
      fmt::print("print | addr: {}, p.value: {}, p.next: {}\n", fmt::ptr(p), p->value, fmt::ptr(p->next));
      p = p->next;
    }
  }

  Node<T> create_node(T value) const
  {
    return Node<T>{ value, nullptr };
  }
};

int main()
{
  auto linked_list = LinkedList<uint32_t>(1);
  auto second = linked_list.create_node(2);
  auto third = linked_list.create_node(3);
  auto fourth = linked_list.create_node(4);

  linked_list.append(&second);
  linked_list.append(&third);
  linked_list.append(&fourth);

  return 0;
}