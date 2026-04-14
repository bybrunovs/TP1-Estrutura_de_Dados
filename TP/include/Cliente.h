#pragma once

#include "Acao.h"

class Cliente
{
private:
    unsigned id;
    Acao* carteira;
public:
    Cliente(unsigned id);
    ~Cliente();
};
