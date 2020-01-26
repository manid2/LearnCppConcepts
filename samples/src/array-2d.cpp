// C++ program to create and initialize 2D array
#include <iostream>

void print2DArray(int **arr_2d, int rows, int cols)
{
  std::cout << "2D array using array of pointers:"
            << "\n";
  for (int r = 0; r < rows; ++r)
  {
    for (int c = 0; c < cols; ++c)
    {
      std::cout << arr_2d[r][c] << " ";
    }
    std::cout << "\n";
  }
}

void delete2DArray(int **arr_2d, int rows, int cols)
{
  if (arr_2d)
  {
    for (int r = 0; r < rows; ++r)
    {
      delete[] arr_2d[r];
      arr_2d[r] = NULL;
    }
    delete arr_2d;
    arr_2d = NULL;
  }
}

int main(int argc, char **argv)
{
  // Using array of pointers
  {
    int count = 0;
    int **arr = NULL;
    arr = new int *[3]();
    for (int r = 0; r < 3; ++r)
    {
      arr[r] = new int[3]();
      for (int c = 0; c < 3; ++c)
      {
        arr[r][c] = ++count;
      }
    }
    print2DArray(arr, 3, 3);
    delete2DArray(arr, 3, 3);
  }

  // Using a single pointer -- efficient
  {
    const int rows = 3;
    const int cols = 4;
    int *arr_2d = new int[rows * cols * sizeof(int)]();

    int i, j, count = 0;
    for (i = 0; i < rows; ++i)
    {
      for (j = 0; j < cols; ++j)
      {
        arr_2d[i * cols + j] = ++count;
      }
    }

    std::cout << "2D array using single pointer:\n";
    for (i = 0; i < rows; ++i)
    {
      for (j = 0; j < cols; ++j)
      {
        std::cout << arr_2d[i * cols + j] << " ";
      }
      std::cout << "\n";
    }

    if (arr_2d)
      delete[] arr_2d;
  }
  return 0;
}
