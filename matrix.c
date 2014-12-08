#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <unistd.h>
#include <math.h>
#include "matrix.h"

t_matrix *Create_Empty( int dim )
{
	t_matrix *aux;
	int i, j;

	if (!(aux=malloc( sizeof(t_matrix))))
		return NULL;
	aux->dim = dim;
	if (!(aux->m = malloc(dim*sizeof(float *)))){
		free( aux );
		return NULL;
	}
	for( i=0; i < dim; i++ )
		if (!(aux->m[i] = malloc(dim*sizeof( float )))){
			for( j=1; j < i; j++)
				free(aux->m[j]);
			free(aux);
			return NULL;
		}
	return aux;
}

t_matrix *Create_M(int dim)
{
	t_matrix *aux;
	int i, j;

	sleep( 1 );
	srandom( time( NULL ) );
   	if ( !(aux = Create_Empty( dim ))) return NULL;
	for (i = 0; i < dim-1; i++)
		for (j = 0; j < dim-1; j++)
			aux->m[i][j] = 1.0*(random()%1000);

	return aux;
}

void Eliminate_M(t_matrix *m)
{
	int i;

	for( i=0; i < m->dim; i++ )
		free(m->m[i]);
	free( m );
}

t_matrix *Add_M(t_matrix *A, t_matrix *B)
{
	int i,j;
	t_matrix *aux;

	if ( A->dim != B->dim) return NULL;
	if (!(aux=Create_Empty(A->dim))) return NULL;

	for(i=0; i<A->dim; i++)
		for(j=0; j<A->dim; j++)
			aux->m[i][j] = A->m[i][j] + B->m[i][j];

	return aux;
}

t_matrix *Subs_M(t_matrix *A, t_matrix *B)
{
	int i,j;
	t_matrix *aux;

	if ( A->dim != B->dim) return NULL;
	if (!(aux=Create_Empty(A->dim))) return NULL;

	for(i=0; i<A->dim; i++)
		for(j=0; j<A->dim; j++)
			aux->m[i][j] = A->m[i][j] - B->m[i][j];

	return aux;
}

t_matrix *Mult_M(t_matrix *A, t_matrix *B)
{
	int i,j,k;
	t_matrix *aux;

	if ( A->dim != B->dim) return NULL;
	if (!(aux=Create_Empty(A->dim))) return NULL;

	for(i=1; i<A->dim; i++)
		for(j=1; j<A->dim; j++){
			aux->m[i][j]=0;
			for( k=1; k<A->dim; k++)
				aux->m[i][j]+=((A->m[i][k])*(B->m[k][j]));
		}
	return aux;
}

void Log_M(t_matrix *A)
{
	int i,j;

	for(i=0; i<A->dim; i++)
		for(j=0; j < A->dim; j++)
			A->m[i][j]=log10(A->m[i][j]);
}

int Print_E(t_matrix *m, int i, int j)
{
	if (m){
		printf("M(%d,%d) = %f\n", i, j, m->m[i][j]);
		return 1;
	}
	return 0;
}

int Print_M(t_matrix *m)
{
	int i, j;

	if (!m) return 0;

	for( i= 0; i < m->dim; i++){
		for( j= 0; j < m->dim; j++)
			printf("%10.2f \t", m->m[i][j]);
		printf("\n");
	}
	printf("\n");
	return 1;
}
