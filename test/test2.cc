#include <iostream>
#include <climits>
#include <vector>

using namespace std;

// 0: A    1: B    2: C
int choose(vector<int> time_left, vector<int> oil, int car, int& min_time){
	int res = -1;
	for(int i = 0; i < time_left.size(); i++){
		if(car <= oil[i] && time_left[i] < min_time){
			min_time = time_left[i];
			res = i;
		}
	}
	return res;
}

void update(int car, int min_time, int& oil_A, int& time_A, int& time_B, int& time_C){
	oil_A -= car;
	time_A = car;
	time_B = max(0, time_B-min_time);
	time_C = max(0, time_C-min_time);
}

int main(){
	int A = 6;
	int B = 2;
	int C = 5;
	vector<int> queue = {5, 3, 2, 2, 1};

	vector<int> time_left(3,0);
	vector<int> oil = {A, B, C};
	int station;
	int wait = 0;

	for(int i = 0; i < queue.size(); i++){
		int car = queue[i];
		int	min_time = INT_MAX;
		station = choose(time_left, oil, car, min_time);
		switch(station){
			case -1: 
				cout << "Stuck!" << endl;
				return 0;
			case 0:
				update(car, min_time, oil[0], time_left[0],time_left[1],time_left[2]);
				cout << "The car goes to A station" << endl;
				break;
			case 1:
				update(car, min_time, oil[1], time_left[1],time_left[0],time_left[2]);
				cout << "The car goes to B station" << endl;
				break;
			case 2:
				update(car, min_time, oil[2], time_left[2],time_left[1],time_left[0]);
				cout << "The car goes to C station" << endl;
				break;
		}
		wait += min_time;
	}
	cout << wait << endl;
	return 0; 

}