#pragma once

#include <ostream>
#include "Vector.h"
class Acao
{
private:
    unsigned _id = 0;

    TADS::Vector<double> _cotacoes;
    TADS::Vector<double> _PontosMetricas;
    double _PontosGlobal = 0.0;

public:
    Acao();

    Acao(unsigned id, unsigned WCotacoes, unsigned nMetricas);

    ~Acao() = default;

    unsigned getId() const;

    double &getCotacao(unsigned indice);

    void adicionarCotacao(double &valor);

    double getPontosMetrica(unsigned indice);

    void setPontosMetrica(unsigned indice, const double &valor);

    double getPontosGlobal() const;

    void setPontosGlobal(const double &valor);

    bool operator<(const Acao &outra) const;

    bool operator>(const Acao &outra) const;

    bool operator==(const Acao &outra) const;

    bool operator!=(const Acao &outra) const;

    friend std::ostream &operator<<(std::ostream &os, const Acao &acao);
};
