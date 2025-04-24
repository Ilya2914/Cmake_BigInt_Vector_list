#include "doubly_linked_list.hpp"

#include <iostream>

using biv::DoublyLinkedList;

template<typename T>
DoublyLinkedList<T>::~DoublyLinkedList() {
    Node* current = begin;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
}

template<typename T>
std::size_t DoublyLinkedList<T>::get_size() const noexcept {
    std::size_t size = 0;
        Node* current = begin;
        while (current != nullptr) {
            size++;
            current = current->next;
        }
        return size;
}

template<typename T>
bool DoublyLinkedList<T>::has_item(const T& value) const noexcept {
    Node* current =begin;
    while(current != nullptr){
        if (current->value==value){
            return true;
        }
        current=current->next;
    }
    return false;
}

template<typename T>
void DoublyLinkedList<T>::print() const noexcept {
    Node* current =begin;
    std::cout<<"[";
    while(current!=nullptr){
        std::cout<<current->value;
        if (current->next != nullptr){
            std::cout<<",";
        }
        current=current->next;
    }
    std::cout<<"]"<<std::endl;
}

template<typename T>
void DoublyLinkedList<T>::push_back(const T& value) {
    Node* new_Node=new Node(value);
    if(end == nullptr and begin==nullptr){
        begin=end=new_Node;
    }
    else{
        new_Node->prev = end;
        end->next = new_Node;
        end=new_Node;
    }

    
}

template<typename T>
bool DoublyLinkedList<T>::remove_first(const T& value) noexcept {
    Node* current=begin;
    while(current!=nullptr){
        if (current->value==value){
            if (current->prev != nullptr) {
                current->prev->next = current->next;
            } else {
                begin = current->next;
            }
            
            if (current->next != nullptr) {
                current->next->prev = current->prev;
            } else {
                end = current->prev;
            }
            
            delete current;
            return true;
        }
        current=current->next;
    }
    return false;
}
template class biv::DoublyLinkedList<int>;
template class biv::DoublyLinkedList<double>;
template class biv::DoublyLinkedList<std::string>;

