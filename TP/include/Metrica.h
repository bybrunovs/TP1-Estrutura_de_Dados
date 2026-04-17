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
    Metrica() : _WCOTACOES(0) {}
    Metrica(unsigned WCOTACOES) : _WCOTACOES(WCOTACOES) {}
    ~Metrica() = default;

    // Métodos para calcular as métricas
    double RET(Acao &acao, unsigned indiceMetrica);
    double AVGRET(Acao &acao, unsigned indiceMetrica);
    double CONS(Acao &acao, unsigned indiceMetrica);
    double STAB(Acao &acao, unsigned indiceMetrica);
};
