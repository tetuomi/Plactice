#include <stdio.h>
#define size 8
char posi[size][size];
int x,y;//charではだめだった。座標の変数
int rights1 = 0,rights2 = 0;//石を置く権利があるかどうか。0＝なし。1＝あり。
int winner = 0;
void read_position(int z){ //石の位置を教ええてもらう
  char input[2000];
  printf("decide player%d's stone position\n ",z);
  printf("x:");
  scanf("%s",input);
  x = input[0] -'0';
  if(input[1] != '\0'){
    x = -1;
  }
  printf("y:");
  scanf("%s",input);
  y = input[0] -'0';
  if(input[1] != '\0'){
    x = -1;
  }
  printf("\n\n\n");
}
void check(){//x,yの値が適切かどうか
  if((0 < x)&&(x < (size + 1))&&(0 < y)&&(y < (size + 1))&&posi[y - 1][x - 1] == '_'){
    rights1++;//権利を与える
    rights2++;
  }
  else{}
    }
void set_stone(char w){//座標に代入
  posi[y - 1][x - 1] = w;
}
void place_stone(){//石を置く
  printf("   ");
  for(int a = 0 ; a < size ; a++){//x座標
    printf("%2d",a + 1);
  }
  printf("(x)\n");
  for(int b = 0 ; b < size ; b++){
    printf("%2d ",b + 1);//y座標
    for(int c = 0 ; c < size ; c++){
      printf("%2c",posi[b][c]);
    }
    printf("\n");
  }
  printf("(y)\n\n\n");
}
void judge(int v , char u){//縦判定
  for(int i = 0 ; i < (size - 4) ; i++){
    for(int j = 0 ; j < size ; j++){
     if(posi[i][j] == u && 
         posi[i+1][j] == u &&
         posi[i+2][j] == u &&
         posi[i+3][j] == u &&
         posi[i+4][j] == u
         ){
        winner = winner + v;
      }
    }
  }
  for(int k = 0; k < size ; k++){//横判定
    for(int l = 0; l < (size - 4) ; l++){
      if(posi[k][l] == u && 
              posi[k][l+1] == u &&
              posi[k][l+2] == u &&
              posi[k][l+3] == u &&
              posi[k][l+4] == u 
              ){
        winner = winner + v;
      }
    }
  }
  for(int m = 0; m < (size - 4) ; m++){//左斜め判定
    for(int n = 0; n < (size - 4) ; n++ ){
     if(posi[m][n] == u && 
              posi[m+1][n+1] == u &&
              posi[m+2][n+2] == u &&
              posi[m+3][n+3] == u &&
              posi[m+4][n+4] == u 
              ){
        winner = winner + v;
      }
    }
  }
  for(int o = 0; o < (size - 4) ; o++ ){//右斜め判定
    for(int p = (size - 1); p > (size - 5) ; p-- ){
      if(posi[o][p] == u && 
              posi[o+1][p-1] == u &&
              posi[o+2][p-2] == u &&
              posi[o+3][p-3] == u &&
              posi[o+4][p-4] == u 
              ){
        winner = winner + v;
      }
    }
  }
}

void game_run (){
  printf("   ");//初期化
  for(int d = 0 ; d < size ; d++){//x座標
    printf("%2d",d + 1);
  }
  printf("(x)\n");
  for(int e = 0 ; e < size ; e++){
    printf("%2d ",e + 1);//y座標
    for(int f = 0 ; f < size ; f++){
      posi[e][f] = '_';
      printf("%2c",posi[e][f]);
    }
    printf("\n");
  }
  printf("(y)\n\n\n"); //初期化完了
  while(winner == 0){
   while(rights1 == 0){
  read_position(1);
  check();
   }
   if(rights1 == 1){
  set_stone('o');
   place_stone();
  judge(1,'o');//ここでwinnerに1を代入してもwinner==0のwhile文を抜けれなかった
  if(winner == 1){
    break;
  }
  rights1--;//権利をなくす
  rights2--;
   }
   while(rights2 == 0){
    read_position(2);
    check();
    }
   if(rights2 == 1){
  set_stone('x');
  place_stone();
  judge(2,'x');
  rights1--;//権利をなくす
  rights2--;
    }
     int filled_cell = 0;
   for(int g = 0 ; g < size ; g++){
     for(int h = 0 ; h < size ; h++){
       if(posi[g][h] != '_'){
         filled_cell++;
       }
     }
   }
   if(filled_cell == size*size){
     break;
   }
  }
  if(winner == 0){
    printf("------------------\n\n\n");
    printf("drawwwwwwww\n\n\n");
    }
  if(winner == 1 || winner == 2){
    printf("------------------\n\n\n");
    printf("player%d's win!!!\n\n\n",winner);
  }
}
