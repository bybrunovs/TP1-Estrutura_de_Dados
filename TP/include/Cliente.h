/**
 * @file Cliente.h
 * @author Bruno Vieira
 * @brief representa um cliente no sistema
 * @version 0.1
 * @date 2025-04-22
 */
#pragma once

#include <ostream>
#include "Vector.h"
#include "Acao.h"
class Cliente
{
private:
    unsigned _id;
    TADS::Vector<Acao *> _acoesCarteira;

public:
    Cliente();

    Cliente(unsigned id);

    ~Cliente() = default;

    unsigned getId() const;

    void adicionarAcao(Acao &acao);

    void removerAcao(unsigned IDAcao);

    bool possuiAcao(unsigned IDAcao) const;

    unsigned getNumeroAcoes() const;

    TADS::Vector<Acao *> &getCarteira();

    friend std::ostream &operator<<(std::ostream &os, const Cliente &cliente);
};
