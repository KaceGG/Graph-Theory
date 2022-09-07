#include <stdio.h>

#define MAX_N 100

typedef struct{
	int n, m;
	int A[MAX_N][MAX_N];
}Graph;

void init_graph(Graph *pG, int n){
	pG->n = n;
	pG->m = 0;
	
	int u, v;
	for(u = 1; u <= n; u++){
		for(v = 1; v <= n; v++)
			pG->A[u][v] = 0;
	}
}

int main() {
    Graph G;
    int n, u, v, i;
    
    scanf("%d",&n);
    init_graph(&G,n);
    
    for(u = 1; u <= G.n; u++){
    	for(v = 1; v <= G.n; v++){
    		scanf("%d",&G.A[u][v]);
		}
	}
	
    for(u = 1; u <= G.n; u++)
    	for(v = u; v <= G.n; v++)
    		for(i = 1; i <= G.A[u][v]; i++){
	    		printf("%d %d",u,v);
    			printf("\n"); 				
			}
				
    return 0;
}
