#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include "Course.h"

static char* p_course_name1=NULL;

Course :: Course(int course_number,char* p_course_name,int num_of_exercises,double weight_hw){
	course_number_(course_number),num_of_exercises_(num_of_exercises),weight_hw_(weight_hw)
	{
		stpcpy(course_name_,p_course_name);
	}
}

int Course::getNum() const {
	
	return course_number_;
}
int Course::getName() const {
	
	if (p_course_name!=NULL) return p_course_name1;
	int name_len=strlen(course_name_);
	char* p_course_name_tmp=new char[name_len+1];
	stpcpy(p_course_name_tmp,course_name_);
	p_course_name1=p_course_name_tmp;
	return p_course_name_tmp1;
}

int Course::getExamGrade()const{
	return exam_grade_;
}

int Course::getHwGrade(int num_of_exercise) const{
	
	if ( num_of_exercise<0 || num_of_exercise>= num_of_exercises_) return -1/*need to ask*/
	return grades_hw_array[num_of_exercise];
}

int Course::getHwNum() const{
	return num_of_exercises_;
}

double Course::getHwWeigh ()const{
	return weight_hw_;
}

double Course::getHwAverage ()const{
	int i;
	int sum=0;
	double average=0;
	for(i=0;i<num_of_hw_;i++){
		sum += grades_hw_array[i];
	}
	average=sum/num_of_hw_;
	return average;
}

int Course::getCourseGrade() const{
	
	double hw_average=getHwAverage();
	int course_grade=0;
	
	course_grade=round((1-weight_hw_)*exam_grade_+ weight_hw_*hw_average);
	return 	course_grade;
}	
	
bool Course::setExamGrade(int exam_grade){
	if (exam_grade>100 || exam_grade<0) return 0;
	exam_grade_=exam_grade;
	return 1;
	
bool Course::setHwGrade(int exercise_num,int exercise_grade){
if (exercise_num<0 || exercise_num>num_of_exercises_ ) return 0;
if (exercise_grade>100 || exercise_grade<0) 					 return 0;
grades_hw_array_[exercise_num]=exercise_grade;
return 1;
}
	
	
