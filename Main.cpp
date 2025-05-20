#include "SmartString.h"
#include <iostream>

int main() {
    SmartString text = "  Hello, World!  ";
    
    // Demonstration of features
    std::cout << "Original: '" << text.toString() << "'" << std::endl;
    std::cout << "Trimmed: '" << text.trim().toString() << "'" << std::endl;
    std::cout << "Uppercase: '" << text.trim().toUpper().toString() << "'" << std::endl;
    
    SmartString csv = "apple,orange,banana,grape";
    auto fruits = csv.split(",");
    
    std::cout << "\nFruits:" << std::endl;
    for (const auto& fruit : fruits) {
        std::cout << "- " << fruit.toString() << std::endl;
    }
    
    return 0;
}