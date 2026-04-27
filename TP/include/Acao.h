/**
 * @file Acao.h
 * @author Bruno Vieira
 * @brief Representa uma ação a ser comprada/vendida
 * @version 0.1
 * @date 2025-04-22
 */
#pragma once

#include <ostream>
#include "Vector.h"
class Acao
{
private:
    unsigned _id = 0;

    TADS::Vector<double> _cotacoes;
    TADS::Vector<double> _PontosMetricas;
    double _PontosGlobal = 0.0;

public:
    Acao();
    /**
     * @brief Constroi um novo objeto
     *
     * @param id ID do objeto
     * @param WCotacoes Quantidade maxima de cotações a serem analisadas
     * @param nMetricas Quantidad maxima de métricas a serem analisadas
     */
    Acao(unsigned id, unsigned WCotacoes, unsigned nMetricas);

    ~Acao() = default;
    /**
     * @brief Obtem o ID no objeto
     *
     * @return unsigned ID do objeto
     */
    unsigned getId() const;

    /**
     * @brief Obtem a quantidade de cotações armazenadas
     *
     * @return unsigned Quantidade de cotações
     */
    unsigned getQuantidadeCotacoes();

    /**
     * @brief Obtem o valor de uma cotação especifica
     *
     * @param indice Posição dessa cotação
     * @return double& Valor da cotação
     */
    double &getCotacao(unsigned indice);

    /**
     * @brief Adiciona uma nova cotação a ação
     *
     * @param valor Valor da cotação a ser adicionada
     */
    void adicionarCotacao(double &valor);

    /**
     * @brief Obtem a quantidade de pontos da ação em uma métrica especifca
     *
     * @param indice Posição da métrica no vetor
     *
     * @return double Valor da métrica
     */
    double getPontosMetrica(unsigned indice);

    /**
     * @brief Adiciona um valor a uma metrica em uma posição
     *
     * @param indice Posição da métrica no vetor
     * @param valor Valor da mética
     */
    void setPontosMetrica(unsigned indice, const double &valor);

    /**
     * @brief Obtem a pontuação global da ação
     *
     * @return double Valor da pontuação
     */
    double getPontosGlobal() const;

    /**
     * @brief Altera o valor da pontuação global
     *
     * @param valor  Valor da pontuação
     */
    void setPontosGlobal(const double &valor);

    /**
     * @brief Operado de comparação menor que
     *
     * @param outra Objeto Ação a se comparado
     * @return true ID desse objeto é menor que ID do outro
     * @return false ID desse objeto é maior que ID do outro
     */
    bool operator<(const Acao &outra) const;

    /**
     * @brief Operado de comparação maior que
     *
     * @param outra Objeto Ação a se comparado
     * @return true ID desse objeto é maior que ID do outro
     * @return false ID desse objeto é menor que ID do outro
     */
    bool operator>(const Acao &outra) const;

    /**
     * @brief  Operador de comparação é igual
     *
     * @param outra Objeto Ação a se comparado
     * @return true os dois objetos tem o mesmo ID
     * @return false Os objetos tem IDs diferentes
     */
    bool operator==(const Acao &outra) const;

    /**
     * @brief  Operador de comparação é diferente
     *
     * @param outra Objeto Ação a se comparado
     * @return true Os objetos tem IDs diferentes
     * @return false os dois objetos tem o mesmo ID
     */
    bool operator!=(const Acao &outra) const;

    friend std::ostream &operator<<(std::ostream &os, const Acao &acao);
};
