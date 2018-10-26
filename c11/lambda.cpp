#include <iostream>
#include <algorithm>
#include <string>
#include <functional>

// using namespace std::string_literals;
template <typename T>
struct TD;

template<class T>
void f(T para) {
    para = 2;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};

    int mul = 5;

    int& rmul = mul;
    auto amul = rmul;
    auto&& v6 = 2;

    std::for_each(arr, arr + sizeof(arr) / sizeof(int), [&](int x) {
        std::cout << x << " ";
        // Can modify the mul inside this lambda function because
        // all outer scope elements has write access here.
        int y = 4;
        mul = 3;
    });
    std::cout << std::endl;

    std::for_each(arr, arr + sizeof(arr) / sizeof(int), [=](int &x) {
        x = x * mul;
        // Can not modify the mul inside this lambda function because
        // all outer scope elements has read only access here.
        // mul = 9;
    });
    std::cout << std::endl;
    std::function<void(int)> h;
    auto g = [](int x) { return 2;};

    std::for_each(arr, arr + sizeof(arr) / sizeof(int), [mul](int &x) {
        x = x * mul;
        // Can not modify the mul inside this lambda function because
        // all outer scope elements has read only access here.
        // mul = 9;
    });

    // auto s = "hh"s;
    std::cout << std::endl;
    // std::cout << "hh"s << std::endl;
    std::cout << __cplusplus << std::endl;

    std::for_each(arr, arr + sizeof(arr) / sizeof(int), [](int x) {
        // No access to mul inside this lambda function because
        // all outer scope elements are not visible here.
        //std::cout<<mul<<" ";
    });
    std::cout << std::endl;
}