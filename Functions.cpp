#include <iostream>
#include <string>
#include "Struct.h"

Client *AddSpace(Client *client, int *size){
    Client *new_client = new Client[*size + 1];
    for (int i = 0; i < *size; i++) {
        new_client[i] = client[i];
    }
    delete[] client;
    (*size)++;

    return new_client;
}

Client *DeleteSpace(Client *client, int *size){
    Client *new_client = new Client[*size - 1];
    for (int i = 0; i < *size - 1; i++) {
        new_client[i] = client[i];
    }
    delete[] client;
    (*size)--;

    return new_client;
}

void EnterClient(Client *client, std::string special_steet, int special_discount){
    std::cout << "Введите фамилию: ";
    std::cin >> client->last_name;
    std::cout << "Введите имя: ";
    std::cin >> client->first_name;
    std::cout << "Введите отчество: ";
    std::cin >> client->patronymic;
    std::cout << "Введите улицу, на которой проживает клиент: ";
    std::cin >> client->street;
    std::cout << "Введите дом, в котором проживает клиент: ";
    std::cin >> client->house;
    std::cout << "Введите квартиру, в которой проживает клиент: ";
    std::cin >> client->flat;
    if (client->street == special_steet)
    {
        client->discount = special_discount;
    }
    else
    {
        std::cout << "Введите скидку: ";
        std::cin >> client->discount;
    }
}

Client *EnterWithSize(int size, std::string special_steet, int special_discount){
    Client *client = new Client[size];

    for (int i = 0; i < size; i++){
        std::cout << i + 1 << " клиент\n";
        EnterClient(client + i, special_steet, special_discount);
    }
    return client;
}

Client *EnterWithStop(int *size, std::string special_steet, int special_discount){
    int stop_discount;
    std::cout << "Введите максимальную скидку, после которой прекращается ввод: ";
    std::cin >> stop_discount;
    Client *client;
    do
    {
        client = AddSpace(client, size);
        std::cout << *size << " клиент\n";
        EnterClient(client + *size - 1, special_steet, special_discount);
    } while (client[*size - 1].discount < stop_discount);

    return client;
}

Client *EnterWithDialog(int *size, std::string special_steet, int special_discount){
    Client *client;
    bool exit;
    while (1){
        client = AddSpace(client, size);
        std::cout << *size << " клиент\n";
        EnterClient(client + *size - 1, special_steet, special_discount);
        std::string input;
        std::cout << "Продолжить(y/n)\n";
        std::cin >> input;
        while (input != "n" && input != "y"){
            std::cout << "Неверный символ!\n";
            std::cin >> input;
        }
        if (input == "n"){
            break;
        }
    }

    return client;
}

void OutputClient(Client client){
    std::cout << "Фамилия: ";
    std::cout << client.last_name;
    std::cout << "\nИмя: ";
    std::cout << client.first_name;
    std::cout << "\nОтчество: ";
    std::cout << client.patronymic;
    std::cout << "\nУлица, на которой проживает клиент: ";
    std::cout << client.street;
    std::cout << "\nДом, в котором проживает клиент: ";
    std::cout << client.house;
    std::cout << "\nКвартира, в которой проживает клиент: ";
    std::cout << client.flat;
    std::cout << "\nСкидка: ";
    std::cout << client.discount << '%';
    std::cout << "\n";
}

void ShowInformation(Client* client, int size){
    if (size == 0){
        std::cout << "Нет клиентов!\n";
        return;
    }
    int number;
    std::cout << "Введите номер клиента (0 - показать всех клиентов): ";
    std::cin >> number;
    if (number == 0){
        for (int i = 0; i < size;i++){
            std::cout << i + 1 << " клиент\n";
            OutputClient(client[i]);
            std::cout << '\n';
        }
    }
    else {
        std::cout << number << " клиент\n";
        OutputClient(client[number - 1]);
        std::cout << '\n';
    }
}

Client *AddClient(Client * client, int * size, std::string special_steet, int special_discount){
    client = AddSpace(client, size);
    EnterClient(client + *size - 1, special_steet, special_discount);

    return client;
}

int FindClient(Client * client, int start, int end, int n_feature, int feature){
    for (int i = start; i < end;i++){
        switch(n_feature){
        case 5:
            if (client[i].house == feature){
                return i;
            }
            break;
        case 6:
            if (client[i].flat == feature){
                return i;
            }
            break;
        case 7:
            if (client[i].discount == feature){
                return i;
            }
            break;
        }
    }

    return -1;
}

int FindClient(Client * client, int start, int end, int n_feature, std::string feature){
    for (int i = start; i < end;i++){
        switch(n_feature){
        case 1:
            if (client[i].last_name == feature){
                return i;
            }
            break;
        case 2:
            if (client[i].first_name == feature){
                return i;
            }
            break;
        case 3:
            if (client[i].patronymic == feature){
                return i;
            }
            break;
        case 4:
            if (client[i].street == feature){
                return i;
            }
            break;
        }
    }

    return -1;
}

Client *DeleteClient(Client * client, int * size, int number){
    for (int i = number + 1; i < *size; i++){
        std::swap(client[i], client[i - 1]);
    }
    client = DeleteSpace(client, size);

    return client;
}

Client *ChooseForDelete(Client *client, int *size){
    if (*size == 0){
        std::cout << "Нет клиентов!\n";
        return client;
    }
    int input, feature_i, find;
    std::string feature_s;
    std::cout << "Введите признак, по которому необходимо удалить клиента:\n";
    std::cout << "1 - Фамилия\n2 - Имя\n3 - Отчечтво\n4 - Улица\n5 - Дом\n6 - Квартира\n7 - Скидка\n8 - Номер\n";
    while (1){
        std::cin >> input;
        if (input <= 8 && input >= 1){
            break;
        }
        std::cout << "Неверный номер!\n";
    }

    if (input == 8){
        std::cout << "Введите номер клинта, которого необходимо удалить: ";
        std::cin >> feature_i;
        client = DeleteClient(client, size, feature_i - 1);
    }
    else if (input >= 5){
        std::cout << "Введите значение признака: ";
        std::cin >> feature_i;
        find = FindClient(client, 0, *size, input, feature_i);
        while (find != -1){
            client = DeleteClient(client, size, find);
            find = FindClient(client, find, *size, input, feature_i);
        }
    }
    else {
        std::cout << "Введите значение признака: ";
        std::cin >> feature_s;
        find = FindClient(client, 0, *size, input, feature_s);
        while (find != -1){
            client = DeleteClient(client, size, find);
            find = FindClient(client, find, *size, input, feature_s);
        }
    }

    return client;
}

Client *ChooseForChange(Client * client, int size){
    if (size == 0){
        std::cout << "Нет клиентов!\n";
        return client;
    }
    int number;
    std::cout << "Введите номер клиента, данные которого вы хотите поменять: ";
    std::cin >> number;
    number--;
    bool exit = false;
    while (!exit){
        std::cout << "Выберите, что вы хотите поменять:\n";
        std::cout << "1 - Фамилия\n2 - Имя\n3 - Отчечтво\n4 - Улица\n5 - Дом\n6 - Квартира\n7 - Скидка\n8-Выйти\n";
        int input;
        switch(input){
        case 1:
            std::cout << "Введите новую фамилию: ";
            std::cin >> client[number].last_name;
            break;
        case 2:
            std::cout << "Введите новое имя: ";
            std::cin >> client[number].first_name;
            break;
        case 3:
            std::cout << "Введите новое отчество: ";
            std::cin >> client[number].patronymic;
            break;
        case 4:
            std::cout << "Введите новую улицу: ";
            std::cin >> client[number].street;
            break;
        case 5:
            std::cout << "Введите новый дом: ";
            std::cin >> client[number].house;
            break;
        case 6:
            std::cout << "Введите новую квартиру: ";
            std::cin >> client[number].flat;
            break;
        case 7:
            std::cout << "Введите новую скидку: ";
            std::cin >> client[number].discount;
            break;
        case 8:
            exit = true;
            break;
        default:
            std::cout << "Неверный номер!\n";
        }
    }

    return client;
}

void ChooseForFind(Client * client, int size){
    if (size == 0){
        std::cout << "Нет клиентов!\n";
        return ;
    }
    int input, feature_i;
    std::string feature_s;
    int find;
    std::cout << "Введите признак, по которому необходимо вывести клиента:\n";
    std::cout << "1 - Фамилия\n2 - Имя\n3 - Отчечтво\n4 - Улица\n5 - Дом\n6 - Квартира\n7 - Скидка\n";
    while (1){
        std::cin >> input;
        if (input <= 8 && input >= 1){
            break;
        }
        std::cout << "Неверный номер!\n";
    }

    if (input >= 5){
        std::cout << "Введите значение признака: ";
        std::cin >> feature_i;
        find = FindClient(client, 0, size, input, feature_i);
        if (find == -1){
            std::cout << "Нет таких клиентов!\n";
            return;
        }
        while (find != -1){
            std::cout << find + 1 << " клиент\n";
            OutputClient(client[find]);
            find = FindClient(client, find + 1, size, input, feature_i);
        }
    }
    else {
        std::cout << "Введите значение признака: ";
        std::cin >> feature_s;
        find = FindClient(client, 0, size, input, feature_s);
        if (find == -1){
            std::cout << "Нет таких клиентов!\n";
            return;
        }
        while (find != -1){
            std::cout << find + 1 << " клиент\n";
            OutputClient(client[find]);
            find = FindClient(client, find + 1, size, input, feature_s);
        }
    }
}

void Sort(Client * client, int size) {
    for (int i = 1; i < size;i++){
        for (int j = i; j > 0 && client[j - 1].discount > client[j].discount; j--){
            std::swap(client[j - 1], client[j]);
        }
    }
}

void FindDiscount(Client * client, int size) {
    Sort(client, size);
    int right = size - 1, left = 0, middle = (right - left) / 2;

    while(right > left && client[middle].discount != 5){
        middle = (right - left) / 2;
        if (client[middle].discount > 5){
            right = middle;
        }
        else {
            left = middle + 1;
        }
    }

    if (client[middle].discount != 5){
        std::cout << "Нет клиентов со скидкой 5%!\n";
    }
    else{
        while (middle != 0 && client[middle - 1].discount == 5){
            middle--;
        }
        while (client[middle].discount == 5){
            std::cout << middle + 1 << " клиент\n";
            OutputClient(client[middle]);
            middle++;
        }
    }
}