#include <stdio.h>

int main() {
  char a,b,c ;
  float n;
  printf("enter the value of temperature:");
  scanf("%f",&n);
  for(;;){
    printf("enter unit 1:");
      scanf(" %c",&a);
    if(a=='C'||a=='F'||a=='K'){
      break;
    }
  }
  for(;;){
    printf("enter unit 2:");
      scanf(" %c",&b);
    if(b=='C'||b=='F'||b=='K'){
      break;
    }
  }
  switch(a){
    case'C':switch(b){
      case'K':n= 273+n;
      break;
      case'F':n= n*9/5+32;
      break;
      case'C':n=n;
      break;
      default://intentionally do nothing.
    }
    break;
    case'F':switch(b){
      case'C':n= 5*(n-32)/9;
      break;
      case'K':n =5*(n-32)/9+273 ;
      break;
      case'F':n=n;
      break;
      default://intentionally do nothing.
    }
    break;
    case'K':switch(b){
      case'C':n= n-273;
      break;
      case'F':n =(n-273)*9/5+32 ;
      break;
      case'K':n=n;
      break;
      default://intentionally do nothing.
    }
    break;
    //default:printf("invalid input");
  }
  char degree;
  printf("the temperature is:%f",n);
  switch(b){
    case 'C':
    case 'F':printf("°%c",b);
    break;
    default://intentionally do nothing.
  }
  return 0;
}
