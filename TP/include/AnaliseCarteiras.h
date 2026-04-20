#include "Acao.h"
#include "Cliente.h"
#include "Metrica.h"
#include "Vector.h"

#include <iomanip>
#include <iostream>
#include <string>

class AnaliseCarteiras
{
private:
    TADS::Vector<Acao> _acoes;
    TADS::Vector<Cliente> _clientes;
    TADS::Vector<std::string> _nomesMetricas;
    TADS::Vector<TADS::Vector<unsigned>> _OrdenacaoMetricas;
    TADS::Vector<unsigned> _ordenaçaoGlobalAcoes;

    Metrica _metrica;
    unsigned _wcotacoes = 0;
    bool _entrouA = false;
    bool _entrouU = false;
    bool _entrouUmetricas = false;

    void ordenarMetrica(unsigned indiceMetrica);
    void ordenarAcoes();
    void ordenarCliente(unsigned IDCliente);

    void quicksort(TADS::Vector<unsigned> &metrica, unsigned low, unsigned high, unsigned indiceMetrica);
    void quicksort(TADS::Vector<unsigned> &ordenacaoGlobalAcoes, unsigned low, unsigned high);
    void quicksort(TADS::Vector<Acao *> &ordenacaoCarteiraCliente, unsigned low, unsigned high);

    double partition(TADS::Vector<unsigned> &metrica, unsigned low, unsigned high, unsigned indiceMetrica);
    double partition(TADS::Vector<unsigned> &ordenaçaoGlobalAcoes, unsigned low, unsigned high);
    double partition(TADS::Vector<Acao *> &ordenacaoCarteiraCliente, unsigned low, unsigned high);

    template <typename T>
void swap(T &a, T &b);
public:
    AnaliseCarteiras(unsigned wcotacoes);
    ~AnaliseCarteiras() = default;

    void iniciarMetricas();
    unsigned getIndiceMetrica(const std::string &Metrica);
    void AdicionarAcao(unsigned IDAcao);
    void AdicionarCliente(unsigned IDCliente);
    void AdicionarMetrica(const std::string &Metrica);
    void ConsultaCarteira(unsigned IdConsulta, unsigned IDCliente, unsigned Nacoes, unsigned Nmetricas, const std::string *metricas, double peso[]);
    void VendaAcao(unsigned IDCliente, unsigned IDAcao);
    void CompraAcao(unsigned IDCliente, unsigned IDAcao);
    void AdicionarCotacaoAcao(unsigned IDAcao, double &preco);
    void AdicionarAcaoCarteira(unsigned IDCliente, unsigned IDAcao);
};