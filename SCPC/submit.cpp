/*
You should use the standard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful. 
*/

#include <iostream>
#include <vector>

using namespace std;

int Answer;
int dp(vector<int> *v, int idx) {
	if(v->at(idx-1) != 0 || idx == 1) {
		return v->at(idx-1);
	}
	else {
		int t;
		if(idx % 2)
			t = idx + 1;
		else
			t = idx / 2;
		v->at(idx-1) = dp(v, t) + 1;
		return v->at(idx-1);
	}
}

int main(int argc, char** argv)
{
	int T, test_case;
	/*
	   The freopen function below opens input.txt file in read only mode, and afterward,
	   the program will read from input.txt file instead of standard(keyboard) input.
	   To test your program, you may save input data in input.txt file,
	   and use freopen function to read from the file when using cin function.
	   You may remove the comment symbols(//) in the below statement and use it.
	   Use #include<cstdio> or #include <stdio.h> to use the function in your program.
	   But before submission, you must remove the freopen function or rewrite comment symbols(//).
	 */	

	freopen("input.txt", "r", stdin);

	cin >> T;
	int n1, n2;

	vector<int> v(1000001, 0);
	for(test_case = 0; test_case  < T; test_case++)
	{

		Answer = 0;
		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
		   Implement your algorithm here.
		   The answer to the case will be stored in variable Answer.
		 */

	    cin >> n1 >> n2;
	    for(int t = n1; t <= n2; t++) {
		    if(v[t-1] == 0)
			    dp(&v, t);
		    Answer += v[t-1];
	    }
		/////////////////////////////////////////////////////////////////////////////////////////////
		
		// Print the answer to standard output(screen).
		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}
