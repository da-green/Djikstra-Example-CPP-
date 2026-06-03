# Dijkstra's Algorithm (C++ Implementation)

This repository contains a beginner-friendly implementation of Dijkstra's shortest path algorithm using a priority queue (min-heap) in C++.

---

## Description

Dijkstra's algorithm is used to find the shortest path from a single source node to all other nodes in a weighted graph with non-negative edge weights.

This implementation uses:
- An adjacency list representation of the graph
- A min-heap (priority queue) for efficient selection of the next closest node

---

## Concepts

- Graph representation using adjacency list
- Greedy approach
- Priority queue (min-heap)
- Relaxation of edges

---

## Time Complexity

- O((V + E) log V)
Where:
- V = number of vertices
- E = number of edges

---

## How to Run

Compile and run using g++:

```bash
g++ main.cpp -o dijkstra
./dijkstra
```

---

## Reference

Original idea and implementation inspired by:

- [GeeksforGeeks](https://www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-using-priority_queue-stl/)

---

## Author

Adapted and annotated by Daniel Green for learning purposes.
