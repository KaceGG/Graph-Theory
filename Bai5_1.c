#define MAX_M 500

typedef struct{
    int u, v;
}Edge;

typedef struct{
    int n, m;
    Edge edges[MAX_M];
}Graph;

void init_graph(Graph *pG, int n){
    pG->n = n;
    pG->m = 0;
}

void add_edge(Graph *pG, int u, int v){
	if(u < 1 || u > pG->n || v > pG->n || v < 1)
		return;
	else{
		pG->edges[pG->m].u = u;
		pG->edges[pG->m].v = v;
		pG->m++;		
	}
}

int degree(Graph *pG, int u){
    int i, deg = 0;
    for(i = 0; i < pG->m; i++){
        if(pG->edges[i].u == u) deg++;
        if(pG->edges[i].v == u) deg++;
    }
    return deg;
}
