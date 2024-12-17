#pragma once
#include <string>

typedef struct Client{
    std::string last_name;
    std::string first_name;
    std::string patronymic;
    std::string street;
    int house;
    int flat;
    int discount;
} Client;