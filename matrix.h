typedef struct{
	int dim;
	float **m;
}t_matrix;

t_matrix *Create_M( int dim );

void Eliminate_M( t_matrix *m );

t_matrix *Add_M(t_matrix *A, t_matrix *B);

t_matrix *Subs_M(t_matrix *A, t_matrix *B);

t_matrix *Mult_M(t_matrix *A, t_matrix *B);

void Log_M(t_matrix *A);

int Print_E(t_matrix *m, int i, int j);

int Print_M(t_matrix *m);

