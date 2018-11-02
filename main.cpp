#include <iostream>
#include "binary.cpp"

int main(int argc, char *argv[]) {
    std::cout << "===========================================================" << '\n';
    std::cout << "Binary Array Practice" << '\n';
    std::cout << "===========================================================" << "\n\n";

    boolean <char> test(16);
    test.print();
    test.bitOn(7);
    std::cout << test[7] << '\n';
    std::cout << test[7] << '\n';
    test.print();
    test.bitOff(7);
    std::cout << test[7] << '\n';
    test.bitOn(10);
    test.bitOn(11);
    std::cout << test[10] << '\n';
    std::cout << test[11] << '\n';
    test.print();
    test.clear();
    test.print();

    return 0;
}
