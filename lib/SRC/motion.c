#include "trajectory.h"

matrix motion(matrix *ut, matrix *bot_pose){
  double v,w,x,y,theta;
  v=ut->mat[0];
  w=ut->mat[1];

  x=bot_pose->mat[0];
  y=bot_pose->mat[1];
  theta=bot_pose->mat[2];

  matrix res = init_mat(3,1,NULL);

  res.mat[0] = x-v/w*sin(theta)+v/w*sin(theta+w);
  res.mat[1] = y+v/w*cos(theta)-v/w*cos(theta+w);
  res.mat[2] = theta+w;

  return(res);
}
