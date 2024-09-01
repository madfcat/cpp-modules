#include <iostream>
#include <variant>
#include <memory>

// Define the RecursivePair structure
struct RecursivePair;
using RecursivePairVariant = std::variant<std::pair<int, int>, std::shared_ptr<std::pair<int, RecursivePair>>>;

struct RecursivePair {
    RecursivePairVariant value;

    // Constructor for the base case: pair<int, int>
    RecursivePair(int first, int second) : value(std::make_pair(first, second)) {}

    // Constructor for the recursive case: pair<int, RecursivePair>
    RecursivePair(int first, RecursivePair next)
        : value(std::make_shared<std::pair<int, RecursivePair>>(std::make_pair(first, next))) {}
};

// Function to process the recursive structure
void processRecursivePair(const RecursivePair& rp) {
    if (std::holds_alternative<std::pair<int, int>>(rp.value)) {
        const auto& basePair = std::get<std::pair<int, int>>(rp.value);
        std::cout << "Base Pair: (" << basePair.first << ", " << basePair.second << ")" << std::endl;
    } else {
        const auto& recursivePair = std::get<std::shared_ptr<std::pair<int, RecursivePair>>>(rp.value);
        std::cout << "First: " << recursivePair->first << std::endl;
        processRecursivePair(recursivePair->second); // Recursively process the next level
    }
}

int main() {
    // Create a deeply nested recursive structure
    RecursivePair base = RecursivePair(3, 4); // Base level: (3, 4)
    RecursivePair level2 = RecursivePair(2, base); // Level 2: (2, (3, 4))
    RecursivePair level1 = RecursivePair(1, level2); // Level 1: (1, (2, (3, 4)))

    // Process the recursive structure
    processRecursivePair(level1);

    return 0;
}
