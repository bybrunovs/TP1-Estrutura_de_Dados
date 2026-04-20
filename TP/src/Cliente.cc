#include "Cliente.h"


Cliente::Cliente() : _id(0) {}

Cliente::Cliente(unsigned id) : _id(id) {}

unsigned Cliente::getId() const
{
    return _id;
}
 
void Cliente::adicionarAcao(Acao &acao)
{
    Acao *acaoPtr = &acao;
    _acoesCarteira.push_back(acaoPtr);
}

void Cliente::removerAcao(unsigned IDAcao)
{
    for (unsigned i = 0; i < _acoesCarteira.tamanho(); i++)
    {
        if (_acoesCarteira[i]->getId() == IDAcao)
        {
            _acoesCarteira.deleteElemento(i);
            return;
        }
    }

    throw std::invalid_argument("O cliente não possui a ação com o ID especificado");
}

bool Cliente::possuiAcao(unsigned IDAcao) const
{
    for (unsigned i = 0; i < _acoesCarteira.tamanho(); i++)
    {
        if (_acoesCarteira[i]->getId() == IDAcao)
        {
            return true;
        }
    }
    return false;
}

unsigned Cliente::getNumeroAcoes() const
{
    return _acoesCarteira.tamanho();
}

TADS::Vector<Acao *> &Cliente::getCarteira()
{
    return _acoesCarteira;
}

std::ostream &operator<<(std::ostream &os, const Cliente &cliente)
{
    os << cliente.getId();
    return os;
}
