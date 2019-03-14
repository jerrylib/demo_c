#include <stdio.h>
#include <windows.h>
#define ARRAY_SIZE(x) (sizeof(x) / sizeof((x)[0]))

void printfTable(const int *tableArray)
{
  // 打印table
  for (int i = 0; i < ARRAY_SIZE(tableArray); i++)
  {
    if (i % 3 == 0 || i == ARRAY_SIZE(tableArray))
    {
      printf("-----------------------------\n");
    }
    for (int j = 0; j < ARRAY_SIZE(tableArray[i]); j++)
    {
      if (j % 3 == 0)
      {
        printf("|");
      }
      printf(" %1d ", tableArray[i][j]);
    }
    printf("|\n");
  }
}

int main()
{
  int tableArray[9][9] = {{0}};

  int locationX, locationY, value;

  do
  {
    printf("plz input location:\n");
    scanf("%d", &locationX);
    scanf("%d", &locationY);
    printf("plz input value:\n");
    scanf("%d", &value);
    printf("location => [%d,%d] => %d\n", locationX, locationY, value);
    tableArray[locationX][locationY] = value;
    printfTable(tableArray);
  } while (locationX != -1);
  system("pause");
  return 0;
}
