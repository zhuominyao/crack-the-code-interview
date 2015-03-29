//在一个二维数组中，每一行都递增，每一列也都递增。在这样的数组中查找制定的元素

#include <stdio.h>

bool find(int * matrix,int rows,int columns,int number)
{
	if(rows == 0 || columns == 0)
		return false;
	if(number == matrix[columns-1])
		return true;
	else if(number > matrix[columns-1])
		return find(matrix+columns,rows-1,columns,number);
	else
		return find(matrix,rows,columns-1,number);
}

int main()
{
	int matrix[16] = {1,2,8,9,2,4,9,12,4,7,10,13,6,8,11,15};
	if(find(matrix,4,4,20))
		printf("find\n");
	else
		printf("can't find\n");
}
