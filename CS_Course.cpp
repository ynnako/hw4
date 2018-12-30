
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include "CS_Course.h"



CS_Course :: CS_Course(int course_number,char* p_course_name,int num_of_hw,float miashkal_hw,bool isTakef,char* p_book_name){
	Course(course_number,p_course_name,num_of_hw,miashkal_hw),isTakef_(isTakef) 
	{
		stpcpy(book_name,p_book_name);
	}	
}

bool CS_Course::setTakef(bool isTakef){
	isTakef_=isTakef;
	return 1;
}
	
void setBook(char* p_book_name){
	strcpy(book_name,p_book_name);
	/*
	int i=0;
	while(*p_book_name!='\0'){
		book_name[i]=*(p_book_name+i);
		i++;
	}
book_name[i]='\0';
*/
return;
}

int getCourseGrade() const{
	double hw_average = getHwAverage();
	double hw_weigh = getHwWeigh();
	int exam_grade = getExamGrade();
	bool takef = isTakef_;
	int course_grade=0;
	course_grade=round((1-miashkal_hw_)*exam_grade_+ miashkal_hw_*hw_average);
	if (takef) {
		return course_grade;
	}
	return max(exam_grade,course_grade);
		
	