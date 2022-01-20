#include "trajectory.h"

matrix D_to_R(matrix *m){
  matrix res = init_mat(3,1,NULL);
  res.mat[0]=m->mat[0];
  res.mat[1]=m->mat[1];
  res.mat[2]=(m->mat[2])*pi/180;
  free(m->mat);
  return(res);
}
