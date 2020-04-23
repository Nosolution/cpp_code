#include <iostream>
#include <fstream>
#include "TradeException.h"

using namespace std;

int main()
{
	int n, m;
	int import_prc[4];
	int export_prc[4];
	import_prc[1] = 10;
	import_prc[2] = 15;
	import_prc[3] = 20;
	export_prc[1] = 12;
	export_prc[2] = 18;
	export_prc[3] = 24;
	
	//ofstream out("F:/Project/CppExercise/exam20/Q96/test.txt", ios::app);

	cin >> n >> m;
	int* commos = new int[n]();
	int size = 0;

	int type, id;
	while (1)
	{
		cin >> type;
		if (type == -1)
			break;
		else
		{
			cin >> id;
		}

		try
		{
			if (type == 1)
			{
				if (size == n)
					throw TradeException("Overflow");
				else if (m < import_prc[id])
					throw TradeException("Can not Afford");
				else
				{
					for (int i = 0; i < n; i++)
					{
						if (commos[i] == 0)
							commos[i] = id;
					}
					m -= import_prc[id];
					size++;
				}
			}
			else if (type == 0)
			{
				if (size == 0)
					throw TradeException("Nothing Left");
				else
				{
					int i = 0;
					for (; i < n; i++)
					{
						if (commos[i] == id)
						{
							commos[i] = 0;
							m += export_prc[id];
							size--;
							break;
						}

					}
					if (i == n)
						throw TradeException("No Such Commodity");
				}
			}

			cout << m << endl;
		}
		catch (TradeException e)
		{
			cout << e.get_msg() << endl;
		}


	}

	//system("pause");
	return 0;

}