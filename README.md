### DAA Submission for CIA-1
##
####  Programming language choosen:C
##

> - The expected node weights are 
	>     - A->A=0  
	> 	- A->B=3
	>	- A->C=2
	>	- A->D=2
	> 	- A->E=6 
##
### Dijkstras
>- When we are using dijkstra's algorithm we get a solution that satisfies for most of that condition since it can find path for directed graphs, but failing at finding the path for **A->D** and **A->E** since it does not consider negative weights and any alternate paths after one solution is found
>- This algorithm uses a greedy approach thus we cant check for any other alternative/efficient routes after one solution is found
>- The ouput obtained: 
>- A->A=0
>- A->B=3
>- A->c=2
>- A->D=5
>- A->E=6
		
##
### Prims 
>-	Prims algorithm is used to calculate the shortest path for all nodes in reference to its previous node
>- If a node a no other node pointing to it it will never get visited
>- Prim's algorithm do not work for a directed graph and thus the solution that we might get can be a disconnected graph with wrong MST
>- The output obtained:
>  -A-A=0
>  -A-B=0
>  A-C=0
>  A-D=0
>  A-E=-1
##
### Kruskal's 
>- This MST algorithm checks for cycles in the MST obtained  and give solution which has the minimum path
>- But in case of an directed graph kruskal's algorithm that there is a cycle and will not take few nodes into consideration
>- However, it can also be modified to work on directed graphs by considering each directed edge as two distinct edges with the same weight, one in each direction.
>- For the same reason we cannot solve solve Kruskal's algorithm with undirected graph.
>- The output obtained is:
> -A-A=0
> -A-B=-1
> -A-C=0
> -A-D=1
> -A-E=3
##
>#### Thus an algorithm that satisfies all the conditon of directed and negative weight we make use of bellman ford algorithm.		

