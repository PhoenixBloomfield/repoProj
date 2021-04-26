#include <filesystem>
#include <iostream>
#include <fstream>
#include <sstream>
#include "Repo.hpp"
namespace fs = std::filesystem;
using std::filesystem::exists;
using namespace std;
//compile using "g++ -std=c++17 main.cpp Repo.cpp" and this won't be an issue

int main(int argc, char *argv[])
{
	string inputLine;
	cout << "Create new repository? (y/n)" << endl;
	getline(cin, inputLine);
	if(inputLine == "n") {
		cout << "Goodbye." << endl;
		return -1;
	}
	Repo Rep;
	bool quit = false;
	while (!quit)
	{
		int option;

		cout << "======Main Menu======" << endl;
		cout << "1. Add New File" << endl;
        cout << "2. Remove File" << endl;
        cout << "3. Commit Changes" << endl;
        cout << "4. Checkout Code" << endl;
		cout << "5. Quit" << endl;

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
				if(Rep.currentLatestMismatch()) break;
				do {
					cout << "Valid file name to be added:" << endl;
					getline(cin, inputLine);
				}
				while(!exists(inputLine));
				doublyNode* currentCommit = Rep.getCurrentCommit();
				bool alreadyAdded = false;
				singlyNode* currentNode = currentCommit->head;
				while(currentNode != NULL && alreadyAdded == false) {
					if(currentNode->fileName == inputLine) alreadyAdded = true;
				}
				if(alreadyAdded) {
					cout << "Error: file already added. Cannot add same file twice." << endl;
					break;
				}
				break;
			}
			case 2:
			{
				if(Rep.currentLatestMismatch()) break;
				cout << "Name of file to be removed:" << endl;
				getline(cin, inputLine);
				bool removed = Rep.removeFile(inputLine);
				if(removed) cout << "File successfully removed." << endl;
				else cout << "File could not be removed." << endl;
				break;
				//branch done
			}
	        case 3:
			{
				if(Rep.currentLatestMismatch()) break;
	            break;
			}
            case 4:
			{
	            cout << "Warning: will overwrite current changes in directory." << endl;
				getline(cin, inputLine);

				if (inputLine.length() != 1 || inputLine[0] < '0' || inputLine[1] > '4') 
				{
				cerr << "Invalid option : " << inputLine << endl;
				continue; 
				}
	            break;
			}
            case 5:
			{
				quit = true;
                break;
				//branch done
			}
	}
}

	cout << "Goodbye!" << endl;

	return 0;
}