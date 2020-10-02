#include <stdio.h>

void display_matrix(int m, int n, int M[][n]) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d\t", M[i][j]);
        }
        printf("\n");
    }
}

void fast_transpose(int C[][3], int T[][3]) {
    T[0][0] = C[0][1];
    T[0][1] = C[0][0];
    T[0][2] = C[0][2];
    int col = C[0][1];
    int total[col], index[col+1];
    for(int i = 0; i < col; i++) {
        total[i] = 0;
    }
    for(int i = 1; i <= C[0][2]; i++) {
        int j = C[i][1];
        total[j]++;
    }
    index[0] = 1;
    for(int i = 1; i <= col; i++) {
        index[i] = index[i-1] + total[i-1];
    }
    for(int i = 1; i <= C[0][2]; i++) {
        int j = C[i][1];
        int loc = index[j];
        index[j]++;
        T[loc][0] = C[i][1];
        T[loc][1] = C[i][0];
        T[loc][2] = C[i][2];
    }
    display_matrix(T[0][2]+1, 3, T);
}

void transpose(int C[][3], int T[][3]) {
    T[0][0] = C[0][1];
    T[0][1] = C[0][0];
    T[0][2] = C[0][2];
    int k = 1;
    for (int i = 0; i < C[0][1]; i++) {
        for (int j = 1; j <= C[0][2]; j++) {
            if(i == C[j][1]) {
                T[k][0] = C[j][1];
                T[k][1] = C[j][0];
                T[k][2] = C[j][2];
                k++;
            }
        }
    }
    display_matrix(k, 3, T);
}

void compact(int m, int n, int M[][n], int C[][3]) {
    int count = 0;
    C[0][0] = m;
    C[0][1] = n;
    int row = 1;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (M[i][j] != 0) {
                C[row][0] = i;
                C[row][1] = j;
                C[row][2] = M[i][j];
                row++;
                count++;
            }
        }
    }
    C[0][2] = count;
    display_matrix(row, 3, C);
}

int main() {
    int m, n, non_zero = 0;
    printf("Enter number of rows: ");
    scanf("%d", &m);
    printf("Enter number of columns: ");
    scanf("%d", &n);
    int M1[m][n];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("Enter matrix[%d][%d]: ", i, j);
            scanf("%d", &M1[i][j]);
            if(M1[i][j] != 0)
                non_zero++;
        }
    }
    int C[non_zero][3], T[non_zero][3], FT[non_zero][3];
    display_matrix(m, n, M1);
    printf("\n");
    compact(m, n, M1, C);
    printf("\n");
    transpose(C, T);
    printf("\n");
    fast_transpose(C, FT);
}