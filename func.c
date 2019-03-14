#include <stdio.h>
void conat_func(int *);
void main(void);
void main(void)
{
  int x[10];
  int y;
  for (int y = 0; y < 10; y++)
  {
    x[y] = y * 10;
  }
  printf("%d-----%d\n", &x[0], x[0]);
  // conat_func(x);
  int array[3] = {1, 2, 3, 4, 5, 6};
  system("pause");
}
void conat_func(int *i)
{
  int y;
  for (y = 0; y < 10; y++)
    printf("%d\n", *(i + y));
}
