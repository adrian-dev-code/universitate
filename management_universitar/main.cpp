#include <iostream>
#include "Teacher.hpp"

int main()
{
	Teacher teacher;
	while (teacher.getIsRunning())
	{
		teacher.printMenu();
	}
	return 0;
}
