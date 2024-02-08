#include <bintree/bintree.h>
#include <vector>
#include <stdexcept>
#include <iostream>
#include <chrono>
#include <iomanip>


using namespace std;


size_t lcg(size_t& i) {
    return (i * 1021 + 24631) % 116640;
}


int main() {
    

    Binary_tree set1000;
    auto begin = std::chrono::steady_clock::now();
    for (size_t j = 0; j < 100; j++)
        for (size_t i = 0; i < 1000; i++)
            set1000.insert(lcg(i));
    auto end = std::chrono::steady_clock::now();

    auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
    //std::cout << "The time: " << elapsed_ms.count() << " ms\n";
    std::cout << "Avg time for insert 1000: " << std::fixed << std::setprecision(6) << static_cast<double>(elapsed_ms.count()) / 100 << " ms\n";

     begin = std::chrono::steady_clock::now();
    for (size_t j = 0; j < 100; j++)
        for (size_t i = 0; i < 1000; i++)
            set1000.contains(lcg(i));
    end = std::chrono::steady_clock::now();

    elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
    //std::cout << "The time: " << elapsed_ms.count() << " ms\n";
    std::cout << "Avg time for search 1000: " << std::fixed << std::setprecision(6) << static_cast<double>(elapsed_ms.count()) / 100 << " ms\n";

}