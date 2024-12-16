#pragma once
#include "Functions.cpp"

Client *AddSpace(Client *, int *);
void EnterClient(Client*, std::string, int);
Client *EnterWithSize(int, std::string, int);
Client *EnterWithStop(int *, std::string, int);
Client *EnterWithDialog(int *, std::string, int);
void OutputClient(Client client);
Client *AddClient(Client *, int*, std::string, int);
int FindClient(Client *, int , int, int, int);
int FindClient(Client *, int, int, int, std::string);
Client *DeleteClient(Client *, int *, int);
Client *ChooseForDelete(Client *, int);