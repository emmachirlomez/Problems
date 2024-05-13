#include <bits/stdc++.h>
#include <cstddef>
#include <exception>
#include <optional>
using namespace std;

template<class T> 
class Vector {
    T *buff;
    size_t allocated, used;
public:
    Vector();
    ~Vector();
    const Vector& operator=(const Vector<T>& oth);
    Vector(const Vector<T>& oth);
    T& operator[](size_t index);
    void push_back(T val);
    T pop_back();
    size_t size();
    optional<T> at(std::size_t index);
};

template<class T>
Vector<T>::Vector() {
    buff = nullptr;
    allocated = used = 0;
}

template<class T>
Vector<T>::~Vector(){
    delete[] buff;
}

template<class T>
const Vector<T>& Vector<T>::operator=(const Vector<T>& oth) {
    delete[] buff;
    if (oth.allocated == 0) {
        buff = nullptr;
        allocated = used = 0;
        return *this;
    }
    buff = new T[oth.allocated];
    allocated = oth.allocated;
    used = oth.used;
    copy(oth.buff, oth.buff + oth.used, buff);
    return *this;
}

template<class T>
Vector<T>::Vector(const Vector<T>& oth) {
    buff = nullptr;
    *this = oth;
}

template<class T>
T& Vector<T>::operator[](size_t index) {
    return buff[index];
}

template<class T>
void Vector<T>::push_back(T val) {
    if (allocated == used) {
        size_t new_size = 2 * max(allocated, size_t(1));
        T *new_buff = new T[new_size];
        copy(buff, buff + used, new_buff);
        allocated = new_size;
        delete[] buff;
        buff = new_buff;
    }

    buff[used] = val;
    used++;
}

template<class T>
T Vector<T>::pop_back() {
    if (used == 0)
        throw "Cannot pop back from empty Vector";
    used--;
    T val = buff[used];
    buff[used] = T();
    return val;
}

template<class T>
size_t Vector<T>::size() {
    return used;
}

template<class T>
optional<T> Vector<T>::at(size_t index) {
    if (index >= used )
        return {};
    return buff[index];
}

int main() {
    Vector<int> x;
    x.push_back(4);
    cout << x.size() << '\n';
    x.push_back(5);
    x.push_back(6);
    x.push_back(7);
    x.pop_back();
    cout << (x.at(x.size() - 1).value() == 6) << '\n';

    Vector<int> y, z;
    y = (z = x);
    cout << x[2] << '\n';
    x[1] = 5;
}