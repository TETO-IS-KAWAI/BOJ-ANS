#include <iostream>
#include <algorithm>

using namespace std;


char up[9];
char down[9];
char front[9];
char back[9];
char left_my[9];
char right_my[9];

char ans[100][9];

void rotate_surface(char sur, char dir) {
	char temp[9];

	if (sur == 'U') {
		copy(up, up + 9, temp);

		if (dir == '+') {
			up[0] = temp[6];
			up[1] = temp[3];
			up[2] = temp[0];
			up[3] = temp[7];
			up[4] = temp[4];
			up[5] = temp[1];
			up[6] = temp[8];
			up[7] = temp[5];
			up[8] = temp[2];
		}

		else {
			up[0] = temp[2];
			up[1] = temp[5];
			up[2] = temp[8];
			up[3] = temp[1];
			up[4] = temp[4];
			up[5] = temp[7];
			up[6] = temp[0];
			up[7] = temp[3];
			up[8] = temp[6];
		}
	}

	else if (sur == 'D') {
		copy(down, down + 9, temp);

		if (dir == '+') {
			down[0] = temp[6];
			down[1] = temp[3];
			down[2] = temp[0];
			down[3] = temp[7];
			down[4] = temp[4];
			down[5] = temp[1];
			down[6] = temp[8];
			down[7] = temp[5];
			down[8] = temp[2];
		}

		else {
			down[0] = temp[2];
			down[1] = temp[5];
			down[2] = temp[8];
			down[3] = temp[1];
			down[4] = temp[4];
			down[5] = temp[7];
			down[6] = temp[0];
			down[7] = temp[3];
			down[8] = temp[6];
		}
	}

	else if (sur == 'F') {
		copy(front, front + 9, temp);

		if (dir == '+') {
			front[0] = temp[6];
			front[1] = temp[3];
			front[2] = temp[0];
			front[3] = temp[7];
			front[4] = temp[4];
			front[5] = temp[1];
			front[6] = temp[8];
			front[7] = temp[5];
			front[8] = temp[2];
		}

		else {
			front[0] = temp[2];
			front[1] = temp[5];
			front[2] = temp[8];
			front[3] = temp[1];
			front[4] = temp[4];
			front[5] = temp[7];
			front[6] = temp[0];
			front[7] = temp[3];
			front[8] = temp[6];
		}
	}

	else if (sur == 'B') {
		copy(back, back + 9, temp);

		if (dir == '+') {
			back[0] = temp[6];
			back[1] = temp[3];
			back[2] = temp[0];
			back[3] = temp[7];
			back[4] = temp[4];
			back[5] = temp[1];
			back[6] = temp[8];
			back[7] = temp[5];
			back[8] = temp[2];
		}

		else {
			back[0] = temp[2];
			back[1] = temp[5];
			back[2] = temp[8];
			back[3] = temp[1];
			back[4] = temp[4];
			back[5] = temp[7];
			back[6] = temp[0];
			back[7] = temp[3];
			back[8] = temp[6];
		}
	}

	else if (sur == 'L') {
		copy(left_my, left_my + 9, temp);

		if (dir == '+') {
			left_my[0] = temp[6];
			left_my[1] = temp[3];
			left_my[2] = temp[0];
			left_my[3] = temp[7];
			left_my[4] = temp[4];
			left_my[5] = temp[1];
			left_my[6] = temp[8];
			left_my[7] = temp[5];
			left_my[8] = temp[2];
		}

		else {
			left_my[0] = temp[2];
			left_my[1] = temp[5];
			left_my[2] = temp[8];
			left_my[3] = temp[1];
			left_my[4] = temp[4];
			left_my[5] = temp[7];
			left_my[6] = temp[0];
			left_my[7] = temp[3];
			left_my[8] = temp[6];
		}
	}

	else /* if (sur == 'R') */ {
		copy(right_my, right_my + 9, temp);

		if (dir == '+') {
			right_my[0] = temp[6];
			right_my[1] = temp[3];
			right_my[2] = temp[0];
			right_my[3] = temp[7];
			right_my[4] = temp[4];
			right_my[5] = temp[1];
			right_my[6] = temp[8];
			right_my[7] = temp[5];
			right_my[8] = temp[2];
		}

		else {
			right_my[0] = temp[2];
			right_my[1] = temp[5];
			right_my[2] = temp[8];
			right_my[3] = temp[1];
			right_my[4] = temp[4];
			right_my[5] = temp[7];
			right_my[6] = temp[0];
			right_my[7] = temp[3];
			right_my[8] = temp[6];
		}
	}



}

void rotate_up() {
	char t_1, t_2, t_3;

	t_1 = right_my[0];
	t_2 = right_my[1];
	t_3 = right_my[2];
	right_my[0] = back[0];
	right_my[1] = back[1];
	right_my[2] = back[2];

	back[0] = left_my[0];
	back[1] = left_my[1];
	back[2] = left_my[2];

	left_my[0] = front[0];
	left_my[1] = front[1];
	left_my[2] = front[2];

	front[0] = t_1;
	front[1] = t_2;
	front[2] = t_3;
}


void rotate_down() {
	char t_1, t_2, t_3;
	t_1 = right_my[6];
	t_2 = right_my[7];
	t_3 = right_my[8];

	right_my[6] = front[6];
	right_my[7] = front[7];
	right_my[8] = front[8];

	front[6] = left_my[6];
	front[7] = left_my[7];
	front[8] = left_my[8];

	left_my[6] = back[6];
	left_my[7] = back[7];
	left_my[8] = back[8];

	back[6] = t_1;
	back[7] = t_2;
	back[8] = t_3;
}


void rotate_front() {
	char t_1, t_2, t_3;

	t_1 = right_my[0];
	t_2 = right_my[3];
	t_3 = right_my[6];

	right_my[0] = up[6];
	right_my[3] = up[7];
	right_my[6] = up[8];

	up[6] = left_my[8];
	up[7] = left_my[5];
	up[8] = left_my[2];

	left_my[2] = down[8];
	left_my[5] = down[7];
	left_my[8] = down[6];

	down[6] = t_1;
	down[7] = t_2;
	down[8] = t_3;
}


void rotate_back() {
	char t_1, t_2, t_3;

	t_1 = right_my[2];
	t_2 = right_my[5];
	t_3 = right_my[8];

	right_my[2] = down[0];
	right_my[5] = down[1];
	right_my[8] = down[2];

	down[0] = left_my[6];
	down[1] = left_my[3];
	down[2] = left_my[0];

	left_my[0] = up[2];
	left_my[3] = up[1];
	left_my[6] = up[0];

	up[0] = t_1;
	up[1] = t_2;
	up[2] = t_3;
}


void rotate_left() {
	char t_1, t_2, t_3;

	t_1 = front[0];
	t_2 = front[3];
	t_3 = front[6];

	front[0] = up[0];
	front[3] = up[3];
	front[6] = up[6];

	up[0] = back[8];
	up[3] = back[5];
	up[6] = back[2];

	back[2] = down[2];
	back[5] = down[5];
	back[8] = down[8];

	down[2] = t_3;
	down[5] = t_2;
	down[8] = t_1;
}


void rotate_right() {
	char t_1, t_2, t_3;

	t_1 = front[2];
	t_2 = front[5];
	t_3 = front[8];

	front[2] = down[6];
	front[5] = down[3];
	front[8] = down[0];

	down[0] = back[0];
	down[3] = back[3];
	down[6] = back[6];

	back[0] = up[8];
	back[3] = up[5];
	back[6] = up[2];

	up[2] = t_1;
	up[5] = t_2;
	up[8] = t_3;
}


void rotate(char sur, char dir) {

	char t_1, t_2, t_3;

	// rotate chosen surface as well
	rotate_surface(sur, dir);

	if (sur == 'U') {
		if (dir == '+') {
			rotate_up();
		}

		else {
			rotate_up();
			rotate_up();
			rotate_up();

		}
	}

	else if (sur == 'D') {
		if (dir == '+') {
			rotate_down();
		}
		else {
			rotate_down();
			rotate_down();
			rotate_down();
		}
	}

	else if (sur == 'F') {
		if (dir == '+') {
			rotate_front();
		}
		else {
			rotate_front();
			rotate_front();
			rotate_front();
		}
	}

	else if (sur == 'B') {
		if (dir == '+') {
			rotate_back();
		}
		else {
			rotate_back();
			rotate_back();
			rotate_back();
		}
	}

	else if (sur == 'L') {
		if (dir == '+') {
			rotate_left();
		}
		else {
			rotate_left();
			rotate_left();
			rotate_left();
		}
	}

	else /* if (sur == 'R') */ {
		if (dir == '+') {
			rotate_right();
		}
		else {
			rotate_right();
			rotate_right();
			rotate_right();
		}
	}

}


int main() {

	int N;
	int rolls;
	char inst[3];

	cin >> N;

	for (int test_case = 0; test_case < N; test_case++) {


		fill(up, up + 9, 'w');
		fill(down, down + 9, 'y');
		fill(front, front + 9, 'r');
		fill(back, back + 9, 'o');
		fill(left_my, left_my + 9, 'g');
		fill(right_my, right_my + 9, 'b');

		cin >> rolls;


		for (int roll = 0; roll < rolls; roll++) {
			cin >> inst;
			rotate(inst[0], inst[1]);
		}

		for (int i = 0; i < 9; i++) {
			ans[test_case][i] = up[i];
		}

	}

	// print "UP" surface
	for (int k = 0; k < N; k++) {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				cout << ans[k][i * 3 + j];
			}
			cout << endl;
		}
	}

}