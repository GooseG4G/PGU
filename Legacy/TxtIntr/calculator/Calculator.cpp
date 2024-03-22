#include <iostream>
#include <math.h>
#define PI 3.14159265
using namespace std;


void print_help(){
	cout<<"enter '-r', 'sin' or 'cos', 'radians' " << "to calculate sine or cosine in radians;\n";
	cout<<"enter '-d', 'sin' or 'cos', 'degrees' to calculate sine or cosine in degrees;\n";
}


bool checker(string t, string o){
	bool check = false;
	if (((t == "-r") or (t == "-d")) and ((o == "sin") or (o == "cos")))
		check = true;
	return check;
}


float calc(string t, string o, string m){
	double answer = 0;
	if ((t == "-r") and (o == "sin"))
		answer =  sin(stoi(m));
	if ((t == "-r") and (o == "cos"))
		answer =  cos(stoi(m));
	if ((t == "-d") and (o == "sin"))
		answer =  sin(stoi(m)*PI/180);
	if ((t == "-d") and (o == "cos"))
		answer =  cos(stoi(m)*PI/180);
	return answer;
}


int main(int argc, char* argv[])
{

	if (argc == 4){
		string t = argv[1];
		string o = argv[2];
		string m = argv[3];
		if (checker(t, o) == true){
			try{
				cout << calc(t, o, m);
			}
			catch(std::invalid_argument){
				print_help();
			}
		}
		else
			print_help();
	}
	else
		print_help();
}
