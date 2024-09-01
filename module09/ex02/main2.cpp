#include <iostream>
#include <variant>
#include <memory>

// Define the RecursivePair type
struct RecursivePair;
using RecursivePairVariant = std::variant<int, std::shared_ptr<std::pair<int, RecursivePair>>>;

struct RecursivePair {
    RecursivePairVariant value;

    // Constructor to allow initializing with an int
    RecursivePair(int val) : value(val) {}

    // Constructor to allow initializing with a pair of int and RecursivePair
    RecursivePair(int val, RecursivePair next)
        : value(std::make_shared<std::pair<int, RecursivePair>>(std::make_pair(val, next))) {}
};

// Function to process the recursive structure
void processRecursivePair(const RecursivePair& rp) {
    const auto* intPtr = std::get_if<int>(&rp.value);
    if (intPtr) {
        std::cout << "Value: " << *intPtr << std::endl;
    } else {
        const auto& pairPtr = std::get<std::shared_ptr<std::pair<int, RecursivePair>>>(rp.value);
        std::cout << "First: " << pairPtr->first << std::endl;
        processRecursivePair(pairPtr->second); // Recursively process the next pair
    }
}

int main() {
    // Example of creating a deeply nested recursive structure
    RecursivePair rp31 = RecursivePair(3);
    RecursivePair rp32 = RecursivePair(4);
    RecursivePair rp21 = RecursivePair(2, rp31);
    RecursivePair rp22 = RecursivePair(1, rp32);
    RecursivePair rp11 = RecursivePair(15, rp21);
    RecursivePair rp12 = RecursivePair(16, rp22);


    processRecursivePair(rp11);
    processRecursivePair(rp12);

    return 0;
}
