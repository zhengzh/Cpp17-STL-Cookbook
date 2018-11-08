#include <iostream>
//https://stackoverflow.com/questions/3601602/what-are-rvalues-lvalues-xvalues-glvalues-and-prvalues
//https://en.cppreference.com/w/cpp/language/value_category
//lvalue
//rvalue
//prvalue ("pure" rvalue) is an rvalue that is not an xvalue
//The result of calling a function whose return type is not a reference is a prvalue

// returns prvalue: plain auto never deduces to a reference
template < typename T > auto foo( T& t ) { return t.value() ; }

// return lvalue: auto& always deduces to a reference
template < typename T > auto& bar( T& t ) { return t.value() ; }

// return prvalue if t.value() is an rvalue
// return lvalue if t.value is an lvalue
// decltype(auto) has decltype semantics (without having to repeat the expression).
template < typename T > decltype(auto) foobar( T& t ) { return t.value() ; }

#define auto_init(variable, value) std::decay<decltype(value)>::type variable = value

template<typename T>
struct fo {
    T t;
};

template<typename T>
fo<typename std::decay<T>::type>
make_foo(T&& t)
{
    return { std::forward<T>(t) };
}

int main()
{
   struct A { int i = 0 ; int& value() { return i ; }; auto g(int a, int b){return a+b;};} a;
   struct B { int i = 0 ; int value() { return i ; } } b;

//    foo(a) = 20 ; // *** error: expression evaluates to prvalue of type int
   int &&e = foo(b) ; // fine: expression evaluates to prvalue of type int

   bar(a) = 20 ; // fine: expression evaluates to lvalue of type int
   
   int (*p)[5] = NULL;
   int &&x = 2;
   x+=3;
   a.g(2,3);
   int &d = bar(a);
//    bar(b) ; // *** error: auto& always deduces to a reference

   foobar(a) = 20 ; // fine: expression evaluates to lvalue of type int
   foobar(b) ; // fine: expression evaluates to prvalue of type int
}