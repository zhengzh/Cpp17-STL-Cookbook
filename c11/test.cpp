#include <utility>
namespace std {
    // a function definition added to namespace std: undefined behavior
    pair<int, int> operator+(pair<int, int> a, pair<int, int> b) {
        return {a.first+b.first, a.second+b.second};
    }
}

int main() {
    // std::pair<int, int> 
    return 0;
}