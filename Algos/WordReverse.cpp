#include <string>
#include <vector>
#include <iostream>
#include <bitset>

/**
 * This function takes a string made of words separated with spaces
 * and reverse the order of the words.
 *
 * input:
 * "A fost odata"
 *
 * output:
 * "odata fost A"
 *
 */
std::string ReverseString(std::string sentence)
{
}

struct MyStruct
{
    long long a;
    char b;
    int c;
};

MyStruct example[3];
int haha;

void PrintMemory(void *data, int nr_bytes)
{
    for (int i = 0; i < nr_bytes; i++)
    {
        char b = *((char *)(data + i));
        std::cout << std::bitset<8>(b) << " ";
    }
}

int main()
{
    // example[0].a = 1;
    // example[0].b = 'a';
    // example[0].c = 0xFF3355E;
    void *p = example;

    *(long long *)p = 1;
    *(char *)(p + 8) = 'a';
    *(int *)(p + 12) = 0xFF3355E;

    example[1].a = 2;
    example[1].b = 'b';
    example[2].a = 3;
    example[2].b = 'c';

    std::vector<int> v(5);
    v.push_back(6);

    int x[10];
    int *ptr = &x[0];

    // PrintMemory(example, 16);
    std::cout << "Example:     " << example << '\n';
    std::cout << "Haha:        " << &haha << '\n';
    std::cout << "Main:        " << (void *)main << '\n';
    std::cout << "PrintMemory: " << (void *)PrintMemory << '\n';
    std::cout << "p:           " << &p << '\n';
    std::cout << "v:           " << &v << '\n';
    std::cout << "elemente v   " << v.data() << '\n';
    std::cout << "elemente v   " << &v.operator[](0) << '\n';
    std::cout << "Size of v:   " << sizeof(v) << '\n';
    PrintMemory((void *)&v, 8);
    std::cout << '\n';
    PrintMemory(((void *)&v) + 8, 8);
    std::cout << '\n';
    PrintMemory((void *)(&v + 8), 8);
    std::cout << '\n';
    PrintMemory(((void *)&v) + 16, 8);
    std::cout << '\n';
}
