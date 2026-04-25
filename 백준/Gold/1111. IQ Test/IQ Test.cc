#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int sequenceLength, sequence[50];

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> sequenceLength;
	for (int i = 0; i < sequenceLength; i++)
		cin >> sequence[i];

	if (sequenceLength == 1){
		cout << "A\n";
		return 0;
	}
	if (sequenceLength == 2){
		if (sequence[0] == sequence[1])
			cout << sequence[1];
		else
			cout << "A\n";
		
		return 0;
	}
	else{
		int coefficientA = 0;
		if (sequence[1] - sequence[0] != 0)
			coefficientA = (sequence[2] - sequence[1]) / (sequence[1] - sequence[0]);

		int coefficientB = sequence[1] - sequence[0] * coefficientA;
		
		for (int i = 1; i < sequenceLength; i++){
			if (sequence[i] != sequence[i - 1] * coefficientA + coefficientB){
				cout << "B\n";
				return 0;
			}
		}
		
		cout << sequence[sequenceLength - 1] * coefficientA + coefficientB;
	}

	return 0;
}
