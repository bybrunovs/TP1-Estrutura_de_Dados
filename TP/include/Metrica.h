#pragma once

#include <string.h>
namespace Metrica
{

    class Metricas
    {
    private:
        unsigned id;

    public:
        Metricas();
        virtual ~Metricas() = default;
    };

} // namespace Metrica