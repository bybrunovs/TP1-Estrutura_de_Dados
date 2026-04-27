/**
 * @file Metrica.h
 * @author Bruno Vieira
 * @brief reune todas as metricas possiveis de ser cálculadas
 * @version 0.1
 * @date 2025-04-22
 */

#pragma once

#include <string>
#include <cmath>
#include "Acao.h"

class Metrica
{
protected:

    double retornoElementar(const double cotacaoAtual, const double cotacaoAnterior)
    {
        return (cotacaoAtual / cotacaoAnterior) - 1;
    }

public:
    Metrica();
    ~Metrica() = default;

    // Métodos para calcular as métricas
    double RET(Acao &acao);
    double AVGRET(Acao &acao);
    double CONS(Acao &acao);
    double STAB(Acao &acao);
};
