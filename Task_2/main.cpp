#include <iostream>
#include "Struct.h"

void func(Call *call){
    std::cout << call->city.name;
}

int main(){
    Call call;
}