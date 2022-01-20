#include "trajectory.h" 

matrix controller(matrix *error){
  double kp=0.2;
  double kb=-0.1;
  double ka=0.39;
  
  double p = error->mat[0];
  double a = error->mat[1];
  double b = error->mat[2];

  free(error->mat);
  matrix res = init_mat(2,1,NULL);

  if(p<1){
    res.mat[0]= kp*p;
    res.mat[1]= ka*a+kb*b;
  }
  else{
    if(kp*p>0.3)
      res.mat[0]=0.3;
    else if(kp*p<0.001)
      res.mat[0]=0.001;
    else
      res.mat[0]=kp*p;
    if((ka*a+kb*b)>0.3)
      res.mat[1] = 0.3;
    else if((ka*a+kb*b)<-0.3)
      res.mat[1] = -0.3;
    else 
      res.mat[1] = ka*a+kb*b;
  }
  return res;
}




  

