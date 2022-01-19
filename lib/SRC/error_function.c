#include "trajectory.h"

matrix error_function(matrix *target, matrix *bot_pose){
  double xt , yt, thetat, xb, yb,thetab;
  xt =      target->mat[0];
  yt =      target->mat[1];
  thetat =  target->mat[2];

  xb =      bot_pose->mat[0];
  yb =      bot_pose->mat[1];
  thetab =  bot_pose->mat[2];


  matrix res = init_mat(3,1,NULL);
  res.mat[0] = sqrt(pow((xt-xb),2)+pow((yt-yb),2));
  res.mat[1] = atan2((yt-yb),(xt-xb))-thetab;
  res.mat[2] = thetat-res.mat[1]-thetab;
  
  return(res);
}
