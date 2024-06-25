

#include<iostream>
#include<string> 
#include <cstdlib>
#include <ctime>

using namespace std;

void Button(){

	cout<<"User page"<<endl;
}

void dispalyUserPage(){

	string UserName;
	int progress = 0; 
	const int maxProgress = 100; 

	cout<<"Welcome to the user page"<<endl;
	cout<<"Please Enter your name";

	getline(cin,UserName);

	cout<<"Hello"<<UserName<<endl;

	while (progress <maxProgress){
		progress+= rand()% 10 + 1;
		if (progress > maxProgress) progress = maxProgress;

		cout<<"progress: [";
		int barWidth = 50;
		int pos = barWidth * progress/maxProgress;

		for (int i = 0; i < barWidth; ++i ){
			if (i<pos) cout<<"=";
			else if (i==pos) cout << ">"<<endl;
		}
			for (int delay = 0; delay<10000000; ++delay);
		}
		cout<<"Progress competed"<<endl;
	}
int main(){

	srand(static_cast<unsigned int> (time(nullptr)));

	Button();
	dispalyUserPage();

	return 0;
}