#pragma once

#include "TADS/Vector.h"

class Acao
{
private:
    unsigned _id;

    TADS::Vector<double> _cotacoes;
    TADS::Vector<double> _PontosMetricas;

public:
    Acao(unsigned id, unsigned WCotacoes, unsigned nMetricas);
    ~Acao();
};
