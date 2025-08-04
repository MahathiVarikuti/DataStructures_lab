#include <stdio.h>
#include <stdlib.h>

// Structure to represent an item
typedef struct {
    int weight;
    int profit;
    float ratio;  // Profit to weight ratio
} Item;

// Structure to represent a node in the search tree
typedef struct {
    int level;      // Level of the node (index of item being considered)
    int profit;     // Profit accumulated so far
    int weight;     // Weight accumulated so far
    float bound;    // Upper bound of the maximum profit that can be obtained
} Node;

// Compare function for sorting items based on the profit-to-weight ratio
int compare(const void *a, const void *b) {
    float r1 = ((Item *)a)->ratio;
    float r2 = ((Item *)b)->ratio;
    return (r1 < r2) - (r1 > r2);
}

// Function to calculate the upper bound for a given node
float bound(Node u, int n, int W, Item items[]) {
    // If weight of the current node is already more than the capacity
    if (u.weight >= W) return 0;

    // Initialize bound
    float bound = u.profit;

    // Start including items from the next level
    int j = u.level + 1;
    int totalWeight = u.weight;

    // Add items greedily while the total weight is within the capacity
    while (j < n && totalWeight + items[j].weight <= W) {
        totalWeight += items[j].weight;
        bound += items[j].profit;
        j++;
    }

    // If there are items left to include and the total weight is still within capacity
    if (j < n) {
        bound += (W - totalWeight) * items[j].ratio;
    }

    return bound;
}

// Branch and Bound to solve 0/1 Knapsack problem
int knapsack(int n, int W, Item items[]) {
    // Create a priority queue of nodes (using an array here for simplicity)
    Node queue[100];
    int front = -1, rear = -1;

    // Sort items by their profit/weight ratio in decreasing order
    qsort(items, n, sizeof(Item), compare);

    // Start with the root node (no items included)
    Node u = { -1, 0, 0, 0.0 };
    Node v;
    int maxProfit = 0;

    // Insert root node into the queue
    queue[++rear] = u;

    // Process nodes in the queue
    while (front != rear) {
        u = queue[++front];

        // Explore the next level by including or excluding the current item
        if (u.level == -1)
            v.level = 0;
        if (u.level == n - 1)
            continue;

        // Include the next item
        v.level = u.level + 1;
        v.weight = u.weight + items[v.level].weight;
        v.profit = u.profit + items[v.level].profit;

        // If the weight does not exceed the capacity, update the max profit if needed
        if (v.weight <= W && v.profit > maxProfit)
            maxProfit = v.profit;

        // If the upper bound is greater than the maxProfit, add this node to the queue
        v.bound = bound(v, n, W, items);
        if (v.bound > maxProfit)
            queue[++rear] = v;

        // Exclude the next item
        v.weight = u.weight;
        v.profit = u.profit;
        v.bound = bound(v, n, W, items);
        if (v.bound > maxProfit)
            queue[++rear] = v;
    }

    return maxProfit;
}

int main() {
    // Example input for knapsack problem
    int n = 4;  // Number of items
    int W = 7;  // Maximum capacity of the knapsack
    Item items[] = {
        { 3, 4, 4.0 },  // {weight, profit, profit/weight}
        { 2, 3, 1.5 },
        { 4, 5, 1.25 },
        { 5, 7, 1.4 }
    };

    // Sort items by profit/weight ratio
    for (int i = 0; i < n; i++) {
        items[i].ratio = (float)items[i].profit / items[i].weight;
    }

    // Call the knapsack function
    int maxProfit = knapsack(n, W, items);

    printf("Maximum profit: %d\n", maxProfit);

    return 0;
}
