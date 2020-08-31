#include "Dictionary.h"
#include "DrawMenu.h"
#include <ctime>




int main()
{

	clock_t start;
	//start = clock();
	
	double t;
	DictionaryInterface Dict;

	//Oxford English Dictionary.txt
	
	Dict.ReadFile("Oxford English Dictionary.txt");
	//start = clock();
	//Dict.Search("a-");
	//Dict.Save();
	//t = (double)(clock() - start);
	//cout << "Time: ";
	//printf("%-20.6lf\n", t);

	
	
	RunDictionary(Dict);




	return 0;
}
