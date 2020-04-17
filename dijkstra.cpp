/* Program to find the paths from one router to all other routers in a connected network */
/* Algorithm: Link State (Dijkstra's algorithm) */
/* Student: Long Hoang Nguyen - ID 190200381 */
/* Date: 11/01/2020 */

#include <limits.h>
#include <stdio.h>

/* Number of routers in the network */
#define N 10
/* Define as infinity number */
#define X 100

void initialization(int visitedNodes[N], bool visited[N], int costPath[N], int cost[N][N], int source, int prev[N]){
	for (int i = 0; i < N; i++){
		/* For all node i, set costPath to i if i is adjacent to source node */
		costPath[i] = cost[source][i];
		visited[i] = false;
		/* Set the previous node of all nodes is the source node as default */
		prev[i] = source;
	}
	/* Mark all nodes except the source node as unvisited */					
	visitedNodes[0] = source;
	visited[source] = true; 
}

void printSolution(int costPath[N], int source, int prev[N]){
	printf("Node\t\tCost\t\tPath");
	for (int i = 0; i < N; i++){
		if (i == source)
			printf("\n%c\t\t-\t\t-", i+65);
		else{
			printf("\n%c\t\t%d\t\t%c", i+65, costPath[i], i+65);
			/* Print all the nodes on the way to node i from source node */
			int j = i;
			do{
				j = prev[j];
				printf("<--%c", j+65);
			} while(j != source);
		}
	}
}

int main(){
	/* A set of visited nodes so far whose least cost path is known */
	int visitedNodes[N];
	/* Boolean function checking whether a node is visited */
	bool visited[N];
	/* A matrix of all the link costs in the network topology */
	/* cost[i,j] is the cost of a link from node i to node j */
	/* cost[i,i] = 0 for all i */
	/* cost[i,j] = X if no direct link between i and j */
	int cost[N][N]={{0, 2, 3, X, X, X, X, X, X, X},
			{2, 0, X, 4, 5, X, X, X, X, X},
			{3, X, 0, 1, X, X, 3, X, X, X},
			{X, 4, 1, 0, 7, 6, 8, X, X, X},
			{X, 5, X, 7, 0, X, X, 2, X, X},
			{X, X, X, 6, X, 0, X, 1, 3, X},
			{X, X, 3, 8, X, X, 0, X, 4, X},
			{X, X, X, X, 2, 1, X, 0, X, 6},
			{X, X, X, X, X, 3, 4, X, 0, 5},
			{X, X, X, X, X, X, X, 6, 5, 0}};
	/* Source node ID */
	int source = 0;
	/* Current overall cost of a path costPath[i] from the source node to the destination node i */
	int costPath[N];
	/* Previous node prev[i] of the node i*/
	int prev[N];

	/* Program initialization */
	initialization(visitedNodes, visited, costPath, cost, source, prev);

	/* Loop run for (N-1) times */
	for (int i = 1; i < N; i++){
		/* Find an unvisited node w not in set M such that costPath to w is a minimum */
		int w;
		int minCostPath = X;
		for (int j = 0; j < N; j++){
			if ((visited[j] == false)&&(costPath[j] < minCostPath)){
				minCostPath = costPath[j];
				w = j;
			}	
		}
		/* Then add w to the set M of visited nodes */
		visitedNodes[i] = w;	
		visited[w] = true;	

		/* Update costPath(v) for all v that are adjacent to w but not in M */
		for (int v = 0; v < N; v++){
			if ((visited[v] == false)&&(costPath[v] > (costPath[w] + cost[w][v]))){
				costPath[v] = costPath[w] + cost[w][v];
				prev[v] = w;
			}
		}
	}
	/* Print out all information of all paths generated */
	printSolution(costPath, source, prev);
	printf("\n");
}

