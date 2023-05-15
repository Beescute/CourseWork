#pragma once
#include <windows.h>
#include <iostream>
#include <string>
#include <stdio.h>
#include <fstream>
#include <time.h>
#include "ClassMenu.h"
#include "ClassStudent.h"
#include "ClassExams.h"
using namespace std;

void crypt() {
	srand(time(NULL));
	const int SIZE = 64;
	char* pass = new char[SIZE];
	for (int i = 0; i < SIZE; i++){
		switch(rand() % 3) {
		case 0 :
			pass[i] = rand() % 10 + '0';
			break;
		case 1:
			pass[i] = rand() % 26 + 'A';
			break;
		case 2:
			pass[i] = rand() % 26 + 'a';
		}
	}
	pass[63] = '\0';

	string command = "openssl\\bin\\openssl.exe enc -aes-256-cbc -salt -in file.bin -out file.bin.enc -pass pass:";
	command += pass;
	system(command.c_str());

	if (remove("dbFile.txt") != 0) {
		cout << "[ERROR] - deleting file" << endl;
	}

	ofstream file;
	file.open("key.txt", ios::binary);
	file.write(pass, 65);
	file.close();

	command = "openssl\\bin\\openssl.exe rsautl -encrypt -inkey rsa.public -pubin -in key.txt -out key.txt.enc";
	system(command.c_str());

	if (remove("key.txt") != 0) {
		cout << "[ERROR] - deleting file" << endl;
	}
}

void decrypt() {
	string command = "openssl\\bin\\openssl.exe rsautl -decrypt -inkey rsa.private -in key.txt.enc -out key.txt";
	system(command.c_str());

	if (remove("key.txt.enc") != 0) {
		cout << "[ERROR] - deleting file" << endl;
	}

	char* pass = new char[64];
	ifstream file;
	file.open("key.txt", ios::binary);
	file.read(pass, 65);
	file.close();

	if (remove("key.txt") != 0) {
		cout << "[ERROR] - deleting file" << endl;
	}
	
	command = "openssl\\bin\\openssl.exe enc -aes-256-cbc -d -in file.bin.enc -out file.bin -pass pass:";
	command += pass;
	system(command.c_str());


	if (remove("dbFile.txt.enc") != 0) {
		cout << "[ERROR] - deleting file" << endl;
	}

}
void WRITE(FILE* file) {
	fopen_s(&file, "dbFile.txt", "w");
	char firstWord[30] = "Студент номер";
	char specialSymb[40] = "---------------------------------------";
	ClassList <ClassStudent> tempStudents;
	//1
	ClassStudent Dany("Даниил", "Атавин", "Антонович", 07, 02, 2005, 2022, "ИКБ", "КБ-02", "БИСО-01-22", "22Б8660", 1);
	Dany.fillExam(0, "Физика", 5); Dany.fillExam(0, "История", 5); Dany.fillExam(0, "Линейная алгебра", 5); Dany.fillExam(0, "Математический анализ", 5); Dany.fillExam(0, "Основы ОИБ", 5);
	tempStudents.addElem(Dany);
	//2
	ClassStudent Maxim("Максим", "Бовин", "Олегович", 23, 05, 2003, 2022, "ИКБ", "КБ-03", "БАСО-03-22", "22Б8661", 1);
	Maxim.fillExam(0, "Физика", 4); Maxim.fillExam(0, "История", 5); Maxim.fillExam(0, "Линейная алгебра", 4); Maxim.fillExam(0, "Математический анализ", 4);
	tempStudents.addElem(Maxim);
	//3
	ClassStudent Ksenia("Ксения", "Брайнин", "Алексеевна", 30, 10, 2004, 2022, "ИКБ", "КБ-03", "БАСО-03-22", "22Б1003", 0);
	Ksenia.fillExam(0, "Физика", 3); Ksenia.fillExam(0, "История", 3); Ksenia.fillExam(0, "Линейная алгебра", 4); Ksenia.fillExam(0, "Математический анализ", 3); Ksenia.fillExam(0, "Основы ОИБ", 4);
	tempStudents.addElem(Ksenia);
	//4
	ClassStudent Alina("Алина", "Грибанова", "Владимировна", 01, 02, 2004, 2022, "ИКБ", "КБ-03", "БАСО-03-22", "22Б0864", 0);
	Alina.fillExam(0, "Линейная алгебра", 4); Alina.fillExam(0, "Математический анализ", 4); Alina.fillExam(0, "Основы ОИБ", 4);
	tempStudents.addElem(Alina);
	//5
	ClassStudent Ilya("Илья", "Долгов", "Сергеевич", 15, 03, 2003, 2022, "ИКБ", "КБ-03", "БАСО-03-22", "22Б0866", 1);
	Ilya.fillExam(0, "Физика", 5); Ilya.fillExam(0, "История", 5); Ilya.fillExam(0, "Линейная алгебра", 5); Ilya.fillExam(0, "Математический анализ", 5); Ilya.fillExam(0, "Основы ОИБ", 5);
	tempStudents.addElem(Ilya);
	//6
	ClassStudent Nastya("Анастасия", "Ерофеева", "Александрова", 06, 06, 2004, 2022, "ИКБ", "КБ-02", "БАСО-03-22", "22Б0868", 0);
	Nastya.fillExam(0, "Физика", 3); Nastya.fillExam(0, "История", 4); Nastya.fillExam(0, "Линейная алгебра", 5); Nastya.fillExam(0, "Математический анализ",5);
	tempStudents.addElem(Nastya);
	//7
	ClassStudent Alex("Александр", "Кондрашкин", "Олегович", 06, 11, 2004, 2022, "ИКБ", "КБ-02", "БИСО-01-22", "22Б0875", 1);
	Alex.fillExam(0, "Физика", 5); Alex.fillExam(0, "История", 5); Alex.fillExam(0, "Линейная алгебра", 5); Alex.fillExam(0, "Математический анализ", 5); Alex.fillExam(0, "Основы ОИБ", 4);
	tempStudents.addElem(Alex);
	//8
	ClassStudent Vlad("Владислав", "Королёв", "Денисович", 12, 01, 2004, 2022, "ИКБ", "КБ-02", "БИСО-01-22", "22Б0877", 1);
	Vlad.fillExam(0, "Физика", 4); Vlad.fillExam(0, "История", 5); Vlad.fillExam(0, "Линейная алгебра", 4); Vlad.fillExam(0, "Математический анализ", 4); Vlad.fillExam(0, "Основы ОИБ", 4);
	tempStudents.addElem(Vlad);
	//9
	ClassStudent Kostya("Константин", "Папин", "Михайлович", 25, 01, 2005, 2022, "ИКБ", "КБ-04", "ББББ-06-22", "22Б0884", 1);
	Kostya.fillExam(0, "Физика", 3); Kostya.fillExam(0, "История", 5); Kostya.fillExam(0, "Математический анализ", 4); Kostya.fillExam(0, "Основы ОИБ", 4);
	tempStudents.addElem(Kostya);
	//10
	ClassStudent Artem("Артем", "Франк", "Александрович", 23, 04, 2004, 2022, "ИКБ", "КБ-04", "ББББ-06-22", "22Б0896", 1);
	Artem.fillExam(0, "Физика", 3); Artem.fillExam(0, "История", 4); Artem.fillExam(0, "Линейная алгебра", 4); Artem.fillExam(0, "Математический анализ", 4); 
	tempStudents.addElem(Artem);

	for (int i = 0; i < tempStudents.getSize(); i++) {
		fprintf_s(file, "%s %s %s %d %d %d %d %s %s %s %s\n", \
			tempStudents[i].getSurname(), tempStudents[i].getName(), tempStudents[i].getPatronymic(), \
			tempStudents[i].getBirthDay(), tempStudents[i].getBirthMonth(), tempStudents[i].getBirthYear(), \
			tempStudents[i].getYearStart(), tempStudents[i].getInstitute(), tempStudents[i].getDepartment(),
			tempStudents[i].getGroup(), tempStudents[i].getID(), tempStudents[i].getSex());

	}
		/*fprintf_s(file, "%s %d: %s %s %s %d %d %d %d %s %s %s %s\n", firstWord, (i+1), \
			tempStudents[i].getSurname(), tempStudents[i].getName(), tempStudents[i].getPatronymic(), \
			tempStudents[i].getBirthDay(), tempStudents[i].getBirthMonth(), tempStudents[i].getBirthYear(), \
			tempStudents[i].getYearStart(), tempStudents[i].getInstitute(), tempStudents[i].getDepartment(),
			tempStudents[i].getGroup(), tempStudents[i].getID(), tempStudents[i].getSex());

		for (int s = 0; s < 9; s++) {
			for (int l = 0; l < 10; l++) {
				if (!tempStudents[i].getExam().lessons[s][l].empty) {
					fprintf_s(file, "Сессия %d, экзамен %d : %s %d\n",  (s+1), (l + 1), \
						tempStudents[i].getExam().lessons[s][l].nameLesson, tempStudents[i].getExam().lessons[s][l].grade);
				}
			}
		}
		fprintf_s(file, "%s\n", specialSymb);*/
	fclose(file);
}
int main() {
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	HANDLE hOUTPUT = GetStdHandle(STD_OUTPUT_HANDLE);
	string compilanceCourseWork = "Выполнение курсовой работы...";
	for (int i = 0; i < compilanceCourseWork.length()+1; i++) {
		if (i < compilanceCourseWork.length()) {
			//SetConsoleTextAttribute(hOUTPUT, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			cout << compilanceCourseWork[i];
			Sleep(25);
		}
	}

	system("cls");
	FILE* file = NULL;
	WRITE(file);
	ClassMenu mainMenu;
	mainMenu.draw(file);

};


