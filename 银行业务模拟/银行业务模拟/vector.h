#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <algorithm>

// 定义一个模板类vector
template <typename T>
class vector {
private:
    T* data;         // 指向动态分配数组的指针
    size_t capacity; // 数组的容量
    size_t length;   // 数组中当前存储的元素数量
public:
    // 构造函数，初始化成员变量
    vector() : data(nullptr), capacity(0), length(0) {}

    // 析构函数，释放动态分配的内存
    ~vector() {
        delete[] data;
    }

    // push_back函数用于向数组末尾添加一个元素
    void push_back(const T& value) {
        if (length == capacity) { // 如果当前长度等于容量，需要扩容
            resize(capacity == 0 ? 1 : capacity * 2); // 容量翻倍或初始化为1
        }
        data[length++] = value; // 添加元素并更新长度
    }

    // pop_back函数用于移除数组末尾的元素
    void pop_back() {
        if (length > 0) { // 如果数组不为空
            --length; // 减少长度，实际上并不删除元素，只是不再访问它
        }
    }

    // 重载[]运算符，提供对元素的随机访问
    T& operator[](size_t index) {
        return data[index]; // 返回指定索引处的元素引用
    }

    // 重载[]运算符的常量版本，用于const对象
    const T& operator[](size_t index) const {
        return data[index]; // 返回指定索引处的元素常量引用
    }

    // size函数返回数组中当前存储的元素数量
    size_t size() const {
        return length;
    }

    // resize函数用于调整数组容量
    void resize(size_t new_capacity) {
        T* new_data = new T[new_capacity]; // 分配新的数组
        copy(data, data + length, new_data); // 将旧数组中的数据复制到新数组
        delete[] data; // 删除旧数组
        data = new_data; // 更新data指针指向新数组
        capacity = new_capacity; // 更新容量
    }
};

#endif