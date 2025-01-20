#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;

string city[10];
int counter = 0;
int hang = 0;
int limit = 8;
int x = 0;


class HangMan
{
private:

	string name[10];
	string key;
	string target;
	int lives = 8;
	
public:
	HangMan()
	{
		name[0] = "India";
		name[1] = "Hydrabad";
		name[2] = "Panipat";
		name[3] = "Karnal";
		name[4] = "Chitkara";
		name[5] = "University";
		name[6] = "Delhi";
		name[7] = "Ambala";
		name[8] = "Chnadigardh";
		name[9] = "Haryana";
	}

	void start()
	{
		bool end = false;  
		bool win = false;

		

		system("CLS");
		selectCity(); 

		while (!end)
		{
			cout << "Lives: " << lives << "\t\tTries: ";
			
			for (int i = 0; i < findLength(target); i++)
				cout << target[i] << ' ';
			cout << endl;

			selectCharacter();

			if (lives <= 0)
				end = true;
			else if (key == target)
			{
				end = true;
				win = true;
			}
		}

		if (win)
			cout << "You Win\n\n";
		else
			cout << "You Loose\n\n";

		cout << "Target was: " << key << endl << endl;
	}

	void selectCity()
	{
		int x = 10;
		while (x < 0 || x > 9)
		{
			cout << "Please select between 0 to 9: ";
			cin >> x;
		}
		key = name[x];  
		target = key;

		for (int i = 0; i < findLength(target); i++) 
		{
			target[i] = '_';
		}
	}

	void selectCharacter()
	{
		char input;
		cout << "Enter a character: ";
		cin >> input;
		
		if (strContains(key, input))
		{
			strCopyChr(key, target, input);
		}
		else
		{
			lives--;
			display_hangingman(); 
		}
		
	}

	bool strContains(string s, char c)  
	{
		for (int i = 0; i < findLength(s); i++)
		{
			if (s[i] == c)
				return true;
		}
		return false;
	}

	void strCopyChr(string source, string &target, char c)  
	{
		for (int i = 0; i < findLength(source); i++)
		{
			if (source[i] == c)
			{
				target[i] = c;
			}
		}
	}

	int findLength(string s)  
		{
		int count = 0;
		for (int i = 0; s[i] != '\0'; i++)
		{
			count++;
		}
		return count;
	}

	void display_hangingman()
	{
		
		if (lives == 7)
		{
		cout<< "				" << "@-@" << endl;
		}
		else if (lives == 6)
		{
		cout << "				" << "@-@" << endl;
		cout << "				" << "  |" << endl;
		}
		else if (lives == 5)
		{
		cout<<"				" << "@-@" << endl;
		cout<<"				" << "  |" << endl;
		cout<<"				" << "(*_*)" << endl;
		}

		else if (lives == 4)
		{
		cout<<"				" << "@-@" << endl;
		cout<<"				" << "  |" << endl;
		cout<<"				" << "(*_*)" << endl;
		cout<<"				" << "  | " << endl;
		}

		else if (lives == 3)
		{
		cout<<"				" << "@-@" << endl;
		cout<<"				" << "  |" << endl;
		cout<<"				" << "(*_*)" << endl;
		cout<<"				" << "  |  " << endl;
		cout<<"				" << "'-|  " << endl;
		}
		else if (lives == 2)
		{
		cout<<"				" << "@-@" << endl;
		cout<<"				" << "  |" << endl;
		cout<<"				" << "(*_*)" << endl;
		cout<<"				" << "  |  " << endl;
		cout<<"				" << "'-|-'" << endl;
		}
		else if (lives == 1)
		{
		cout<<"				" << "@-@" << endl;
		cout<<"				" << "  |" << endl;
		cout<<"				" << "(*_*)" << endl;
		cout<<"				" << "  | " << endl;
		cout<<"				" << "'-|-' " << endl;
		cout<<"				" << "  | " << endl;
		cout<<"				" << "__| " << endl;
		}
		else if (lives == 0)
		{
			cout<<"				" << "@-@" << endl;
			cout<<"				" << "  |" << endl;
			cout<<"				" << "(*_*)" << endl;
			cout<<"				" << "  | " << endl;
			cout<<"				" << "'-|-'" << endl;
			cout<<"				" << "  |  " << endl;
			cout<<"				" << "__|__" << endl;
		}
		
	}
};
