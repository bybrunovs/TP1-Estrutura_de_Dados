#pragma once

#include <string>
#include <cmath>
#include "Acao.h"

class Metrica
{
protected:
    unsigned _WCOTACOES;

    double retornoElementar(const double cotacaoAtual, const double cotacaoAnterior)
    {
        return (cotacaoAtual / cotacaoAnterior) - 1;
    }

public:
    Metrica();
    Metrica(unsigned WCOTACOES);
    ~Metrica() = default;

    // Métodos para calcular as métricas
    double RET(Acao &acao);
    double AVGRET(Acao &acao);
    double CONS(Acao &acao);
    double STAB(Acao &acao);
};
