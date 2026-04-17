#include "Metrica.h"

namespace Metricas
{
    class RET : public Metricas::Metrica
    {

    public:
        RET(unsigned WCOTACOES);

        void calcularMetrica(Acao &acao, unsigned indiceMetrica);
    };
} // namespace Metrica