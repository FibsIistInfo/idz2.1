#include <iostream>
#include<ctime>
#include <cstdlib>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct Grade{
	int Value; // �������� ������
	char* Subject; // �������
	char* Name; // �������������
	int Year; // ���
	int Month; // �����
	int Day; // ����
};

/**
* ���������� ������
*/
void output(Grade* grade);
void input(Grade* grade);


int main(int argc, char** argv) {
	Grade* ptrGrades;
	ptrGrades = new Grade[2];

	// ���� ��������
	// TODO: ������� � ����� ��������������
	input(ptrGrades);
	input(ptrGrades+1);
	
	// ����� ������� ��������
	output(NULL); // �����
	for(int i=0; i<2; i++){
		output(&ptrGrades[i]);
	}
	
	for(int i=0; i<2; i++){
		// ��������� ������ �� ��� ����� Subject � Name
		// TODO: ���������, ����� ����� ���������� ������
		delete ptrGrades[i].Subject;
		delete ptrGrades[i].Name;
	}
	delete ptrGrades;
	
	return 0;
}

/**
* ����������� ������� input
*/
void input(Grade* grade)
{
	// TODO:  ���� ������� ������� ��������������
	// ������ ����� ��� ������� ���������� ������
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
* ����������� ������� output 
*/
void output(Grade* grade)
{
	if(grade == NULL){
		// ������� �����
		printf("|%15s|%8s|%10s|%20s|\n","Subject", "Grade", "Date", "Name"); // ����� ��������� � ������� �������
	}
	else{
		// �������� �������� �� ������ � ����� ���� ���������
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


