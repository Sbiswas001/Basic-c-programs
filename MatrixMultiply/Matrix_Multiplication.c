#include<stdio.h>
#include<math.h>

int main(){
    int a,b,c,d;
    printf("Enter the value of rows of first matrix:");
    scanf("%d",&a);
    printf("Enter the value of columns of first matrix:");
    scanf("%d",&b);
    printf("Enter the value of rows of second matrix:");
    scanf("%d",&c);
    printf("Enter the value of columns of second matrix:");
    scanf("%d",&d);
    if(b!=c){
        printf("SORRY! multiplication can't be done\n");
        return 1;
    }
    int matrix_1[a][b];
    int matrix_2[c][d];
    printf("For the first matrix:\n\n");
    for(int i=1;i<=a;i++){
       for(int j=1;j<=b;j++){
        printf("Enter the %d row's %d column's element:",i,j);
        scanf("%d",&matrix_1[i][j]);
       }
    }
    printf("For the second matrix:\n\n");
    for(int i=1;i<=c;i++){
       for(int j=1;j<=d;j++){
        printf("Enter the %d row's %d column's element:",i,j);
        scanf("%d",&matrix_2[i][j]);
       }
    }
    int res_matrix[a][d];
    for(int i=1;i<=a;i++){
        for(int j=1;j<=d;j++){
            res_matrix[i][j] = 0;
        }
    }

    for(int i=1;i<=a;i++){
        for(int j=1;j<=d;j++){
            for(int k=1;k<=b;k++){
                res_matrix[i][j] += matrix_1[i][k]*matrix_2[k][j];
            }
        }
    }
    printf("So the result of the multiplication is:\n\n");
    for(int i=1;i<=a;i++){
        for(int j=1;j<=d;j++){
            printf("The %d row's %d column's element is:%d\n",i,j,res_matrix[i][j]);
        }
    }
    return 1;
}
