#pragma once

#include <ostream>
#include "Vector.h"
class Acao
{
private:
    unsigned _id;

    TADS::Vector<double> _cotacoes;
    TADS::Vector<unsigned> _PontosMetricas;
    double _PontosMetrica;

public:
    Acao(unsigned id, unsigned WCotacoes, unsigned nMetricas);

    ~Acao() = default;

    unsigned getId() const;

    double& getCotacao(unsigned indice);

    void adicionarCotacao(double &valor);

    unsigned getPontosMetrica(unsigned indice);

    void setPontosMetrica(unsigned indice, const double &valor);

    bool operator<(const Acao& outra) const;

    bool operator>(const Acao& outra) const;

    bool operator==(const Acao& outra) const;

    friend std::ostream& operator<<(std::ostream& os, const Acao& acao);
};
