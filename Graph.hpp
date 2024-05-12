#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <iostream>
#include <vector>
#include <limits>
#include <unordered_set>

namespace ariel {
    class Graph {
    public:
        std::vector<std::vector<int>> adjacencyMatrix;
        std::vector<std::vector<int>> shortestPaths;
        bool isDirected;
        bool hasNegativeCycle;
        bool hasNegativeEdges;
        std::string cycle;
        size_t v;
        int edges;
        std::unordered_set<int> sets[2];

        Graph();
        void loadGraph(const std::vector<std::vector<int>>& matrix);
        void printGraph() const;
        void cleanGraph();
        void setDirected(const std::vector<std::vector<int>>& matrix);
        void setNegativeEdges(const std::vector<std::vector<int>>& matrix);
        inline size_t getSize() const{ return adjacencyMatrix.size(); };
        inline std::string getCycle(){ return cycle; }
        inline void setCycle(std::string foundCycle) { cycle = foundCycle;}

    };
} // namespace ariel

#endif