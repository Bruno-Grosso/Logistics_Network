# 🚚 Logistics Network Engine & Live Radar

High-performance logistics optimization engine developed entirely in **C**, seamlessly integrated with an interactive **Web Dashboard**. The backend does not use third-party high-level libraries; all fundamental data structures (graphs, hash tables, min-heaps) and file ingestion pipelines were built from scratch, ensuring absolute control over memory management and algorithmic complexity.

## 🚀 Features and Algorithms

### ⚙️ Backend Engine (C)
- [x] **Directed Graph:** Implementation based on adjacency lists for memory optimization.
- [x] **Hash Table:** Resolution of strings (city names) to internal IDs in constant time **O(1)**, eliminating search bottlenecks.
- [x] **Custom Min-Heap:** Priority queue with dynamic allocation and `heapify_up` / `heapify_down` operations in **O(log N)**.
- [x] **Dijkstra’s Algorithm:** Routing engine for calculating the path with the lowest logistics cost. Automatically exports the final path to a `.json` file for frontend rendering.
- [x] **Randomized Select (RSelect):** An auditing module that calculates the median traffic across the entire network in linear time **O(N)**.
- [x] **File Parser (Data Ingestion):** A custom file parser for automated loading of massive logistics networks via `.txt`.

### 🌐 Frontend Radar (JavaScript / HTML)
- [x] **Physics-Based Visualizer:** Interactive UI using Vis.js to render the C-parsed network in real-time.
- [x] **Dijkstra Integration:** Reads the backend-generated `path_result.json` to visually trace the exact shortest path calculated by the C engine.
- [x] **Interactive Controls:** Features manual rotation via <kbd>Q</kbd> and <kbd>E</kbd> keys, click-to-highlight for origin/destination flows, and drag-and-drop orbit recalculation.

## 🏗 Project Architecture

The repository follows a strict Separation of Concerns pattern, hybridizing low-level memory management with web visualization:

* `src/`: Source code for backend structures and algorithms (`.c`).
* `include/`: Headers and interface definitions (`.h`).
* `data/`: *Assets* directory, containing the logistics networks (`map.txt`) and the dynamic routing output (`path_result.json`).
* `frontend/`: The Web Dashboard environment (`index.html` and UI scripts).
* `build/`: Directory generated during compilation containing the final executable.

## ⚙️ How to Compile and Run

**Prerequisites:** GCC compiler, `make`, and Python 3 (for the local web server).

**1. Clone the repository and compile the C engine:**
```bash
git clone [https://github.com/Bruno-Grosso/Logistics_Network.git](https://github.com/Bruno-Grosso/Logistics_Network.git)
cd Logistics_Network
make
```

**2. Run the C Backend:**
```bash
./build/logistics
```

**3. Launch the Live Radar (Frontend):**
To avoid CORS blockages when reading local files, start a simple local server from the root directory:
```bash
python3 -m http.server 8000
```
Open your browser and navigate to: `http://localhost:8000/frontend/index.html`

## 🗺️ How to Use File-Based Loading (.txt)

The system allows for manual entry of cities, but it features an engine optimized to load massive grids instantly.

To use this feature, make sure the configuration file (`map.txt`) is located inside the `data/` folder.

**Required .txt format:**
The file functions as a custom `.csv`. The first section lists the cities, and after the separator `---`, the routes are defined in the format `Origin, Destination, Cost`.

## 🛣️ How to Visualize the Dijkstra Route (Step-by-Step)

The Web Radar is strictly bound to the `map.txt` state. To see the routing integration working seamlessly, follow these steps:

1. **Start the Backend:** Run `./build/logistics` in your terminal.
2. **Load the Grid:** Select the terminal option to load data from `map.txt`. *(Note: Nodes added manually via the console menu will not render on the Web Radar).*
3. **Calculate the Route:** Choose the Dijkstra option and input your Origin and Destination.
4. **Generate Payload:** Wait for the terminal to display `[Sistema] Rota exportada para o Radar com sucesso`.
5. **Open the Radar:** Ensure your python server is running and open the frontend in your browser.
6. **See the Magic:** Click the **"Show Dijkstra Route"** button on the web dashboard to see the exact shortest path highlighted in neon pink/red.

## 📈 Project Status

**Fully Operational & Deployed.** All data pipelines, routing algorithms (Dijkstra), and statistical analysis (RSelect) are fully integrated. The architectural bridge between the C Engine and the JS Dashboard is stable, successfully using JSON to decouple the calculation layer from the presentation layer.
