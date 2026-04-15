#pragma once

#include "Acao.h"
#include "TADS/Vector.h"

class Cliente
{
private:
    unsigned _id;
    TADS::Vector<Acao *> _carteira;

public:
    Cliente(unsigned id);
    ~Cliente();
};
