#include <bits/stdc++.h>
using namespace std;

template<class Value>
class HashTable
{
    int mod;
    vector<int> head;
    struct Node
    {
        Value val;
        int key;
        int next;
    };

    vector<Node> nodes;

public:
    HashTable(int dim) : mod(dim), head(dim, -1)  {}
    
    optional<Value> find(int key) {
        int poz_node = head[key % mod];
        for (int i = poz_node; i != -1; i = nodes[i].next) {
            if (nodes[i].key == key) {
                return nodes[i].val;
            }
        }
        return {};
    }
};

int main()
{
    int a(10);
}