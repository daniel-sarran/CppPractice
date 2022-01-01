#include <iostream>
#include <unordered_map>
#include <vector>

int main() {
    // Initializing a vector
    std::vector<int> values = {1, 2, 3, 4, 5};

    // Value through indexing loop
    for (int i = 0; i < values.size(); i++) {
        std::cout << values[i] << " ";
    }
    std::cout << std::endl;

    // Value through iterator
    for (int value : values) {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    // Both value and index through iterator, a-la enumerate
    for (std::vector<int>::iterator it = values.begin(); it != values.end();
         it++) {
        std::cout << "(" << *it << " index: " << it - values.begin() << "), ";
    }
    std::cout << std::endl;

    // Useful in case a different data structure that isn't contiguous
    // with a map, you can ONLY traverse with an iterator
    using ScoreMap = std::unordered_map<std::string, int>;
    ScoreMap map;
    map["Daniel"] = 35;
    map["Enzo"] = 5;

    for (ScoreMap::const_iterator it = map.begin(); it != map.end(); it++) {
        // *it better to use arrow operator it->
        auto& key = it->first;     // first is the key
        auto& value = it->second;  // second is value
        std::cout << key << " = " << value << std::endl;
    }

    // Can we use range based for loops but with a map?
    for (auto kv : map) {
        // retrieves the pair (and std pair) of first/second aka key/value
        auto& key = kv.first;
        auto& value = kv.second;
        std::cout << key << " = " << value << std::endl;
    }

    // Even further, using C++ 17 syntax :chef's kiss:
    for (auto [key, value] : map) {
        std::cout << key << " = " << value << std::endl;
    }
}