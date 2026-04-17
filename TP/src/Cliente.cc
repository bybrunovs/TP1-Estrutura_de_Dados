#include "Cliente.h"

Cliente::Cliente(unsigned id) : _id(id) {}

unsigned Cliente::getId() const
{
    return _id;
}

void Cliente::adicionarAcao(unsigned IDAcao)
{
    _IDAcoesCarteira.push_back(IDAcao);
}

void Cliente::removerAcao(unsigned IDAcao)
{
    for (unsigned i = 0; i < _IDAcoesCarteira.tamanho(); i++)
    {
        if (_IDAcoesCarteira[i] == IDAcao)
        {
            _IDAcoesCarteira.deleteElemento(i);
            return;
        }
    }
}

bool Cliente::possuiAcao(unsigned IDAcao) const
{
    for (unsigned i = 0; i < _IDAcoesCarteira.tamanho(); i++)
    {
        if (_IDAcoesCarteira[i] == IDAcao)
        {
            return true;
        }
    }
    return false;
}

unsigned Cliente::getNumeroAcoes() const
{
    return _IDAcoesCarteira.tamanho();
}

std::ostream &operator<<(std::ostream &os, const Cliente &cliente)
{
    os << cliente.getId();
    return os;
}
