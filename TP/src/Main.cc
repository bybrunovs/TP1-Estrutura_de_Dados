#include <iostream>
#include <string>
#include <sstream>
#include "AnaliseCarteiras.h"
#include "Vector.h"
#include "Metrica.h"

int main(int argc, char *argv[])
{
    std::cout << std::fixed << std::setprecision(3);

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

    while (getline(std::cin, linha))
    {
        ss.clear();
        ss.str(linha);
        ss >> token;

        if (token.compare("A") == 0)
        {
            // Adicionar ação
            int IDAcao;
            ss >> IDAcao;
            analiseCarteiras.AdicionarAcao(IDAcao);
        }
        else if (token.compare("U") == 0)
        {
            // Adicionar cliente
            int IDCliente;
            ss >> IDCliente;
            analiseCarteiras.AdicionarCliente(IDCliente);
        }
        else if (token.compare("P") == 0)
        {
            // adicionar cotação de ação
            unsigned IDAcao;
            double preco;
            ss >> IDAcao >> preco;
            analiseCarteiras.AdicionarCotacaoAcao(IDAcao, preco);
        }
        else if (token.compare("B") == 0)
        {
            // comprar ação
            unsigned IDCliente;
            unsigned IDAcao;
            ss >> IDCliente >> IDAcao;
            analiseCarteiras.CompraAcao(IDCliente, IDAcao);
        }
        else if (token.compare("V") == 0)
        {
            // vender ação
            unsigned IDCliente;
            unsigned IDAcao;
            ss >> IDCliente >> IDAcao;
            analiseCarteiras.VendaAcao(IDCliente, IDAcao);
        }
        else if (token.compare("Q") == 0)
        {
            // consulta carteira
            unsigned IdConsulta;
            unsigned IDCliente;
            unsigned Nacoes;
            unsigned Nmetricas;
            ss >> IdConsulta >> IDCliente >> Nacoes >> Nmetricas;

            std::string metricas[Nmetricas];
            double peso[Nmetricas];
            for (unsigned i = 0; i < Nmetricas; i++)
            {
                ss >> metricas[i] >> peso[i];
            }

            analiseCarteiras.ConsultaCarteira(IdConsulta, IDCliente, Nacoes, Nmetricas, metricas, peso);
        }
        else
            throw std::invalid_argument("Entrada inválida: tipo de linha desconhecido. As linhas válidas são: A, U, P, B, V e Q.");
    }
    return 0;
}