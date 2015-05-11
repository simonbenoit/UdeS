// GIF261.cpp : définit le point d"entrée pour l'application console.
//

#include "stdafx.h"
using namespace std;

template <class T>
T findname(T a[], T lastname, T firstname, int max)
{
	int min = 0;
	T param;

	for (int i = 0; i < max; i++)
	{		
		if ((a[i].find(lastname) != string::npos) && (a[i].find(firstname) != string::npos))
		{
			param = a[i];
			break;
		}
	}
	return param;
}


int _tmain()
{
	//Const 
	//Need to be change if input.txt is different, otherwise, it will not work properly
	int max = 18;
	string completeList[18];

	//Variables declaration
	string CMD;
	string filename;
	string request;
	string requesttype;
	string lastname;
	string firstname;
	string str;
	ifstream infile;
	string param;
	int min = 0;
	node* n = new node();
	node* d = new node();
	btree *tree = new btree;
	
	cout << "commandes: c nomDeFichier, l, s requete, e, o, t." << endl;
	while (1)
	{		
		cout << "CMD: ";  
		getline(cin, CMD);
		istringstream iss(CMD);
		vector<string> tokens{ istream_iterator<string>{iss}, istream_iterator<string>{}};

		if (tokens[0] == "t")
		{			
			delete n;
			delete d;
			tree->destroyBtree();
			exit(0);
		}
		else if (tokens[0] == "o")
		{
			cout << "OK" << endl;
		}
		else if (tokens[0] == "l")
		{
			cout << "Not implemented" << endl;
		}
		else if (tokens[0] == "c")
		{					
			filename = tokens[1];

			int i = 0;
			//Read file and outup in array
			infile.open(filename);
			if (!infile)
			{
				cout << "Unable to open file";
				exit(1); // terminate with error
			}
			while (!infile.eof())
			{
				getline(infile, completeList[i], '\n');
				i++;
			}

			int ptr = 0;
			n = tree->buildtree(completeList, ptr, 18);
		}

		else if (tokens[0] == "s")
		{
			requesttype = tokens[1];
			lastname = tokens[2];
			firstname = tokens[3];
			request = requesttype + " " + lastname + " " + firstname + " ";

		}
		else if (tokens[0] == "e")
		{
			if (request != "")
			{
				param = findname(completeList, firstname, lastname, max);

				cout << "Execution: " + request << endl;
				cout << "----------" << endl;

				if (requesttype == "n")
				{	
					mergesort(completeList, min, max - 1);
					string val = bisectionsearch(completeList, min, max, param);
					cout << val << endl;
				}
				else if (requesttype == "d")
				{	
					d = tree->search(param, n);
					tree->preorder(d->left);
					tree->preorder(d->right);
				}
				else
				{
					cout << "No request type found!" << endl;
				}
			}
			else
			{
				cout << "No request found!" << endl;
			}
			
		}
		else
		{
			cout << "Invalid command" << endl;
		}
	}		

	return 0;	
}
