#include <iostream>
#include <string>
#include <sstream>
#include "AnaliseCarteiras.h"
#include "Vector.h"
#include "Metrica.h"
#include "AVGRET.h"
#include "CONS.h"
#include "RET.h"
#include "STAB.h"

int main(int argc, char *argv[])
{
    std::string token;
    std::string linha;
    std::getline(std::cin, linha);
    std::stringstream ss(linha);

    ss >> token;

    if (token != "M")
    {
        throw std::invalid_argument("Entrada inválida: a primeira linha deve ser do tipo 'M'");
    }

    unsigned wcotacoes;
    ss >> wcotacoes;

    AnaliseCarteiras analiseCarteiras(wcotacoes);

    while (ss >> token)
    {
        analiseCarteiras.AdicionarMetrica(token);
    }

    //
    while (getline(std::cin, linha))
    {
        ss.str(linha);
        ss >> token;

        if (token.compare("A") == 0)
        {
            int IDCliente;
            ss >> IDCliente;
            analiseCarteiras.AdicionarCliente(IDCliente);
        }
        else if (token.compare("C") == 0)
        {
            int IDAcao;
            ss >> IDAcao;
            analiseCarteiras.AdicionarAcao(IDAcao);
        }
        else
            throw std::invalid_argument("Entrada inválida");
    }

    return 0;
}