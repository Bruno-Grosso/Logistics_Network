# 🚚 Logistics Network Engine

Motor de otimização logística de alta performance desenvolvido inteiramente em **C**. O sistema não utiliza bibliotecas de alto nível de terceiros; todas as estruturas de dados fundamentais (Grafos, Tabelas Hash, Min-Heaps) e pipelines de ingestão de arquivos foram construídos do zero, garantindo controle absoluto sobre a manipulação de memória e a complexidade algorítmica.

## 🚀 Funcionalidades e Algoritmos

- [x] **Grafo Direcionado:** Implementação baseada em listas de adjacências para otimização de memória.
- [x] **Tabela Hash:** Resolução de strings (nomes das cidades) para IDs internos em tempo constante **O(1)**, eliminando gargalos de busca.
- [x] **Min-Heap Customizada:** Fila de prioridade com alocação dinâmica e operações de `heapify_up` / `heapify_down` em **O(log N)**.
- [x] **Algoritmo de Dijkstra:** Motor de roteamento para cálculo do caminho de menor custo logístico.
- [x] **Algoritmo Randomized Select (RSelect):** Módulo de auditoria que calcula a mediana de tráfego de toda a malha em tempo linear **O(N)**.
- [x] **File Parser (Data Ingestion):** Interpretador de arquivos customizado para carregamento automatizado de malhas logísticas via `.txt`.

## 🏗 Arquitetura do Projeto

O repositório segue um padrão rigoroso de separação de responsabilidades (Separation of Concerns):

* `src/`: Código-fonte das estruturas e algoritmos (`.c`).
* `include/`: Cabeçalhos e definições de interface (`.h`).
* `data/`: Diretório de *assets*, contendo as malhas logísticas em formato `.txt`.
* `build/`: Diretório gerado na compilação (ignorado via Git) que armazena os binários e o executável final.

## ⚙️ Como Compilar e Executar

**Pré-requisitos:** Compilador GCC e `make` instalados.

1. **Clone o repositório e compile o projeto:**
```bash
git clone <url-do-seu-repositorio>
cd Logistics_Network
make
```

2. **Execute o sistema:**
```bash
./build/logistics
```

## 🗺️ Como utilizar o carregamento via Arquivo (.txt)

O sistema permite a inserção manual de cidades, mas possui um motor otimizado para carregar malhas massivas de forma instantânea.

Para utilizar essa função, certifique-se de que o arquivo de configuração (map.txt) esteja localizado dentro da pasta data/.

**Formato exigido no .txt:**
O arquivo funciona como um .csv customizado. A primeira seção cadastra as cidades, e, após o separador ---, as rotas são definidas no formato Origem, Destino, Custo.

## 📈 Status do Projeto

**Em fase de testes e manutenção.** Todos os pipelines de dados, roteamento (Dijkstra) e análise estatística (RSelect) já estão integrados. Atualmente, o motor backend passa por testes de estresse de tráfego, refinamento de arquitetura e auditoria de código para garantir estabilidade e escalabilidade contínuas.
