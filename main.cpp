#include <iostream>
#include <string>
#include "Functions.h"

int main(){
    bool exit = false;
    Client *client;
    int size = 0;
    std::string special_street;
    int special_discount = -1;

    while (!exit){
        std::cout << "Выберите способ ввода данных о клиентах:\n";
        std::cout << "1 - Ввести количество клинтов\n";
        std::cout << "2 - Вводить клиенто пока не всретится со скидкой больше заданной\n";
        std::cout << "3 - Диалог\n";
        std::cout << "4 - Добавить определенную скидке, проживающим на определенной улице\n";
        int input;
        std::cin >> input;
        switch (input){
        case 1:
            std::cout << "Введите количество клинтов: ";
            std::cin >> size;
            client = EnterWithSize(size, special_street, special_discount);
            exit = true;
            break;
        case 2:
            client = EnterWithStop(&size, special_street, special_discount);
            exit = true;
            break;
        case 3:
            client = EnterWithDialog(&size, special_street, special_discount);
            exit = true;
            break;
        case 4:
            std::cout << "Введите специальную улицу: ";
            std::cin >> special_street;
            std::cout << "Введите специальную скидку: ";
            std::cin >> special_discount;
            break;
        default:
            std::cout << "Неверный номер!\n";
        }
    }

    exit = false;
    while (!exit){
        std::cout << "\n-----------------------------------\n";
        std::cout << "Выберите действие:\n";
        std::cout << "1 - показать информацию\n";
        std::cout << "2 - добавить клиента\n";
        std::cout << "3 - удалить клиента\n";
        std::cout << "4 - изменить информацию о клиенте\n";
        std::cout << "5 - найти клиента\n";
        std::cout << "6 - отсортировать клиентов по возрастанию скидки\n";
        std::cout << "7 - вывести клиентов со скидкой 5%(при этом клиенты будут отсортированы по возрастанию скидки)\n";
        std::cout << "8 - выйти\n";
        int input;
        std::cin >> input;
        switch (input){
        case 1:
            ShowInformation(client, size);
            break;
        case 2:
            client = AddClient(client, &size, special_street, special_discount);
            break;
        case 3:
            client = ChooseForDelete(client, &size);
            break;
        case 4:
            client = ChooseForChange(client, size);
        case 5:
            ChooseForFind(client, size);
            break;
        case 6:
            Sort(client, size);
            break;
        case 7:
            FindDiscount(client, size);
            break;
        case 8:
            exit = true;
            break;
        default:
            std::cout << "Неверный номер!\n";
        }
    }

    delete[] client;
}