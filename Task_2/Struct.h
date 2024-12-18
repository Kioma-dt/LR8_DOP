#include <string>

typedef union City{
    std::string name;
    int code;
} City;

typedef struct Call{
    std::string date;
    City city;

    // Call(const Call &other)
    //     : date(other.date) {
    //     city.name = other.city.name;
    //     city.code=other.city.code  // Копируем содержимое union
    // }

    // // Оператор присваивания
    // Call& operator=(const Call &other) {
    //     if (this == &other) return *this;

    //     date= other.date;
        
    //     city.code = other.city.code;
    //     city.name = other.city.name; // Копируем содержимое union

    //     return *this;
    // }

} Call;
