#include "AVGRET.h"

namespace Metricas
{

    AVGRET::AVGRET(unsigned WCOTACOES): Metrica(WCOTACOES)
    {
        this->_nomeMetrica = "AVGRET";
    }

    void AVGRET::calcularMetrica(Acao &acao, unsigned indiceMetrica){
        
    }
} // namespace Metrica