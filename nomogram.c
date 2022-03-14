//Copyright Ilinca Sebastian Ionut Grupa 311CA
#include <stdio.h>
#define K 110
void read_matrix(int mat[K][K], int n, int m);
void read_matrix_for_lines(int mat[K][K], int n);
void read_matrix_for_columns(int mat[K][K], int m);
int check_mat_l(int mat[K][K], int n, int m, int mat_lines[K][K]);
int check_mat_c(int mat[K][K], int n, int m, int mat_columns[K][K]);

void read_matrix(int mat[K][K], int n, int m)
{
	for (int i = 0; i < n; i = i + 1) {
		for (int j = 0; j < m; j = j + 1)
			scanf("%d", &mat[i][j]);
	}
	//This function read the matrix
}

void read_matrix_for_lines(int mat[K][K], int n)
{
	int groups;
	for (int i = 0; i < n; i = i + 1) {
		scanf("%d", &groups);
		mat[i][0] = groups;
		for (int j = 1; j <= mat[i][0]; j = j + 1)
			scanf("%d", &mat[i][j]);
	}
	//This function see how many groups are for every line
	//then we tell the function the dimensions
	//of every group (e.g. 3 55 4 10.
	//The programs knows that are 3 groups with the next
	//dimensions : 55, 4, 10)
}

void read_matrix_for_columns(int mat[K][K], int m)
{
	int groups;
	for (int i = 0; i < m; i = i + 1) {
		scanf("%d", &groups);
		mat[i][0] = groups;
		if (groups != 0) {
			for (int j = 1; j <= mat[i][0]; j = j + 1)
				scanf("%d", &mat[i][j]);
		}
	}
	//This function does the same thing but for
	//the columns
}

int check_mat_l(int mat[K][K], int n, int m, int mat_lines[K][K])
{
	int i = 0;
	int column_restriction = 1;
	//column_restrictions are the restrictions of a group,
	//helps to verify the group's dimension
	while (i < n) {
		int count = 0;
		//count memorise how many 1's I have
		for (int j = 0; j < m; j = j + 1) {
			//I check on the i line every column
			if (mat[i][j] == 1) {
				//if it's one I begin a group or continue one
				//I memroise how many 1's are
				count = count + 1;
				if (mat[i][j + 1] == 0 || m == j + 1) {
					//if the next value is 0
					//means that the group is ended
					//or if it's the last column
					if (count != mat_lines[i][column_restriction]) {
						return 0;
						//if the conditions aren't good then the
						//nomogram is wrongly done
					}
					if (count == mat_lines[i][column_restriction]) {
						column_restriction = column_restriction + 1;
						count = 0;
						//if the condition is good
						//we go the next line
					}
				}
			}
		}
		i = i + 1;
		column_restriction = 1;
	}
	return 1;
}

int check_mat_c(int mat[K][K], int n, int m, int mat_columns[K][K])
{
	int j = 0;
	int count = 0;
	int column_restriction = 1;
	while (j < m) {
		for (int i = 0; i < n; i = i + 1) {
			if (mat[i][j] == 1) {
				count = count + 1;
				if (mat[i + 1][j] == 0 || n == i + 1) {
					if (count != mat_columns[j][column_restriction])
						return 0;
					if (count == mat_columns[j][column_restriction]) {
						column_restriction = column_restriction + 1;
						count = 0;
					}
				}
			}
		}
		j = j + 1;
		column_restriction = 1;
	}
	return 1;
}

//The function does the same thing that the last one does
//but for the columns
int main(void)
{
	int T, mat[K][K], mat_lines[K][K], mat_columns[K][K], n;
	int m, okay_for_lines, okay_for_columns;
	scanf("%d", &T);
	while (T != 0) {
		scanf("%d%d", &n, &m);
		read_matrix_for_lines(mat_lines, n);
		read_matrix_for_columns(mat_columns, m);
		read_matrix(mat, n, m);
		okay_for_lines = check_mat_l(mat, n, m, mat_lines);
		okay_for_columns = check_mat_c(mat, n, m, mat_columns);
		if (okay_for_columns == 1 && okay_for_lines == 1)
			printf("Corect\n");
		else
			printf("Eroare\n");
		T = T - 1;
	}
}
