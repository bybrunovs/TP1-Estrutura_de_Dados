#pragma once

#include <string>
#include "Acao.h"


namespace Metrica
{

class Metricas
{
protected:
    unsigned _WCOTACOES;
    
public:
    Metricas(unsigned WCOTACOES);
    ~Metricas() = default;
    virtual double calcularMetrica(Acao &acao, unsigned indiceMetrica) = 0;
};

}