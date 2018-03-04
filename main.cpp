#include <iostream>
#include<ctime>
#include <cstdlib>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct Grade{
	int Value; // значение оценки
	char* Subject; // предмет
	char* Name; // преподаватель
	int Year; // год
	int Month; // мес€ц
	int Day; // день
};

/**
* объ€влени€ фкнций
*/
void output(Grade* grade);
void input(Grade* grade);


int main(int argc, char** argv) {
	Grade* ptrGrades;
	ptrGrades = new Grade[2];

	// ввод струкутр
	// TODO: сделать в цикле самосто€тельно
	input(ptrGrades);
	input(ptrGrades+1);
	
	// вывод массива структур
	output(NULL); // шапка
	for(int i=0; i<2; i++){
		output(&ptrGrades[i]);
	}
	
	for(int i=0; i<2; i++){
		// освободим пам€ть из под полей Subject и Name
		// TODO: объ€снить, зачем нужно освободить пам€ть
		delete ptrGrades[i].Subject;
		delete ptrGrades[i].Name;
	}
	delete ptrGrades;
	
	return 0;
}

/**
* определение функции input
*/
void input(Grade* grade)
{
	// TODO:  ввод следует сделать самосто€тельно
	// вместо ввода дл€ примера сгенерирую данные
	time_t temp = time(NULL);
	srand(temp+rand());

	grade->Day = 1 + rand() % 31;
	grade->Month = 1 + rand() % 12;
	grade->Year = 2015 + rand() % 4;
	grade->Value = 3 + rand() % 3;
	char* subject = new char[15];
	sprintf(subject, "Test %d",1 + rand() % 50);
	grade->Subject = subject;
	char* name = new char[20];
	sprintf(name, "Prepod %d", 1 + rand() % 50);
	grade->Name = name;

}

/**
* определение функции output 
*/
void output(Grade* grade)
{
	if(grade == NULL){
		// выводим шапку
		printf("|%15s|%8s|%10s|%20s|\n","Subject", "Grade", "Date", "Name"); // вывод заголовка с помощью шаблона
	}
	else{
		// обращаем внимание на доступ к пол€м черз указатель
		printf("|%15s|%8d|%02d.%02d.%4d|%20s|\n",
			grade->Subject,  
			grade->Value, 
			grade->Day, 
			grade->Month, 
			grade->Year, 
			grade->Name
		);
	}
}


