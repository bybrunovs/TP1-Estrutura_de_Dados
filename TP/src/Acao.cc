#include "Acao.h"

Acao::Acao() : _id(0){

      for (unsigned i = 0; i < 4; i++)
    {
        _PontosMetricas.push_back(0.0);
    }
}

Acao::Acao(unsigned id, unsigned WCotacoes, unsigned nMetricas) : _id(id)
{

    for (unsigned i = 0; i < nMetricas; i++)
    {
        _PontosMetricas.push_back(0.0);
    }
}

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

double Acao::getPontosMetrica(unsigned indice)
{
    return _PontosMetricas[indice];
}

void Acao::setPontosMetrica(unsigned indice, const double &valor)
{
    _PontosMetricas[indice] = valor;
}

double Acao::getPontosGlobal() const
{
    return _PontosGlobal;
}

void Acao::setPontosGlobal(const double &valor)
{
    _PontosGlobal = valor;
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

bool Acao::operator!=(const Acao &outra) const
{
    return this->_id != outra._id;
}

std::ostream &operator<<(std::ostream &os, const Acao &acao)
{
    os << acao.getId();
    return os;
}
