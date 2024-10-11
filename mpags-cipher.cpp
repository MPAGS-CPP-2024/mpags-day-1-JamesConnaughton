#include <iostream>

int main(){
    // This is a comment
    /* This is a 
    Multiline comment*/

    int a{5};
    std::cout << "a is " << a << std::endl;
    a = 7;
    std::cout << "a is " << a << std::endl;

    double b{3.6};
    std::cout << "b is " << b << std::endl;
    b = 4.8;
    std::cout << "b is " << b << std::endl;

    // int c = a + b; This DOESN't give the compiler error 
    int c{a + b};
    std::cout << "c is " << c << std::endl;
}