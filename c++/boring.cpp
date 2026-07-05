template <typename T>
class Matrix
{
private:
    int row, col;
    vector<vector<T>> matrix;

public:
    Matrix() : row(0), col(0), matrix(0, vector<T>(0)) {}
    Matrix(int row, int col) : row(row), col(col), matrix(row, vector<T>(col, 0)) {}
    Matrix(vector<vector<T>> matrix)
    {
        this->row = matrix.size();
        this->col = matrix[0].size();
        this->matrix = matrix;
    }

    void print()
    {
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
                cout << matrix[i][j] << " ";
            cout << endl;
        }
    }

    Matrix operator+(const Matrix &other)
    {
        Matrix<T> res(row, col);
        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++)
                res.matrix[i][j] = matrix[i][j] + other.matrix[i][j];
        return res;
    }

    Matrix operator*(const Matrix &other)
    {
        Matrix<T> res(row, other.col);
        for (int i = 0; i < row; i++)
            for (int j = 0; j < other.col; j++)
                for (int k = 0; k < col; k++)
                    res.matrix[i][j] += matrix[i][k] * other.matrix[k][j];
        return res;
    }

    T key_val()
    {
        int x = rand() % row;
        int y = rand() % col;
        return matrix[x][y];
    }
};
