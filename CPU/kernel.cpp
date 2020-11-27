#include<bits/stdc++.h>
#include<iostream>

using namespace std;

#define N 256
#define A(i,j) A[(i)*cols+j]
#define C(i,j) C[(i)*cols+j]

static double diffclock(clock_t clock1,clock_t clock2)
{
    double diffticks=clock1-clock2;
    double diffms=(diffticks)/(CLOCKS_PER_SEC/1000);
    return diffms;
}

void convolution(int *A, int *C)
{
  int filter[3][3] = { { 1, 2, 1 }, { 2, 4, 2 }, { 1, 2, 1 } };

  int cols = N+2;

  for(int i=0; i<N+1; i++)
    for(int j=0; j<N+1; j++){
      int value = 0;
      value = value + A(i - 1, j - 1)	*  filter[0][0];
      value = value + A(i - 1, j)		*  filter[0][1];
      value = value + A(i - 1, j + 1)	*  filter[0][2];
      value = value + A(i, j - 1)		*  filter[1][0];
      value = value + A(i, j)			*  filter[1][1];
      value = value + A(i, j + 1)		*  filter[1][2];
      value = value + A(i + 1, j - 1)	*  filter[2][0];
      value = value + A(i + 1, j)		*  filter[2][1];
      value = value + A(i + 1, j + 1)	*  filter[2][2];
      C(i, j) = value;
    }
}

int main()
{
  int A[(N+2)*(N+2)] = {};//+2 for padding matrix
  int *C;

  clock_t start, end;

  //Needs for row-major layout
  int cols = N + 2;

  //Calculate memory size
  int memorySize = (N + 2) * (N + 2);

  start = clock();

  for (int i = 0; i < N+2; i++) {
    for (int j = 0; j < N+2; j++) {
      A(i,j) = 0;
    }
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      A(i + 1,j + 1) = rand() % 10;
    }
  }

  C = new int[memorySize];

  convolution(A,C);

  end = clock();

  double milliseconds = diffclock(end,start);

  cout<<"Time Taken by CPU: "<<milliseconds<<" ms";

}
