#include "includes.hpp"
#include "Teacher.hpp"

Teacher::Teacher() : isRunning(true), option(0), arr(nullptr) {};

Teacher::~Teacher()
{
	delete [] arr;
}

void Teacher::TeacherAc() const
{
	remove("automatica.txt");
	bool ok = false;
	std::ofstream fout("automatica.txt");
	for (int i = 0; i < this->dynMatrix.size(); i++)
	{
		if (std::stoi(this->dynMatrix[i][AC]) == 1)
		{
			fout << this->dynMatrix[i][FN] << " " << this->dynMatrix[i][LN] << " preda la automatica si calculatoare." << "\n";
			ok = true;
		}
	}
	if (ok)
	{
		std::cout << "Lista cu cadre didactice de la automatica si calculatoare fost actualizata cu succes \n";
	}
	else
	{
		std::cout << "Nu exista profesori care predau la automatica si caluclatoare \n";
	}
}

void Teacher::hasLeft() const
{
	remove("hasLeft.txt");
	bool ok = false;
	std::ofstream fout("hasLeft.txt");
	for (int i = 0; i < this->dynMatrix.size(); i++)
	{
		if (std::stoi(this->dynMatrix[i][HAS_LEFT]) !=0)
		{
			fout << this->dynMatrix[i][FN] << " " << this->dynMatrix[i][LN] << " a parasit universitatea acum " << this->dynMatrix[i][HAS_LEFT] <<" (de)ani" << "\n";
			ok = true;
		}
	}
	if (ok)
	{
		std::cout << "Lista cu cadre didactice ce au parasit universitatea a fost actualizata cu succes!\n";
	}
	else
	{
		std::cout << "Nu cadre didactice ce au parasit universitatea \n";
	}
}

void Teacher::smallSalary() const
{
	remove("smallSalary.txt");
	bool ok = false;
	std::ofstream fout("smallSalary.txt");
	for (int i = 0; i < this->dynMatrix.size(); i++)
	{
		if (std::stoi(this->dynMatrix[i][SALARY]) < SALARY_RANGE)
		{
			fout << this->dynMatrix[i][FN] <<" " << this->dynMatrix[i][LN] <<" " <<dynMatrix[i][SALARY]<<"\n";
			ok = true;
		}
	}
	if (ok)
	{
		std::cout << "Lista cu persoane cu salariu sub 4000 RON a fost actualizata cu succes \n";
	}
	else
	{
		std::cout << "Nu exista persoane cu salariu sub 4000 RON \n";
	}
}

void Teacher::hasCredits() const
{
	remove("credit.txt");
	bool ok = false;
	std::ofstream fout("credit.txt");
	for (int i = 0; i < this->dynMatrix.size(); i++)
	{
		if ((this->dynMatrix[i][CREDITS]) == "1")
		{
			fout << this->dynMatrix[i][FN] << " " << this->dynMatrix[i][LN] <<" " <<this->dynMatrix[i][RATE] <<" RON RATE" <<"\n";
			ok = true;
		}
	}
	if (ok)
	{
		std::cout << "Lista cu persoane cu credite s-a acutalizat cu succes \n";
	}
	else
	{
		std::cout << "Nu exista persoane cu salariu mai mic decat 4000 RON \n";
	}
}

void Teacher::isRetired() const
{
	remove("retired.txt");
	bool ok = false;
	std::ofstream fout("retired.txt");
	for (int i = 0; i < this->dynMatrix.size(); i++)
	{
		if (std::stoi(this->dynMatrix[i][AGE]) >= (int)RETIREMENT_AGE_F
			&& this->dynMatrix[i][SEX] == "f")
		{
			fout << this->dynMatrix[i][FN] << " " << this->dynMatrix[i][LN] << "\n";
			ok = true;
		}
		if (std::stoi(this->dynMatrix[i][AGE]) >= (int) RETIREMENT_AGE_M
			&& this->dynMatrix[i][SEX] == "m")
		{
			fout << this->dynMatrix[i][FN] << " " << this->dynMatrix[i][LN] << "\n";
			ok = true;
		}
	}
	if (ok)
	{
		std::cout << "Lista cu pensionari a fost actualizata cu succes \n";
	}
	else
	{
		std::cout << "Nu exista pensionari sau persoane in curs de pensionare \n";
	}
}

void Teacher::scanDB()
{
	std::ifstream fin("employee.txt");
	std::string x;
	unsigned int count = 0;
	unsigned int i = 0;
	this->arr = new std::string[COLUMNO];

	while (fin >> x)
	{
		if (count >= COLUMNO)
		{
			arr[i] = x;

			if (i == COLUMNO - 1)
			{
				this->dynMatrix.push_back(arr);
				this->arr = new std::string[COLUMNO];
				i = -1; // Indexul o sa fie de fapt 0, ca face i++ la final
			}

			i++;
		}
		count++;
	}
}

void Teacher::chooseOption(const unsigned int& option)
{
	switch (this->option)
	{
	case 1:
		smallSalary();
		break;
	case 2:
		isRetired();
		break;
	case 3:
		hasCredits();
		break;
	case 4:
		TeacherAc();
		break;
	case 5:
		hasLeft();
		break;
	case 6:
		this->isRunning = false;
		break;
	default:
		break;
	}
}

void Teacher::printMenu()
{
	std::cout << "\n==MAIN MENU==" << "\n";
	std::cout << std::setw(80) << std::setfill('=') << "\n";
	std::cout << "1:Tabel cu salariatii ce au un salariu mai mic decat 4000 lei \n";
	std::cout << "2:Tabel cu persoanele ce au implinit varsta de pensionare sau au depasit-o \n";
	std::cout << "3:Tabel cu persoanele ce au de achitat rate lunare si suma totala \n";
	std::cout << "4:Tabel cu cadrele didactice de la facultatea de automatica-calculatoare \n";
	std::cout << "5:Tabel cu persoanele ce au plecat de la universitate in ultimii 5 ani.  \n";
	std::cout << "6:Iesire \n";
	std::cout << std::setw(80) << std::setfill('=') << "\n";
	scanDB();
	std::cin >> this->option;
	chooseOption(this->option);
}
