import pandas as pd
import matplotlib.pyplot as plt
import matplotlib.ticker as ticker
import os

# Configuração de cada arquivo: (caminho, coluna_x, label_x, título)
CONFIGS = [
    (
        "acoesXtempoXespaco.csv",
        "Qtd. ações",
        "Qtd. Ações",
        "Analise de Complexidade: Quantidade de Ações",
    ),
    (
        "ClientesXtempoXespaco.csv",
        "Qtd.Clientes",
        "Qtd. Clientes",
        "Analise de Complexidade: Quantidade deClientes",
    ),
    (
        "consultasXtempoXespaco.csv",
        "Qtd. consultas",
        "Qtd. Consultas",
        "Analise de Complexidade: Quantidade de Consultas",
    ),
    (
        "cotacoesXtempoXespaco.csv",
        "Qtd. Cotações",
        "Qtd. Cotações",
        "Analise de Complexidade: Quantidade de Cotações",
    ),
]

CORES = {
    "imediata": "#1f77b4",    # azul
    "sob_demanda": "#ff0e0e", # vermelho
}

SCRIPT_DIR = os.path.dirname(os.path.abspath(__file__))

def encontrar_coluna(df, nome):
    """Encontra coluna pelo nome, tolerando espaços extras."""
    nome_strip = nome.strip()
    for c in df.columns:
        if c.strip() == nome_strip:
            return c
    raise KeyError(f"Coluna '{nome}' não encontrada. Disponíveis: {df.columns.tolist()}")

def gerar_grafico(caminho_csv, coluna_x, label_x, titulo):
    df = pd.read_csv(caminho_csv)
    df.columns = [c.strip() for c in df.columns]

    col_x        = coluna_x.strip()
    col_tempo    = "Tempo de execução(ms)"
    col_memoria  = "pico de memória(kb)"
    col_est      = "Estrategia"

    fig, ax_tempo = plt.subplots(figsize=(10, 6))
    ax_mem = ax_tempo.twinx()

    for estrategia in ["imediata", "sob_demanda"]:
        sub = df[df[col_est] == estrategia].sort_values(col_x)
        cor = CORES[estrategia]
        label_base = estrategia.replace("_", " ").title()

        # Tempo — linha sólida, eixo esquerdo
        ax_tempo.plot(
            sub[col_x], sub[col_tempo],
            color=cor, marker="o", linewidth=2,
            label=f"{label_base} – Tempo (ms)"
        )

        # Memória — linha pontilhada, eixo direito
        ax_mem.plot(
            sub[col_x], sub[col_memoria],
            color=cor, marker="s", linewidth=2,
            linestyle="--",
            label=f"{label_base} – Memória (kb)"
        )

    ax_tempo.set_xlabel(label_x, fontsize=12)
    ax_tempo.set_ylabel("Tempo de execução (ms)", fontsize=12, color="black")
    ax_mem.set_ylabel("Pico de memória (kb)", fontsize=12, color="black")

   # ax_tempo.set_xscale("log")
    ax_tempo.xaxis.set_major_formatter(ticker.FuncFormatter(lambda v, _: f"{int(v):,}".replace(",", ".")))

    # Legenda unificada
    linhas_t, labels_t = ax_tempo.get_legend_handles_labels()
    linhas_m, labels_m = ax_mem.get_legend_handles_labels()
    ax_tempo.legend(linhas_t + linhas_m, labels_t + labels_m,
                    loc="upper left", fontsize=10, framealpha=0.9)

    ax_tempo.grid(True, which="both", linestyle=":", alpha=0.5)
    plt.title(titulo, fontsize=14, fontweight="bold", pad=14)
    plt.tight_layout()

    nome_saida = os.path.splitext(os.path.basename(caminho_csv))[0] + ".png"
    caminho_saida = os.path.join(SCRIPT_DIR, nome_saida)
    plt.savefig(caminho_saida, dpi=150)
    plt.close()
    print(f"Gráfico salvo: {caminho_saida}")

if __name__ == "__main__":
    for csv_nome, col_x, label_x, titulo in CONFIGS:
        caminho = os.path.join(SCRIPT_DIR, csv_nome)
        if not os.path.exists(caminho):
            print(f"Arquivo não encontrado, pulando: {caminho}")
            continue
        gerar_grafico(caminho, col_x, label_x, titulo)
