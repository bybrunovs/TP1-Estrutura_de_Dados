#pragma once

#include "TADS/Vector.h"

class Cliente
{
private:
    unsigned _id;
    TADS::Vector<unsigned> _IDAcoesCarteira;

public:
    Cliente(unsigned id);

    ~Cliente();

    friend std::ostream &operator<<(std::ostream &os, const Acao &acao);
};
