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

int degree(Graph *pG, int u){ //bac cua dinh bang so dinh ke cua dinh do
	int i, deg_u = 0;
	for(i = 0; i < pG->m; i++){
		if(pG->edges[i].u == u) deg_u++;
		if(pG->edges[i].v == u) deg_u++;
	}
	return deg_u;
}

int main(){
    freopen("dt.txt", "r", stdin);
    int i, n, m, u, v;
    Graph G;
    
    scanf("%d %d", &n, &m);
    init_graph(&G, n);
    
    for(i = 0; i < m; i++){
        scanf("%d %d", &u, &v);
        add_edge(&G, u, v);
    }

    for(u = 1; u <= G.n; u++)
        printf("deg(%d) = %d\n", u, degree(&G, u));
        
    return 0;
}
_____________________________________________________________________________________________________________________________________________________________________
#include <stdio.h>

#define MAX_M 500 //So cung toi da ma do thi co the chua

typedef struct{ //CTDL Edge bieu dien 1 cung (u,v)
	int u, v; //Moi cung luu dinh dau u, dinh cuoi v
}Edge;

typedef struct{ //CTDL Graph bieu dien 1 do thi
	int n, m; //n dinh, m cung
	Edge edges[MAX_M]; //mang luu tru cac cung;
}Graph;

void init_graph(Graph *pG, int n, int m){
	pG->n = n;
	pG->m = 0;
}

void add_edge(Graph *pG, int u, int v){
	pG->edges[pG->m].u = u;
	pG->edges[pG->m].v = v;
	pG->m++;		
}

int degree(Graph *pG, int u){ //bac cua dinh bang so dinh ke cua dinh do
	int i, deg_u = 0;
	for(i = 0; i < pG->m; i++){
		if(pG->edges[i].u == u) deg_u++;
		if(pG->edges[i].v == u) deg_u++;
	}
	return deg_u;
}

int main() {
    Graph G;
    int n, m, e, u, v;
    //Mở file dothi.txt để đọc dữ liệu
    FILE *file = fopen("dt.txt", "r");
    //Đọc số đỉnh và số cung & khởi tạo đồ thị
    fscanf(file, "%d%d", &n, &m);
    init_graph(&G, n, m);
    //Đọc m cung
    for (e = 0; e < m; e++) {
        fscanf(file, "%d%d", &u, &v);
        add_edge(&G, u, v);
    }
    
    for (u = 1; u <= n; u++)
        printf("deg(%d) = %d\n", u, degree(&G, u));
    //Đóng file
    fclose(file);
}
