#include "vector.hpp"

#include <iostream>

using biv::Vector;

template<typename T>
const std::size_t Vector<T>::START_CAPACITY = 10;

template<typename T>
Vector<T>::Vector() {
    arr = new T[START_CAPACITY];
    capacity = START_CAPACITY;
    size = 0;
}

template<typename T>
Vector<T>::~Vector() {
    if (arr) {
        delete[] arr;
    }
    arr=nullptr;
    size=0;
    capacity = 0;
}

template<typename T>
std::size_t Vector<T>::get_size() const noexcept {
    return size;
}

template<typename T>
bool Vector<T>::has_item(const T& value) const noexcept {
    for (std::size_t i = 0; i < size; i++ ){
        if (arr[i] == value){
            return true;
        }
    }
    return false;
}

template<typename T>
bool Vector<T>::insert(const std::size_t position, const T& value) {
    if (position>size){
        return false;
    }
    if (size==capacity){
        capacity+=100;
        T* new_arr = new T[capacity];
        std::copy(arr, arr+size, new_arr);
        delete[] arr;
        arr=new_arr;
    }
    for(size_t i=size;i>position;i--){
        arr[i]=arr[i-1];
    }
    arr[position]=value;
    ++size;
    return true;
}

template<typename T>
void Vector<T>::print() const noexcept {
    std::cout<<"[";
    for(int i = 0; i < size; i++){
        std::cout<<arr[i];
        if (i != size - 1) {
            std::cout << ", ";
        }
    }
    std::cout<<"]"<<std::endl;
}

template<typename T>
void Vector<T>::push_back(const T& value) {
    if (size == capacity){
        capacity+=100;
        T* new_arr = new T[capacity];
        std::copy(arr, arr+size, new_arr);
        delete[] arr;
        arr=new_arr;
    }
    arr[size]=value;
    ++size;
}

template<typename T>
bool Vector<T>::remove_first(const T& value) {
    if (capacity-size>200){
        capacity-=100;
        T* new_arr = new T[capacity];
        std::copy(arr, arr+size, new_arr);
        delete[] arr;
        arr=new_arr;
    }
    for(int i = 0; i < size; i++){
        if (arr[i]==value){
            for (std::size_t j = i; j < size - 1; ++j) {
                arr[j] = arr[j + 1];
            }
            --size;
            return true;
        }
    }
    return false;
}
