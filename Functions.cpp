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
    std::cout << client.discount;
    std::cout << "\n";
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
    for (int i = number; i < *size; i++){
        std::swap(client[i], client[i - 1]);
    }
    client = DeleteSpace(client, size);

    return client;
}

Client *ChooseForDelete(Client *client, int *size){
    int input;
    int feature_i;
    int find;
    std::string feature_s;
    std::cout << "Введите признак, по которому необходимо удалить клиента:\n";
    std::cout << "1 - Фамилия\n2 - Имя\n3 - Отчечтво\n4 - Улица\n5 - Дом\n6 - Квартира\n7 - Скидка\n8 - Номер";
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
        DeleteClient(client, size, feature_i);
    }
    if (input >= 5){
        std::cout << "Введите значение признака: ";
        std::cin >> feature_i;
        find = FindClient(client, 0, *size, input, feature_i);
        while (find != -1){
            DeleteClient(client, size, find);
            find = FindClient(client, find + 1, *size, input, feature_i);
        }
    }
    else {
        std::cout << "Введите значение признака: ";
        std::cin >> feature_s;
        find = FindClient(client, 0, *size, input, feature_s);
        while (find != -1){
            DeleteClient(client, size, find);
            find = FindClient(client, find + 1, *size, input, feature_s);
        }
    }

    return client;
}