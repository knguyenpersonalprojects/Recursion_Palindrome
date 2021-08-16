#include <iostream>
#include <vector>
#include<string>
using namespace std;

//check if the number is a palidrone using simple recursion 
int palidrone(string& num, vector<char> &palid_arr)
{
	//converts string to an interger
	int temp = stoi(num);
	if (temp < 1)
	{
		return 0;

	}
	else
	{
		//push the back most element into the vector of num
		//what we get is a vector of elements from end to begining 
		palid_arr.push_back('0' + (temp % 10));
		temp /= 10;
		num = to_string(temp);
		palidrone(num, palid_arr);
	}
}
bool isPalidrone(vector<char>orig_arr, vector<char>palidrone,int size)
{
	bool isitPalidrone = false;
	for (int i = 0; i < size; i++)
	{
		if (orig_arr[i] == palidrone[i])
		{
			isitPalidrone = true;
		}
		else
			isitPalidrone = false;

	}
	return isitPalidrone;
}

int main()
{
	
	string user_num;
	vector<char> palidrone_arr;
	vector<char> original_arr;
	int size;
	bool isitPalidrone;
	cout << "Please enter a number " << endl;
	cin >> user_num;
	cout << "The user input number is " << user_num << endl;
	//finds the number of characters in the string
	size = user_num.length();

	for (int i = 0; i < size; i++)
	{
		original_arr.push_back(user_num[i]);
	}

	palidrone(user_num, palidrone_arr);
	
	isitPalidrone = isPalidrone(original_arr, palidrone_arr,size);
	if (isitPalidrone == true)
	{
		cout << "This number is a palidrone " << endl;
	}
	else
	{
		cout << "This number is not a palidrone " << endl;
	}

	system("PAUSE");

}