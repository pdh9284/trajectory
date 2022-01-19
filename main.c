# include "trajectory.h"

int main(void){


  char *val_ut[]      = {"1","1",NULL};
  char *val_bot_pos[] = {"1","1","0",NULL};
  char *val_target[]  = {"-7","-5","90",NULL};

  matrix ut            = init_mat(2,1,val_ut);
  matrix bot_pose_temp = init_mat(3,1,val_bot_pos);
  matrix target_temp   = init_mat(3,1,val_target);
  matrix bot_pose      = D_to_R(&bot_pose_temp);
  matrix target        = D_to_R(&target_temp);
  matrix error         = init_mat(3,1,NULL);

/*  printf("[%f %f %f]\n",bot_pose.mat[0],bot_pose.mat[1],bot_pose.mat[2]);
 
  bot_pose = motion(&ut , &bot_pose);

  printf("[%f %f %f]\n",bot_pose.mat[0],bot_pose.mat[1],bot_pose.mat[2]);

  matrix error = init_mat(3,1,NULL);
  error = error_function(&target , &bot_pose);

  printf("[%f %f %f]\n",error.mat[0],error.mat[1],error.mat[2]);
  
  matrix new_u = init_mat(2,1,NULL);
  new_u = controller(&error);

  printf("[%f %f]\n",new_u.mat[0],new_u.mat[1]);
*/
  FILE *fp =NULL;
  fp = fopen("data.txt","w");
  double ti=0.0, tf=10.0 ,ts=0.1;
  for(ti=0.0;ti<=tf;ti+=ts){
    bot_pose = motion(&ut, &bot_pose);
    error    = error_function(&target,&bot_pose);
    ut       = controller(&error);
    fprintf(fp,"%f %f\n",bot_pose.mat[0],bot_pose.mat[1]);
  }

  printf("[%f %f %f]\n",bot_pose.mat[0],bot_pose.mat[1],bot_pose.mat[2]); 
  return 0;

 }
