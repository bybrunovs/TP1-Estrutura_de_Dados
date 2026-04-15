#pragma once

#include "TADS/Vector.h"


#include "TADS/Vector.h"

class Acao
{
private:
    unsigned _id;

    TADS::Vector<double> _cotacoes;
    TADS::Vector<double> _PontosMetricas;
    double _PontosTotaisMetricas;

public:
    Acao(unsigned id, unsigned WCotacoes, unsigned nMetricas);

    ~Acao();

    double getCotacao(unsigned indice);

    void adicionarCotacao(double &valor);

    void getPontosMetrica(unsigned indice, double &valor);

    void setPontosMetrica(unsigned indice, double &valor);

    bool operator<(const Acao& outra) const;

    bool operator>(const Acao& outra) const;

    bool operator==(const Acao& outra) const;

    bool operator=(const Acao& outra) const;

    friend std::ostream& operator<<(std::ostream& os, const Acao& acao);
};
