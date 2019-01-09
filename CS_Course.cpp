
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include "CS_Course.h"
using std::cout;

/*
  Function     : CS_Course
  Description  : constructor initial values for objects in CS_Course class 
  Parameters   : course_number	  - course number    
			     p_course_name    - pointer to course name
			     num_of_exercises - number of hw exercises
			     weight_hw        - weight of hw from whole grade
			     isTakef          - if the hw is takef
			     p_book_name      - pointer to book name
  Return value : None
*/
CS_Course :: CS_Course(int course_number, char* p_course_name, int num_of_exercises, double weight_hw, bool isTakef, char* p_book_name) :
	Course(course_number,p_course_name, num_of_exercises, weight_hw),isTakef_(isTakef)
	{
	if (p_book_name != NULL)
	{
		int len_book_name = strlen(p_book_name);
		char* p_2_book_name = new char[len_book_name + 1];
		strcpy(p_2_book_name, p_book_name);
		p_book_name_ = p_2_book_name;
	}
	else p_book_name_ = NULL;
	};

/*
  Function     : CS_Course
  Description  : destructor
  Parameters   : free the dynamic allocations
  Return value : None
*/
CS_Course :: ~CS_Course() {
	if (p_book_name_ != NULL) {
		delete[] p_book_name_;
	}
}

/*
  Function     : setTakef
  Description  : set the value of isTakef_
  Parameters   : isTakef - 1 if hw if takef else 0
  Return value : always 1
*/
bool CS_Course::setTakef(bool isTakef){
	isTakef_=isTakef;
	return 1;
}

/*
  Function     : setBook
  Description  : set the book name 
  Parameters   : p_book_name- pointer to book name
  Return value : None
*/
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

/*
  Function     : getCourseGrade
  Description  : return the course grade according to exam grade,hw grades and isTakef_ object
  Parameters   : None
  Return value : course grade' value between 0-100
*/
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

/*
  Function     : isTakef
  Description  : return if thw hw is takef 
  Parameters   : None
  Return value : 1 if hw is takef else 0
*/
bool CS_Course:: isTakef() const {
	return isTakef_;
}

/*
  Function     : getBook
  Description  : returns a pointer to a clone of the book's name
  Parameters   : None
  Return value : char* pointer for book name
*/
char* CS_Course::getBook() const {
	int len_book_name = strlen(p_book_name_);
	char* p_2_book_name = new char[len_book_name + 1];
	strcpy(p_2_book_name, p_book_name_);
	return p_2_book_name;
}
