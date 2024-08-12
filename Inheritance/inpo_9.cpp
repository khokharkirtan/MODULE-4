//9. Write a Program of Two 1D Matrix Addition using Operator Overloading
#include <iostream>


using namespace std;  // Use the entire std namespace

class Matrix1D {
private:
    int* data;
    int size;

public:
    // Constructor to initialize the matrix with a given size
    Matrix1D(int size) : size(size) {
        data = new int[size];
    }

    // Copy constructor
    Matrix1D(const Matrix1D& other) : size(other.size) {
        data = new int[size];
        for (int i = 0; i < size; ++i) {
            data[i] = other.data[i];
        }
    }

    // Destructor to free allocated memory
    ~Matrix1D() {
        delete[] data;
    }

    // Function to input matrix data
    void input() {
        cout << "Enter " << size << " elements: ";
        for (int i = 0; i < size; ++i) {
            cin >> data[i];
        }
    }

    // Function to display matrix data
    void display() const {
        cout << "[ ";
        for (int i = 0; i < size; ++i) {
            cout << data[i] << " ";
        }
        cout << "]" << endl;
    }

    // Overload + operator to add two 1D matrices
    Matrix1D operator+(const Matrix1D& other) const {
        if (size != other.size) {
            cerr << "Error: Matrices must be of the same size to add." << endl;
            return Matrix1D(0); // Return an empty matrix in case of error
        }

        Matrix1D result(size);
        for (int i = 0; i < size; ++i) {
            result.data[i] = data[i] + other.data[i];
        }

        return result;
    }
};

int main() {
    int size;
    cout << "Enter the size of the matrices: ";
    cin >> size;

    Matrix1D matrix1(size);
    Matrix1D matrix2(size);

    cout << "Matrix 1:" << endl;
    matrix1.input();

    cout << "Matrix 2:" << endl;
    matrix2.input();

    Matrix1D result = matrix1 + matrix2;

    cout << "Resultant Matrix after Addition:" << endl;
    result.display();

    return 0;
}

