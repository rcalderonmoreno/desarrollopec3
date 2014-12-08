#include <stdio.h>
#include "matrix.h"

void main()
{
	t_matrix *A, *B, *C, *D, *E;
	A = Create_M(5);
	B = Create_M(5);
	Print_M(A); Print_E(A,3,3);
	Print_M(B);	
	C = Add_M( A, B );
	D = Subs_M( A, B );
	E = Mult_M( A, B );
	Log_M(A);
    	Print_M( A ); Print_E(A,3,3);
    	Print_M( C ); Print_E(C,3,3);
    	Print_M( D ); Print_E(D,3,3);
    	Print_M( E ); Print_E(E,3,3);
    	Eliminate_M(A);
    	Eliminate_M(B);
    	Eliminate_M(C);
    	Eliminate_M(D);
    	Eliminate_M(E);
}
