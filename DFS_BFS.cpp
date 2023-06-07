#include <iostream>
#include <queue>
#include <stack>

using namespace std;

void BFS(int** adjMatrix, int numNodes, int startNode, bool* visited) {
    int* queue = new int[numNodes];
    int front = 0, rear = 0;
    queue[rear++] = startNode;
    visited[startNode] = true;

    while (front != rear) {
        int currentNode = queue[front++];
        cout << currentNode << " ";

        for (int i = 0; i < numNodes; i++) {
            if (adjMatrix[currentNode][i] && !visited[i]) {
                queue[rear++] = i;
                visited[i] = true;
            }
        }
    }

    delete[] queue;
}

void DFS(int** adjMatrix, int numNodes, int startNode, bool* visited) {
    stack<int> st;
    st.push(startNode);
    visited[startNode] = true;
    cout << startNode << " ";

    while (!st.empty()) {
        int currentNode = st.top();

        bool foundUnvisitedNeighbor = false;
        for (int i = 0; i < numNodes; i++) {
            if (adjMatrix[currentNode][i] && !visited[i]) {
                st.push(i);
                visited[i] = true;
                cout << i << " ";
                foundUnvisitedNeighbor = true;
                break;
            }
        }

        if (!foundUnvisitedNeighbor)
            st.pop();
    }
}

void printAdjList(int** adjMatrix, int numNodes) {
    cout << "Adjacency List:" << endl;
    for (int i = 0; i < numNodes; i++) {
        cout << i << ": ";
        for (int j = 0; j < numNodes; j++) {
            if (adjMatrix[i][j])
                cout << j << " ";
        }
        cout << endl;
    }
}
void printMatrix(int** graph, int numNodes) {
    cout << "Adjacency Matrix:" << endl;
    for (int i = 0; i < numNodes; i++) {
        for (int j = 0; j < numNodes; j++) {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
}
int main() {
    int numNodes = 6;

    int** adjMatrix = new int*[numNodes];
    for (int i = 0; i < numNodes; i++) {
        adjMatrix[i] = new int[numNodes]();
    }

    adjMatrix[0][1] = 1;
    adjMatrix[0][2] = 1;
    adjMatrix[1][0] = 1;
    adjMatrix[1][3] = 1;
    adjMatrix[1][4] = 1;
    adjMatrix[2][0] = 1;
    adjMatrix[2][4] = 1;
    adjMatrix[3][1] = 1;
    adjMatrix[3][4] = 1;
    adjMatrix[3][5] = 1;
    adjMatrix[4][1] = 1;
    adjMatrix[4][2] = 1;
    adjMatrix[4][3] = 1;
    adjMatrix[4][5] = 1;
    adjMatrix[5][3] = 1;
    adjMatrix[5][4] = 1;

    printAdjList(adjMatrix, numNodes);
    cout << endl;
    
    printMatrix(adjMatrix, numNodes);
    cout << endl;
    int startNode = 0;
    bool* visited = new bool[numNodes]();

    cout << "Depth-First Search (DFS): ";
    DFS(adjMatrix, numNodes, startNode, visited);
    cout << endl;

    for (int i = 0; i < numNodes; i++) {
        visited[i] = false;
    }

    cout << "Breadth-First Search (BFS): ";
    BFS(adjMatrix, numNodes, startNode, visited);
    cout << endl;
// Clean up memory By using delete[] graph, the dynamically allocated memory for the graph is properly released, preventing memory leaks and ensuring the resources are freed for reuse.
    delete[] visited;

    for (int i = 0; i < numNodes; i++) {
        delete[] adjMatrix[i];
    }
    delete[] adjMatrix;

    return 0;
}
/*Represent a given graph using adjacency matrix/list to perform DFS and using adjacency 
list to perform BFS. Use the map of the area around the college as the graph. Identify 
the prominent land marks as nodes and perform DFS and BFS on that.
*/


/*
DFS (Depth-First Search):
Create a stack to keep track of visited nodes.
Push the start node onto the stack and mark it as visited.
While the stack is not empty:
Pop a node from the stack and print it.
Traverse all adjacent nodes of the current node.
If an adjacent node is not visited and there is an edge from the current node to it:
Push the adjacent node onto the stack and mark it as visited.
Repeat the above steps until the stack is empty.
BFS (Breadth-First Search):
Create a queue to keep track of visited nodes.
Enqueue the start node into the queue and mark it as visited.
While the queue is not empty:
Dequeue a node from the queue and print it.
Traverse all adjacent nodes of the current node.
If an adjacent node is not visited and there is an edge from the current node to it:
Enqueue the adjacent node into the queue and mark it as visited.
Repeat the above steps until the queue is empty.
*/
