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
    TADS::Vector<unsigned> _ordenacaoGlobalAcoes;

    Metrica _metrica;
    unsigned _wcotacoes = 0;
    bool _entrouA = false;
    bool _entrouU = false;
    bool _entrouUmetricas = false;
    bool _entrouQ = false;

    void ordenarMetrica(unsigned indiceMetrica);
    void ordenarAcoes();
    void ordenarCliente(unsigned IDCliente, bool isDecrescente);

    void quicksort(TADS::Vector<unsigned> &metrica, unsigned low, unsigned high, unsigned indiceMetrica);
    void quicksort(TADS::Vector<unsigned> &ordenacaoGlobalAcoes, unsigned low, unsigned high);
    void quicksort(TADS::Vector<Acao *> &ordenacaoCarteiraCliente, unsigned low, unsigned high, bool isDecrescente);

    double partition(TADS::Vector<unsigned> &metrica, unsigned low, unsigned high, unsigned indiceMetrica);
    double partition(TADS::Vector<unsigned> &ordenacaoGlobalAcoes, unsigned low, unsigned high);
    double partition(TADS::Vector<Acao *> &ordenacaoCarteiraCliente, unsigned low, unsigned high, bool isDecrescente);

    template <typename T>
    void swap(T &a, T &b);
    unsigned encontrarMediana(double a,unsigned indicea, double b, unsigned indiceb, double c, unsigned indicec);
    bool doubleEquals(double a, double b);

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