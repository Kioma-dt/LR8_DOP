#pragma once
#include "Struct.h"
#include "Functions.cpp"

int CheckUnsigned();
int CheckDiscount();
int CheckNumberOfArray(int);
bool CheckSreetOrDistrict();
void swap_struct(Client *, Client *);
void EnterClient(Client *, std::string, int);        // Ввести данные об одном клиента(структуру)
Client *EnterWithSize(int, std::string, int, int);        // Ввод заранее заданного количества
Client *EnterWithStop(int *, std::string, int, int);      // Ввод до появление структуры с определенным свойством
Client *EnterWithDialog(int *, std::string, int, int);    // Диалог с пользователем о необходимости продолжать ввод
void OutputClient(Client *, int);                    // Вывод информации об одном клиенте
void ShowInformation(Client *, int);                 // Диалог для выводв информации о клиентах
Client *AddClient(Client *, int *, std::string, int, int);   // Добавить еще одного клиента в конец списка
int FindClient(Client *, int, int, int, int);        // Найти клиета по определенному полю(значение поля - число) начиная с определенной позиции и до конца
int FindClient(Client *, int, int, int, std::string);// Найти клиета по определенному полю(значение поля - строка) начиная с определенной позиции и до конца
Client *DeleteClient(Client *, int *, int);             // Удаление одного клиента
Client *ChooseForDelete(Client *, int *);               // Диалог с пользователем о выборе клиентов для удалния
Client *ChooseForChange(Client *, int);                 // Диалог с пользователем о выборе клиента для редактирования его данных
void ChooseForFind(Client *, int);                   // Диалог с пользователем о поиске клиентов с определенными свойствами
void Sort(Client *, int);                            // Сортировка вставками
void FindDiscount(Client *, int);                    // Отдельная функция для вывода всех пользователей со скидкой 5%(с использованием бинарного поиска)