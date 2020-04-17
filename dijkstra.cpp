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


