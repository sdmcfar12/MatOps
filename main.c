#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdbool.h>



//------------------------------------------------------

void multiply (float** a, float** b, float** c, int n)
{
  int i,j,k;
  for(i=0; i<n; i++)
    for(j=0; j<n; j++)
      c[i][j] = 0;

  for(i=0; i<n; i++)
    for(j=0; j<n; j++)
      for(k=0; k<n; k++)
	c[i][j] = a[i][k] * b[k][j];
}

//------------------------------------------------------

void print_matrix(float** a, int n, char* mat_name)
{
  printf("Matrix %s:\n", mat_name);
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++)
      printf("%g ", a[i][j]);
    printf("\n");
  }
  printf("\n");
}

//------------------------------------------------------

int main(int argc, char*argv[])
{
  int i,j,k;
  int n=4;
  float** a, **b, **c;

  //allocate memory
  a = malloc(n* sizeof(float*));
  b = malloc(n* sizeof(float*));
  c = malloc(n* sizeof(float*));

  for(i=0; i<n; i++){
    a[i] = malloc(n*sizeof(float));
    b[i] = malloc(n*sizeof(float));
    c[i] = malloc(n*sizeof(float));

    for(j=0; j<n; j++){
      a[i][j] = i*j;
      b[i][j] = i+j;
      c[i][j] = 0;
    }
  }

  multiply(a,b,c,n);
  printf("Simple Matrix Multiplication!\n\n");
  print_matrix(a, n, "A");
  print_matrix(b, n, "B");
  print_matrix(c, n, "C=A*B");
  return 0;
}


//------------------------------------------------------
