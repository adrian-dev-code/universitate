#ifndef TEACHER_H
#define TEACHER_H
#include "includes.hpp"

class Teacher
{
public:
	//Constructor and destructor
	Teacher();
	~Teacher();

	//Accesor
	const bool& getIsRunning() const { return this->isRunning; }

	//Functions
	void printMenu();

private:
	//Internal functions
	void chooseOption(const unsigned int&);
	void isRetired() const;
	void smallSalary() const;
	void hasCredits() const;
	void TeacherAc() const;
	void hasLeft() const;

	//DB
	void scanDB();
	
private:
	bool isRunning;
	unsigned int option;
	
	
	std::string* arr;
	std::vector <std::string*> dynMatrix;
};
#endif // !TEACHER_H
