//10. Write a program to concatenate the two strings using Operator Overloading
#include <iostream>
#include <cstring>  // Include for C-style string functions

using namespace std;  // Use the entire std namespace

class MyString {
private:
    char* data;
    int length;

public:
    // Constructor to initialize the string with a C-style string
    MyString(const char* str = "") {
        length = strlen(str);
        data = new char[length + 1]; // +1 for the null terminator
        strcpy(data, str);
    }

    // Copy constructor
    MyString(const MyString& other) {
        length = other.length;
        data = new char[length + 1];
        strcpy(data, other.data);
    }

    // Destructor to free allocated memory
    ~MyString() {
        delete[] data;
    }

    // Overload + operator to concatenate two strings
    MyString operator+(const MyString& other) const {
        char* concatenatedData = new char[length + other.length + 1];
        strcpy(concatenatedData, data);
        strcat(concatenatedData, other.data);

        MyString result(concatenatedData);
        delete[] concatenatedData;
        return result;
    }

    // Function to display the string
    void display() const {
        cout << data << endl;
    }
};

int main() {
	char s1[100],s2[100];
	cout<<"\n Enter 1 String : ";
	cin>>s1;
	cout<<"\n Enter 2 String : ";
	cin>>s2;
    MyString str1(s1);
    MyString str2(s2);

    MyString result = str1 + str2;

    cout << "Concatenated String: ";
    result.display();

    return 0;
}

