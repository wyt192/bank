#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <algorithm>

// ����һ��ģ����vector
template <typename T>
class vector {
private:
    T* data;         // ָ��̬���������ָ��
    size_t capacity; // ���������
    size_t length;   // �����е�ǰ�洢��Ԫ������
public:
    // ���캯������ʼ����Ա����
    vector() : data(nullptr), capacity(0), length(0) {}

    // �����������ͷŶ�̬������ڴ�
    ~vector() {
        delete[] data;
    }

    // push_back��������������ĩβ���һ��Ԫ��
    void push_back(const T& value) {
        if (length == capacity) { // �����ǰ���ȵ�����������Ҫ����
            resize(capacity == 0 ? 1 : capacity * 2); // �����������ʼ��Ϊ1
        }
        data[length++] = value; // ���Ԫ�ز����³���
    }

    // pop_back���������Ƴ�����ĩβ��Ԫ��
    void pop_back() {
        if (length > 0) { // ������鲻Ϊ��
            --length; // ���ٳ��ȣ�ʵ���ϲ���ɾ��Ԫ�أ�ֻ�ǲ��ٷ�����
        }
    }

    // ����[]��������ṩ��Ԫ�ص��������
    T& operator[](size_t index) {
        return data[index]; // ����ָ����������Ԫ������
    }

    // ����[]������ĳ����汾������const����
    const T& operator[](size_t index) const {
        return data[index]; // ����ָ����������Ԫ�س�������
    }

    // size�������������е�ǰ�洢��Ԫ������
    size_t size() const {
        return length;
    }

    // resize�������ڵ�����������
    void resize(size_t new_capacity) {
        T* new_data = new T[new_capacity]; // �����µ�����
        copy(data, data + length, new_data); // ���������е����ݸ��Ƶ�������
        delete[] data; // ɾ��������
        data = new_data; // ����dataָ��ָ��������
        capacity = new_capacity; // ��������
    }
};

#endif