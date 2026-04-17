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

    unsigned getId() const;

    void adicionarAcao(unsigned IDAcao);

    void removerAcao(unsigned IDAcao);

    bool possuiAcao(unsigned IDAcao) const;

    unsigned getNumeroAcoes() const;

    unsigned getAcaoID(unsigned indice) const;
    friend std::ostream &operator<<(std::ostream &os, const Cliente &cliente);
};
