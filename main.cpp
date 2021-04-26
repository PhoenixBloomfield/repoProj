#include <filesystem>
#include <iostream>
#include <fstream>
#include <sstream>
#include "Repo.hpp"
namespace fs = std::filesystem;
//compile using "g++ -std=c++17 main.cpp Repo.cpp" and this won't be an issue

int main(int argc, char *argv[])
{

	bool quit = false;
	while (!quit)
	{
		int option;
		string inputLine;

		cout << "======Main Menu======" << endl;
		cout << "1. Initialize" << endl;
		cout << "2. Add New File" << endl;
        cout << "3. Remove File" << endl;
        cout << "4. Commit Changes" << endl;
        cout << "5. Checkout Code" << endl;
		cout << "4. Quit" << endl;

		getline(cin, inputLine);

		if (inputLine.length() != 1 || inputLine[0] < '0' || inputLine[1] > '4') {
			cerr << "Invalid option : " << inputLine << endl;
			continue;
		}

		option = stoi(inputLine);

		switch (option)
		{

			case 1:
			{
				
				Repo inputString;
				//call constructor
				break;
			}
			case 2:
			{
                
				break;
			}
	        case 3:
			{
	            break;
			}
            case 4:
			{
	            break;
			}
            case 5:
			{
                cout << "Warning: will overwrite current changes in directory." << endl;
	            break;
			}
			case 6:
			{

				quit = true;
                break;
			}
	}
}

	cout << "Goodbye!" << endl;

	return 0;
}