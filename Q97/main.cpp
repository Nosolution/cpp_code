#include <iostream>
#include <vector>
#include <fstream>
#include "Element.h"
#include "BaseElement.h"
#include "CompositeElement.h"
#include "IDNotFoundException.h"
#include "AddTagToCommonException.h"

using namespace std;
void split(const string& line, const string token, vector<string>& words);
int isBase(string tag);

int main()
{
	int n;
	cin >> n;
	getchar();
	Element* root = nullptr;
	Element* target;
	string line;
	vector<string> words;
	for (int i = 0; i < n; i++)
	{
		getline(cin, line);
		split(line, " ", words);
		if (words[1].compare("NULL") == 0)
		{
			root = new CompositeElement(words[3], words[2], words[4], words[5], words[6], words[7]);
			continue;
		}
		else
		{
			target = root->find(words[1]);
			if (target == nullptr)
			{
				cout << "IDNotFoundException: ID not found, " + words[1] << endl;
				continue;
			}
			Element* newElement;
			if (isBase(words[2]))
				newElement = new BaseElement(words[3], words[2], words[4], words[5], words[6], words[7]);
			else
				newElement = new CompositeElement(words[3], words[2], words[4], words[5], words[6], words[7]);
			try {
				target->addElement(newElement);
			}
			catch (AddTagToCommonException e)
			{
				//delete newElement;
				//cout << e.report() << endl;
				cout << "AddTagToCommonException: can not add tag to common tag, " + words[3]<<endl;
			}
		}
	}

	cin >> n;
	getchar();
	for (int i = 0; i < n; i++)
	{
		getline(cin, line);
		try {
			target = root->find(line);
			if (target == nullptr)
				throw	IDNotFoundException(line);

			target->output(cout);
		}
		catch (IDNotFoundException e)
		{
			cout << e.report()<<endl;
		}
	}
	//system("pause");
	return 0;

}


void split(const string& line, const string token, vector<string>& words)
{
	words.clear();

	size_t cur, prev = 0;
	cur = line.find(token, prev);
	while (cur != string::npos)
	{
		if (cur > prev)
		{
			words.push_back(line.substr(prev, cur - prev));
		}
		prev = cur + 1;
		if (prev == line.length())
			break;
		cur = line.find(token, prev);
	}

	if (prev != line.length())
	{
		words.push_back(line.substr(prev, line.length() - prev));
	}

}
int isBase(string tag)
{
	return (tag.compare("SButton") == 0) || (tag.compare("SInput") == 0) || (tag.compare("SLabel") == 0) || (tag.compare("SText") == 0);
}