#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

#define INF INT_MAX

class Router {
    public:
        int id;
        vector<pair<int, int>> neighbors; // neighbor (id, cost)
        vector<pair<int, int>> routingTable; // destination (id, cost)

        Router(int id) {
            this->id = id;
        }
};

// Function to implement Dijkstra's algorithm
void dijkstra(vector<Router>& routers, int source) {
    // Initialize all distances to infinity and the source to 0
    vector<int> distance(routers.size(), INF);
    distance[source] = 0;

    // Initialize priority queue with the source router
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(0, source));

    while (!pq.empty()) {
        // Get the router with the smallest distance from the queue
        int current = pq.top().second;
        pq.pop();

        // Update the distances to each neighbor of the current router
        for (auto neighbor : routers[current].neighbors) {
            int neighbor_id = neighbor.first;
            int cost = neighbor.second;
            if (distance[neighbor_id] > distance[current] + cost) {
                distance[neighbor_id] = distance[current] + cost;
                pq.push(make_pair(distance[neighbor_id], neighbor_id));
            }
        }
    }

    // Update the routing table for each router
    for (auto& router : routers) {
        int destination = router.id;
        int cost = distance[destination];
        router.routingTable.push_back(make_pair(destination, cost));
    }
}

int main() {
    // Initialize the network
    int numRouters = 3;
    vector<Router> routers;
    for (int i = 0; i < numRouters; i++) {
        routers.push_back(Router(i));
    }
    routers[0].neighbors.push_back(make_pair(1, 6));
    routers[0].neighbors.push_back(make_pair(2, 3));
    routers[1].neighbors.push_back(make_pair(0, 6));
    routers[1].neighbors.push_back(make_pair(2, 2));
    routers[2].neighbors.push_back(make_pair(0, 3));
    routers[2].neighbors.push_back(make_pair(1, 2));
    

    // Calculate the routing table for each router
    for (int i = 0; i < numRouters; i++) {
        dijkstra(routers, i);
    }

    // Print the routing table for each router
    for (auto router : routers) {
        cout << "Routing table for Router " << router.id << ":" << endl;
        for (auto entry : router.routingTable) {
            cout << "Destination: " << entry.first << ", Cost: " << entry.second << endl;
        }
        cout << endl;
    }

    return 0;
}
