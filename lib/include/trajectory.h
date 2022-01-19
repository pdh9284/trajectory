#ifndef MATRIX_H_
# define MATRIX_H_

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define MAT_H dim[0]
#define MAT_W dim[1]

#define pi 3.141592

typedef struct matrix_struct{
  double *mat;
  int dim[2];
}matrix;

//function for matrix
matrix  init_mat(int height, int width, char** values);
matrix  id_mat(int dim);
matrix  mat_p(matrix *m1, matrix *m2);
matrix  mat_m(matrix *m1, matrix *m2);
matrix  mat_x(matrix *m1, matrix *m2);
matrix  mat_x_n(matrix *m, double n);
matrix  mat_pow(matrix *m, int n);
matrix  cpy_mat(matrix *m);
void    del_mat(matrix m);
void    disp_mat(matrix *m);

//function for trajectory
matrix D_to_R(matrix *m);
matrix motion(matrix *ut, matrix *bot_pose);
matrix error_function(matrix *target, matrix *bot_pose);
matrix controller(matrix *error);
#endif
