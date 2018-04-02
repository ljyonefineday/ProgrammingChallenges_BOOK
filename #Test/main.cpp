#include <iostream>

int main(void){

    int a(1);
    char b('3');

    int test(a+(int)b);
    char test2(a);

    std::cout<<a<<std::endl;
    std::cout<<test2<<std::endl;
    std::cout<<b<<std::endl;
    std::cout<<test<<std::endl;

    return 0;
}