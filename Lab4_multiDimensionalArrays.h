
//---------------VANEEZA AHMAD--------------
//--------------21i-0390-------------------
//--------------SECTION A------------------
#include<iostream>
#include<ctime>
using namespace std;

//task1
//In this task, we will make number of rowsand columns variable.Thus, we will have a
//way of defining a generic 2D matrix according to user choice.Now your goal is to write a
//function that receives three arguments :
//(i)an alias to a 2D pointer;
//(ii)number of rows; and
//(iii)number of columns;
//Now your goal is to first allocate the memory for rowsand then for columns dynamically
//using new operator.


void allocate(int**& p, int nrows, int ncols)
{
	srand((time(0)));

	p = new int* [nrows];

	for (int i = 0; i < nrows; i++)
	{
		p[i] = new int[ncols];
	}

	for (int i = 0; i < nrows; i++)
	{
		for (int j = 0; j < ncols; j++)
		{
			p[i][j] = rand() % 100;
		}
	}
}

//In this function, your goal is to write code for deallocating a dynamically allocated 2D
//matrix.Your function will receive three arguments :
//(i)a 2D pointer;
//(ii)number of rows; and
//(iii)number of columns.Complete the code to properly deallocate.

void deallocate(int** p, int nrows, int ncols)
{
	for (int i = 0; i < nrows; i++)
	{
		delete[] p[i];
	}
	delete[] p;
}


//task2
//Write a C++ program for two - dimensional array A of size m x n using above function, to find
//a single max number in each row.Populate a 1D array with the resultant values and return.
int* max(int**& p, int nrows, int ncols)
{
	int* arr = new int[nrows];

	for (int i = 0; i < nrows; i++)
	{
		int max = p[i][0];
		for (int j = 0; j < ncols; j++)
		{
			if (p[i][j] > max)
				max = p[i][j];
			arr[i] = max;
		}
	}
	return arr;
}

//In this question you will use the functions defined in the previous tasks to createand compute
//sum of two nrows X ncols matrices, where nrowsand ncols will be passed as arguments to
//the function.First define two 2D pointers call them matrixA and matrixB.Now call the
//function defined in above tasks to allocate the memory for both the matrices.Next randomly
//fill both the matricesand then store the sum of these two matrices in new created matrix
//matrixC.Finally, deallocate the memory of matrixAand matrixB using function from the
//previous taskand return the matrixC from the function without deallocating.

int** sum(int nrows, int ncols)
{
	int** MatrixA;
	int** MatrixB;

	allocate(MatrixA, nrows, ncols);
	allocate(MatrixB, nrows, ncols);

	int** MatrixC;
	allocate(MatrixC, nrows, ncols);

	for (int i = 0; i < nrows; i++)
	{
		for (int j = 0; j < ncols; j++)
		{
			MatrixC[i][j] = MatrixA[i][j] + MatrixB[i][j];  //overwrite the values of C with Sums
		}
	}
	deallocate(MatrixA, nrows, ncols);
	deallocate(MatrixB, nrows, ncols);
	return MatrixC;
}


//-----task3
//Now your goal is to write a function that receives four arguments :
//(i)an alias to a 3D pointer;
//(ii)number of pages(or number of matrices);
//(iii)number of rows; and
//(iv)number of columns.
//Now your goal is to first allocate the memory for pages, rowsand then for columns
//dynamically using new operator.
void allocateThreeD(int***& p, int npages, int rows, int cols)
{
	srand(time(0));
	p = new int** [npages];

	for (int i = 0; i < npages; i++)
	{
		p[i] = new int* [rows];
		for (int j = 0; j < rows; j++)
		{
			p[i][j] = new int[cols];
		}
	}

	for (int i = 0; i < npages; i++)
	{
		for (int j = 0; j < rows; j++)
		{
			for (int k = 0; k < cols; k++)
			{
				p[i][j][k] = rand()%100;
			}
		}
	}
}
//In this function, your goal is to write code for deallocating a dynamically allocated 3D
//matrix.Your function will receive four arguments :
//(i)a 3D pointer;
//(ii)number of pages;
//(iii)number of rows; and
//(iv)number of columns.
//Complete the code to properly deallocate the 3D array.
void deAllocateThreeD(int*** p, int npages, int rows, int cols)
{
	for (int i = 0; i < npages; i++)
	{
		for (int j = 0; j < rows; j++)
		{
			delete[] p[i][j];
		}
		delete[] p[i];
	}
	delete[] p;
}
