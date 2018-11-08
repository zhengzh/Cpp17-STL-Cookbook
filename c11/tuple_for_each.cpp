    #include <string>
    #include <iostream>
    #include <tuple>
 
    namespace detail
    {
        template<int... Is>
        struct seq { };
 
        template<int N, int... Is>
        struct gen_seq : gen_seq<N - 1, N - 1, Is...> { };
 
        template<int... Is>
        struct gen_seq<0, Is...> : seq<Is...> { };
 
        template<typename T, typename F, int... Is>
        void for_each(T&& t, F f, seq<Is...>)
        {
            auto l = { (f(std::get<Is>(t)), 0)... };
        }
    }
 
    template<typename... Ts, typename F>
    void for_each_in_tuple(std::tuple<Ts...> const& t, F f)
    {
        detail::for_each(t, f, detail::gen_seq<sizeof...(Ts)>());
    }
 
    struct my_functor
    {
        template<typename T>
        void operator () (T&& t)
        {
            std::cout << t << std::endl;
        }
    };
 
    int main()
    {
        std::pair a {1, 'a'};
        int n = 1;
        std::tuple<int*, double, std::string> t(&n, 3.14, "Hello World!");
        for_each_in_tuple(t, [](auto&& t){std::cout << t << std::endl;});
        // for_each_in_tuple(t, my_functor());
    }
