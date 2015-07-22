#include<iostream>
#include<vector>
using namespace std;
#define MAX 23456789
#define MIN 12
#define INVALID 0
//no #defines

class Odometer {
	public:
		//make private
		bool isValid(unsigned long long int reading) {
			short int currentDigit, previousDigit;
			if(reading > MAX || reading < MIN)
				return false; 
			while(reading > 0) {
				currentDigit = reading % 10;
				reading /= 10;
				previousDigit = reading % 10;			
				if(previousDigit >= currentDigit) {
					return false;
				}
			}
			return true;
		}
		unsigned long long int nextReading(unsigned long long int reading) {
			while(!isValid(++reading));
			return reading;
		}
		
		unsigned long long int previousReading(unsigned long long int reading) {
			while(!isValid(--reading));
			return reading;
		}
		
		
		unsigned long long int differenceInReadings(unsigned long long int reading1, unsigned long long int reading2) {
			unsigned long long int start; 
			unsigned long long int stop;
			unsigned long long int counter = 0;
			if(isValid(reading1) && isValid(reading2)) {
				start = reading1 < reading2 ? reading1 : reading2;
				stop = reading1 < reading2 ? reading2 : reading1;
				while(start != stop) {
					if(isValid(++start))
						counter++;
				}
				return counter;
			}
			return INVALID;
		}
};

int main() {
	Odometer odometer;
	cout << odometer.nextReading(2345678) << "\n";
	cout << odometer.previousReading(2345678) << "\n";
	cout << odometer.differenceInReadings(12345, 23456789);
	return 0;
}
