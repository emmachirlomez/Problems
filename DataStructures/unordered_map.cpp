#include<bits/stdc++.h>
#include <system_error>
using namespace std;

template <class T> 
class UnorderedMap {
    const int P = 107;
    vector <vector <pair <int, T>>> v;

    public:
    UnorderedMap(){
        v.resize(P);
    }

    void Set(int position, T value) {
        int hash = position % P;
        bool found = false;
        for (auto& [k, old_value] : v[hash])
            if (k == position)
                found  = true, old_value = value; 
        if (!found)
            v[hash].push_back({position, value});
    }

    T& Get(int position) {
        for (auto& [k, value] : v[position % P]) 
            if (k == position)
                return value;
        throw "Value not found"; 
    }

    T& operator[](int position) {
        try {
            return Get(position);
        }
        catch(...) {
            Set(position, T());
            return Get(position);
        }
        
    }
};

template<class T>
class Mytype {
    public:
    void Tell();
};

// template<class T>
// void Mytype<T>::Tell() {
//     cout << "I am a generic tell\n";
// }

template<>
class Mytype<int> {
    void Tell() {
        cout << "I am an int tell\n";
    }
};

int main() {
    // UnorderedMap<string> mp;
    // mp[0] = "hahah";
    // cout << mp[0] << '\n';
    // cout << mp.Get(2) << '\n';

    Mytype<int> a;
    Mytype<string> b;
    b.Tell();
    return 0;
}