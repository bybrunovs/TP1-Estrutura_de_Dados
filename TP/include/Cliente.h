#pragma once

#include "Vector.h"

class Cliente
{
private:
    unsigned _id;
    TADS::Vector<unsigned> _IDAcoesCarteira;

public:
    Cliente(unsigned id);

    ~Cliente() = default;

    friend std::ostream &operator<<(std::ostream &os, const Acao &acao);
};
