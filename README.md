# Logistics Network

Sistema de otimização logística desenvolvido em C para cálculo de rotas utilizando o algoritmo de Dijkstra e uma estrutura de dados de Min-Heap para gerenciamento de prioridades.

## 🚀 Funcionalidades
- [x] Implementação de Grafo (Lista de Adjacências).
- [x] Fila de Prioridade (Min-Heap) com complexidade O(log n).
- [ ] Algoritmo de Dijkstra para menor caminho.

## 🛠 Pré-requisitos
- Compilador GCC.
- `make` instalado.

## ⚙️ Como Compilar e Rodar
Para compilar o projeto, utilize o Makefile incluso:

```bash
# Para compilar
make

# Para executar
./logistics
```
## 🏗 Arquitetura
- src/: Código-fonte (.c).
- include/: Cabeçalhos (.h).
- Min-Heap: Otimizado com alocação dinâmica e operações de heapfy_up e heapfy_down.
- Grafo: Implementação baseada em lista de adjacências para alta performance.

## 📈 Status do Projeto

O motor de busca (Min-Heap) e a estrutura de Grafo estão validados e operacionais.
Próximo passo: Integração do algoritmo de Dijkstra com o Grafo para cálculo de rotas.
