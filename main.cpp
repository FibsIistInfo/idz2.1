#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct Grade{
	int Value; // значение оценки
	char* Subject; // предмет
	char* Name; // преподаватель
	int Year; // год
	int Month; // месяц
	int Day; // день
};

int main(int argc, char** argv) {
	Grade gradeMath,gradeGraphics;
	Grade* ptrMath;
	Grade* ptrGrades;
	
	gradeMath.Value = 5;
	gradeMath.Subject = "Math";
	gradeMath.Day = 12;
	gradeMath.Month = 1;
	gradeMath.Year = 2018;
	gradeMath.Name = "Kupriyanov";
	
	gradeGraphics.Value = 4;
	gradeGraphics.Subject = "Graphics";
	gradeGraphics.Day = 20;
	gradeGraphics.Month = 1;
	gradeGraphics.Year = 2018;
	gradeGraphics.Name = "Belyaev";
	
	

	// вывод двух струткутр на экран
	//printf("|Subject        |Grade   |Date      |Name                |\n"); // header
	printf("|%15s|%8s|%10s|%20s|\n","Subject", "Grade", "Date", "Name"); // вывод заголовка с помощью шаблона

	printf("|%15s|%8d|%02d.%02d.%4d|%20s|\n",
		gradeMath.Subject, 
		gradeMath.Value, 
		gradeMath.Day, 
		gradeMath.Month, 
		gradeMath.Year, 
		gradeMath.Name
	);
	printf("|%15s|%8d|%02d.%02d.%4d|%20s|\n",
		gradeGraphics.Subject, 
		gradeGraphics.Value, 
		gradeGraphics.Day, 
		gradeGraphics.Month, 
		gradeGraphics.Year, 
		gradeGraphics.Name
	);
	
	ptrMath = &gradeMath; // берем адрес переменной gradeMath
	ptrMath->Value = 4; // меняем значение по указателю
	// снова выводим переменную
	printf("|%15s|%8d|%02d.%02d.%4d|%20s|\n",
		gradeMath.Subject, 
		gradeMath.Value, 
		gradeMath.Day, 
		gradeMath.Month, 
		gradeMath.Year, 
		gradeMath.Name
	);
	
	ptrGrades = new Grade[5];
	
	
	delete ptrGrades;
	
	return 0;
}
