#include "Acao.h"

Acao::Acao(unsigned id, unsigned WCotacoes, unsigned nMetricas) : _id(id) {}

unsigned Acao::getId() const
{
    return _id;
}

double &Acao::getCotacao(unsigned indice)
{
    return _cotacoes[indice];
}

void Acao::adicionarCotacao(double &valor)
{
    _cotacoes.push_back(valor);
}

unsigned Acao::getPontosMetrica(unsigned indice)
{
    return _PontosMetricas[indice];
}

void Acao::setPontosMetrica(unsigned indice, const double &valor)
{
    _PontosMetricas[indice] = valor;
}

bool Acao::operator<(const Acao &outra) const
{
    return this->_id < outra._id;
}

bool Acao::operator>(const Acao &outra) const
{
    return this->_id > outra._id;
}

bool Acao::operator==(const Acao &outra) const
{
    return this->_id == outra._id;
}

std::ostream &operator<<(std::ostream &os, const Acao &acao)
{
    os << acao.getId();
    return os;
}
