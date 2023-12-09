
//
// Created by huangruidong on 2022/12/1.
//

#ifndef ALOGORITHM_STACK_H
#define ALOGORITHM_STACK_H

#include "Node.h"
#include "utility.h"

/**
 * 栈 \n
 * 使用链表为底层
 */
template <class Stack_entry>
class Stack {
public:
    //  Standard Stack methods
    Stack();
    bool empty() const;
    int size();
    Error_code push(const Stack_entry& item);
    Error_code pop();
    Stack_entry top() const;
    //  Safety features for linked structures
    ~Stack();
    Stack(const Stack& original);
    void operator =(const Stack<Stack_entry>& original);
protected:
    Node<Stack_entry>* top_node;
    int count;
};

template <class Stack_entry> Stack<Stack_entry>::Stack() {
    top_node == nullptr;
    count = 0;
}

template <class Stack_entry> bool Stack<Stack_entry>::empty() const {
    return count == 0;
}

template <class Stack_entry> Stack_entry Stack<Stack_entry>::top() const {
    if (empty()) return underflow;
    return top_node->entry;
}

template <class Stack_entry> Error_code Stack<Stack_entry>::push(const Stack_entry& item) {
    Node<Stack_entry>* new_top = new Node<Stack_entry>(item, top_node);
    if (new_top == nullptr)
        return overflow;
    top_node = new_top;
    count++;
    return success;
}

template <class Stack_entry> Error_code Stack<Stack_entry>::pop() {
    Node<Stack_entry>* old_top = top_node;
    if (top_node == nullptr) return underflow;
    top_node = old_top->next;
    delete old_top;
    count--;
    return success;
}

template <class Stack_entry> void Stack<Stack_entry>::operator = (const Stack& original) {
    Node<Stack_entry>* new_top, * new_copy, * original_node = original.top_node;
    if (original_node == nullptr) new_top = nullptr;
    else {
        new_top = new_copy = new Node<Stack_entry>(original_node->entry);
        while (original_node != nullptr) {
            original_node = original_node->next;
            new_copy->next = new Node<Stack_entry>(original_node->entry);
            new_copy = new_copy->next;
        }
    }
    while (!empty()) pop();
    top_node = new_top;
}

template <class Stack_entry> Stack<Stack_entry>::~Stack() {
    while (empty()) pop();
    count = 0;
}

template <class Stack_entry> Stack<Stack_entry>::Stack(const Stack& original) {
    Node<Stack_entry> *new_copy, *original_node = original.top_node;
    if (original_node == nullptr) top_node = nullptr;
    else {
        top_node = new_copy = new Node<Stack_entry>(original_node->entry);
        while (original_node != nullptr) {
            original_node = original_node->next;
            new_copy->next = new Node<Stack_entry>(original_node->entry);
            new_copy = new_copy->next;
        }
    }
}

template <class Stack_entry> int Stack<Stack_entry>::size() {
    return count;
}

#endif //ALOGORITHM_STACK_H
