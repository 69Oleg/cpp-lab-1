#include <iostream>
using namespace std;

class Matrica {
private:
  int columns;
  int rows;
  int ** matrix;
public:
  //конструткор
  Matrica(int valueStr, int valueCol) {
    rows = valueStr;
    columns = valueCol;
    matrix = new int* [rows];
    for (int i = 0; i < rows; i++) {
      matrix[i] = new int[columns];
    }
  }
  //деструктор
  ~Matrica() {
    for (int i = 0; i < rows; i++) {
      delete[] matrix[i];
    }
    delete[] matrix;
  }
  //заполняем матрицу
  void SetMatrica() {
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < columns; j++) {
        cin >> matrix[i][j];
      }  
    }
  }
  //выводим матрицу
  void PrintMatrica() {
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < columns; j++) {
        cout << matrix[i][j] << " ";
      }
      cout << endl;
    }
  }
  //перегрузка оператора раваенства двух матриц
  bool operator == (const Matrica& matrix2) const {
    if (rows != matrix2.rows || columns != matrix2.columns) {
      return false;
    }
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < columns; j++) {
        if (matrix[i][j] != matrix2.matrix[i][j]) {
          return false;
        }
      }
    }
    return true;
  }
  //перегрузка оператора неравенства двух матриц
  bool operator != (const Matrica& matrix2) const {
    return !(*this == matrix2);
  }
  //перегрузка умножения двух матриц
  Matrica operator * (const Matrica& matrix2) const {
    if (rows != matrix2.columns || columns != matrix2.columns) {
      cout << "ошибка умножения" << endl;
    }
    Matrica result(rows, matrix2.columns);
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < matrix2.columns; j++) {
        int summa_elements = 0;
        for (int k = 0; k < columns; k++) {
          summa_elements += matrix[i][k] * matrix2.matrix[k][i];
        }
        result.matrix[i][j] = summa_elements;
      }
    }
    return result;
  }
  //перегрузка умножения матрицы на скаляр
  Matrica operator*(int scalar) const {
    Matrica result(rows, columns);
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < columns; j++) {
        result.matrix[i][j] = matrix[i][j] * scalar;
      }
    }
    return result;
  }
  //перегрузка вычитания двух матриц
  Matrica operator-(const Matrica& matrix2) const {
    if (rows != matrix2.rows || columns != matrix2.columns) {
      cout << "ошибка вычитания" << endl;
    }
    Matrica result(rows, columns);
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < columns; j++) {
        result.matrix[i][j] = matrix[i][j] + matrix2.matrix[i][j];
      }
    }
    return result;
  }
  //перегрузка для сложения двух матриц
  Matrica operator+(const Matrica& matrix2) const {
    if (rows != matrix2.rows || columns != matrix2.columns) {
      cout << "ошибка сложения" << endl;
    }
    Matrica result(rows, columns);
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < columns; j++) {
        result.matrix[i][j] = matrix[i][j] + matrix2.matrix[i][j];
      }
    }
    return result;
  }
};
int main() {
  int rows1, columns1, rows2, columns2, lamda;
  cout << "строки и столбцы 1 матрицы:";
  cin >> rows1 >> columns1;
  Matrica matrix1(rows1, columns1);
  cout << "элементы 1 матрицы:" << endl;
  matrix1.SetMatrica();
  cout << "строки и столбцы 2 матрицы:";
  cin >> rows2 >> columns2;
  Matrica matrix2(rows2, columns2);
  cout << "элементы 2 матрицы:" << endl;
  matrix2.SetMatrica();
  cout << "ввести лямду:";
  cin >> lamda;
  cout << "1 матрица:" << endl;
  matrix1.PrintMatrica();
  cout << "2 матрица:" << endl;
  matrix2.PrintMatrica();
  if (matrix1 == matrix2) {
    cout << "равенство: true" << endl;
  }
  else
  {
    cout << "равенство: false" << endl;
  }
  cout << "сложение матриц:" << endl;
  Matrica plusmatrix = matrix1 + matrix2;
  plusmatrix.PrintMatrica();
  Matrica multiplicationmatrix = matrix1 * matrix2;
  cout << "умножение матриц:" << endl;
  multiplicationmatrix.PrintMatrica();
  cout << "умножение 1 матрицы на число:" << endl;
  Matrica multiplicationLamda1 = matrix1 * lamda;
  multiplicationLamda1.PrintMatrica();
  cout << "умножение 2 матрицы на число:" << endl;
  Matrica multiplicationLamda2 = matrix2 * lamda;
  multiplicationLamda2.PrintMatrica();
}