#include <iostream>
#include <cmath>

using namespace std;

//display program description
void progdescription(){
	
	cout << "--PROGRAMMING EXERCISE 4 TEASER PROBLEM-- \n";
    cout << "-Program to find highest and lowest number among 3 user inputs. Also shows the difference of the two-\n\n";
    cout << "Programmer: Dan Aaron P. Gamad\n";
    cout << "Date submitted: 4/27/24\n";
    cout << "Subject: CMSC 28 K\n\n";
    
}

//read input values
void readdata(int &x, int &y, int &z){
    cout << "Please enter 3 numbers: ";
    cin >> x >> y >> z;
}

//find the highest of 3 numbers
int getlarge(int x, int y, int z){
    return max(x, max(y, z));
}

//find the lowest of 3 numbers
int getsmall(int x, int y, int z){
    return min(x, min(y, z));
}

//display the values
void showdata(int x, int y, int z, int largeval, int smallval, int diff){
    cout << "Numbers entered by user: " << x << ", " << y << ", " << z << endl;
    cout << "Highest number entered is: " << largeval << endl;
    cout << "Lowest number entered is: " << smallval << endl;
    cout << "Difference between the two: " << diff << endl;
}

int main(){
	
    //var declarations
    int x, y, z, smallval, largeval, diff;
    
    //functions used and called
    progdescription();
    readdata(x, y, z);
    smallval = getsmall(x, y, z);
    largeval = getlarge(x, y, z);
    diff = largeval - smallval;
    showdata(x, y, z, largeval, smallval, diff); //prints all data

    return 0;
}

