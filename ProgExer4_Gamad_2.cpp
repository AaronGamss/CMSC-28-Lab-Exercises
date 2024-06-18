#include <iostream>
#include <cmath>

using namespace std;

//display program description
void progdescription(){
	
	cout << "--PROGRAMMING EXERCISE 4 BOREDOM RELIEVER PROBLEM-- \n";
    cout << "-Program to convert user input (decimal) into binary-\n\n";
    cout << "Programmer: Dan Aaron P. Gamad\n";
    cout << "Date submitted: 4/27/24\n";
    cout << "Subject: CMSC 28 K\n\n";
    
}

//convert decimal to binary
void decToBinary(int n){
	
    //array def to store binary digits
    int binaryNum[32];
  
    //counter var for bin array
    int i = 0;
    while (n > 0){
        //puts remainder in bin array
        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }
  
    //display array in reverse
    for (int j = i - 1; j >= 0; j--)
        cout << binaryNum[j];
}

int main(){
    int num;
    
	//description
    progdescription();
    
    //program content
    cout << "Enter an integer(decimal) to be converted to binary: ";
    cin >> num;
    cout << "Binary equivalent of user input >>" << num << "<< would be: ";
    decToBinary(num);

    return 0;
}

