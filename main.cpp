#include <iostream>
#include "binary.cpp"

using namespace std;

int main(int argc, char *argv[]) {
    cout << "===========================================================" << endl;
    cout << "Binary Array Practice" << endl;
    cout << "===========================================================" << endl << endl;

    boolean test(24);
    test.bitOn(7);
    cout<<test[7]<<endl;
    cout<<test[7]<<endl;
    test.print();
    test.bitOff(7);
    cout<<test[7]<<endl;
    test.bitOn(10);
    test.bitOn(11);
    cout<<test[10]<<endl;
    cout<<test[7]<<endl;
    test.print();

    return 0;
}
