#include <stdio.h>

#define MAX_M 500 //So cung toi da ma do thi co the chua

typedef struct{ //CTDL Edge bieu dien 1 cung (u,v)
	int u, v; //Moi cung luu dinh dau u, dinh cuoi v
}Edge;

typedef struct{ //CTDL Graph bieu dien 1 do thi
	int n, m; //n dinh, m cung
	Edge edges[MAX_M]; //mang luu tru cac cung;
}Graph;

void init_graph(Graph *pG, int n){
	pG->n = n;
	pG->m = 0;
}

void add_edge(Graph *pG, int u, int v){
	pG->edges[pG->m].u = u;
	pG->edges[pG->m].v = v;
	pG->m++;		
}

int adjacent(Graph *pG, int u, int v){ //kiem tra dinh ke cua do thi vo huong
	int i;
	for(i = 0; i < pG->m; i++){
		if(pG->edges[i].u == u && pG->edges[i].v == v)
			return 1;
	}
	return 0;
}

int degree(Graph *pG, int u){ //bac cua dinh bang so dinh ke cua dinh do
	int i, deg_u = 0;
	for(i = 0; i < pG->m; i++){
		if(pG->edges[i].u == u) deg_u++;
		if(pG->edges[i].v == u) deg_u++;
	}
	return deg_u;
}

void neighbours(Graph *pG, int u){
	int v;
	for(v = 1; v <= pG->n; v++){
		if(adjacent(pG,u,v)) //neu u ke voi v
			printf("%d ",v); //liet ke v
	}
	printf("\n");
}

int main() {
	Graph G;
	int n, m, e, u, v;
	
	scanf("%d%d", &n, &m);
	init_graph(&G,n);
	
	for (e = 0; e < m; e++) {
		scanf("%d%d", &u, &v);
		add_edge(&G, u, v);
	}
	
    for (u = 1; u <= n; u++){
        printf("neighbours(%d) = ", u);
		neighbours(&G,u);	
    }
    
	return 0;
}
