#include <iostream>
#include <cmath>

const int MAX_SIZE = 10;

//input integers to the array
void input(int num[], int& size){
	
    std::cout << "Please enter numbers (enter 0 to signify stop):" << std::endl;
    
    for (size = 0; size < MAX_SIZE; ++size){
        std::cout << "Input any integer: ";
        std::cin >> num[size];
        if (!num[size])
            break;
    }
}

//function for max val in array
int max(const int num[], int size){
	
    int m = num[0];
    
    for (int i = 1; i < size; ++i){
        if (num[i] > m)
            m = num[i];
    }
    return m;
}

//funtion for min val in array
int min(const int num[], int size){
	
    int m = num[0];
    
    for (int i = 1; i < size; ++i){
        if (num[i] < m)
            m = num[i];
    }
    return m;
}

//function to calculate average
double avg(const int num[], int size){
	
    int sum = 0;
    
    for (int i = 0; i < size; ++i){
        sum += num[i];
    }
    
    return static_cast<double>(sum) / size;
}

//function to calculate variance
double var(const int num[], int size, double avg){
	
    double v = 0;
    
    for (int i = 0; i < size; ++i){
        v += pow(num[i] - avg, 2);
    }
    
    return v / size;
}

//function to calculate standard dev
double stddev(double var){
    return sqrt(var);
}

//displaying infomation or statistics
void stats(int largest, int smallest, double average, double stdev, double variance){
	std::cout << "\nSTATISTICS:";
    std::cout << "\nLargest = " << largest << std::endl;
    std::cout << "Smallest = " << smallest << std::endl;
    std::cout << "Average = " << average << std::endl;
    std::cout << "Standard deviation = " << stdev << std::endl;
    std::cout << "Variance = " << variance << std::endl;
}

int main(){
	
    int num[MAX_SIZE];
    int size;
    double average, variance, stdev;
	
	//input phase
    input(num, size);

	//pops up when no data entered
    if (!size){
        std::cout << "No data entered!" << std::endl;
        return 1;
    }
	
	//calculations start 
    int largest = max(num, size);
    int smallest = min(num, size);
    average = avg(num, size);
    variance = var(num, size, average);
    stdev = stddev(variance);

	//display results
    stats(largest, smallest, average, stdev, variance);

    return 0;
}

