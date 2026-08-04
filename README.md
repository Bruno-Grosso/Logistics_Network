# 🚚 Logistics Network Engine

High-performance logistics optimization engine developed entirely in **C**. The system does not use third-party high-level libraries; all fundamental data structures (graphs, hash tables, min-heaps) and file ingestion pipelines were built from scratch, ensuring absolute control over memory management and algorithmic complexity.

## 🚀 Features and Algorithms

- [x] **Directed Graph:** Implementation based on adjacency lists for memory optimization.
- [x] **Hash Table:** Resolution of strings (city names) to internal IDs in constant time **O(1)**, eliminating search bottlenecks.
- [x] **Custom Min-Heap:** Priority queue with dynamic allocation and `heapify_up` / `heapify_down` operations in **O(log N)**.
- [x] **Dijkstra’s Algorithm:** Routing engine for calculating the path with the lowest logistics cost.
- [x] **Randomized Select (RSelect) Algorithm:** An auditing module that calculates the median traffic across the entire network in linear time **O(N)**.
- [x] **File Parser (Data Ingestion):** A custom file parser for automated loading of logistics networks via `.txt`.
      
## 🏗 Project Architecture

The repository follows a strict Separation of Concerns pattern:

* `src/`: Source code for structures and algorithms (`.c`).
* `include/`: Headers and interface definitions (`.h`).
* `data/`: *Assets* directory, containing logistics networks in `.txt` format.
* `build/`: Directory generated during compilation (ignored by Git) that stores the binaries and the final executable.

## ⚙️ How to Compile and Run

**Prerequisites:** GCC compiler and `make` installed.

1. **Clone the repository and compile the project:**
```bash
git clone https://github.com/Bruno-Grosso/Logistics_Network.git
cd Logistics_Network
make
```

2. **Run the system:**
```bash
./build/logistics
```

## 🗺️ How to Use File-Based Loading (.txt)

The system allows for manual entry of cities, but it features an engine optimized to load massive grids instantly.

To use this feature, make sure the configuration file (map.txt) is located inside the data/ folder.

**Required .txt format:**
The file functions as a custom .csv. The first section lists the cities, and after the separator ---, the routes are defined in the format Origin, Destination, Cost.

## 📈 Project Status

**Currently in the testing and maintenance phase.** All data pipelines, routing (Dijkstra), and statistical analysis (RSelect) are already integrated. The backend engine is currently undergoing traffic stress testing, architectural refinement, and code audits to ensure ongoing stability and scalability.
