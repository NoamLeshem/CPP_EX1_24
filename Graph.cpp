#include "Graph.hpp"

namespace ariel {

    Graph::Graph() {    }

    void Graph::cleanGraph(){
        this->adjacencyMatrix.clear();
        this->cycle.erase();
        this->isDirected = false;
        this->hasNegativeEdges = false;
        this->hasNegativeCycle = false;
        this->edges = 0;
        this->cycle;
    }

    void checkSquareMatrix(const std::vector<std::vector<int>>& matrix){
        for (size_t i = 0; i < matrix.size(); i++)
        {
            if (matrix[i].size() != matrix.size())
            {
                throw std::invalid_argument("Error: Matrix is not square!");
            }
        }
    }

    void Graph::setDirected(const std::vector<std::vector<int>>& matrix){
        for (size_t i = 0; i < matrix.size(); i++)
        {
            for (size_t j = 0; j < matrix.size(); j++)
            {
                if (matrix[i][j] != matrix[j][i])
                {
                    this->isDirected = true;
                    break;
                }
            }
            if (this->isDirected) {
                break;
            }
        }
    }

    void Graph::setNegativeEdges(const std::vector<std::vector<int>>& matrix){
        for (size_t i = 0; i < matrix.size(); i++)
        {
            for (size_t j = 0; j < matrix.size(); j++)
            {
                if (matrix[i][j] < 0)
                {
                    this->hasNegativeEdges = true;
                    break;
                }
            }
            if (this->hasNegativeEdges) {
                break;
            }
        }
    }

    void Graph::loadGraph(const std::vector<std::vector<int>>& matrix){
        cleanGraph();
        checkSquareMatrix(matrix);
        setDirected(matrix);
        setNegativeEdges(matrix);

        v = matrix.size();

        adjacencyMatrix = matrix;

        for(size_t i = 0; i < matrix.size(); ++i){
            for(size_t j = 0; j < matrix.size(); ++j){
                if(adjacencyMatrix[i][j] != 0){
                    edges++;
                }
            }
        }

        if(!isDirected){
            edges /= 2;
        }
    }

    void Graph::printGraph() const{
        std::cout << "Graph with " << v << " vertices and " << edges << " edges." << std::endl;
    }

}
