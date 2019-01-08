
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include "CS_Course.h"



CS_Course :: CS_Course(int course_number, char* p_course_name, int num_of_exercises, double weight_hw, bool isTakef, char* p_book_name) :
	Course(course_number,p_course_name, num_of_exercises, weight_hw),isTakef_(isTakef)
	{
	int len_book_name = strlen(p_book_name);
	char* p_2_book_name = new char[len_book_name + 1];
	strcpy(p_2_book_name,p_book_name);
	p_book_name_ = p_2_book_name;
	};
CS_Course :: ~CS_Course() {
	delete[] p_book_name_;
}

bool CS_Course::setTakef(bool isTakef){
	isTakef_=isTakef;
	return 1;
}

void  CS_Course::setBook(char* p_book_name){
	if (p_book_name_ != NULL) {
		delete[] p_book_name_;
	}
	int len_book_name = strlen(p_book_name);
	char* p_2_book_name = new char[len_book_name + 1];
	strcpy(p_2_book_name,p_book_name);
	p_book_name_=p_2_book_name;

return;
}

int CS_Course::getCourseGrade() const {
	double hw_average = getHwAverage();
	double hw_weigh = getHwWeigh();
	int exam_grade = getExamGrade();
	bool takef = isTakef_;
	double course_grade = 0;
	course_grade = (1 - hw_weigh)*exam_grade + hw_weigh * hw_average +0.5;
	if (takef) return (int)course_grade;
	return exam_grade > course_grade ? exam_grade : (int)course_grade;
}

bool CS_Course:: isTakef() const {
	return isTakef_;
}

char* CS_Course::getBook() const {
	int len_book_name = strlen(p_book_name_);
	char* p_2_book_name = new char[len_book_name + 1];
	strcpy(p_2_book_name, p_book_name_);
	return p_2_book_name;
}
