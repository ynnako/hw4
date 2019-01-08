#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include "Course.h"

/*
  Function: 
  Description:
  Parameters:
  Return value: 
*/

Course :: Course(int course_number,char* p_course_name,int num_of_exercises,double weight_hw):
	course_number_(course_number),num_of_exercises_(num_of_exercises),weight_hw_(weight_hw)
	{
	int len_course_name = strlen(p_course_name);
	char* p_2_course_name = new char[len_course_name + 1];
	strcpy(p_2_course_name,p_course_name);
	int* p_grades_hw_array = new int[num_of_exercises + 1];
	for (int i = 0; i < num_of_exercises; i++) {
		p_grades_hw_array[i] = 0;
	}
	p_grades_hw_array_ = p_grades_hw_array;
	p_course_name_ = p_2_course_name;
};

/*
  Function:
  Description:
  Parameters:
  Return value:
*/
Course::~Course() {
	delete[] p_course_name_;
	delete[] p_grades_hw_array_;
}

/*
  Function:
  Description:
  Parameters:
  Return value:
*/
int Course::getNum() const {

	return course_number_;
}

/*
  Function:
  Description:
  Parameters:
  Return value:
*/
char* Course::getName() const  {
	int len_course_name = strlen(p_course_name_);
	char* p_2_course_name = new char[len_course_name + 1];
	strcpy(p_2_course_name, p_course_name_);
	return p_2_course_name;
	
}

/*
  Function:
  Description:
  Parameters:
  Return value:
*/
int Course::getExamGrade()const{
	return exam_grade_;
}

/*
  Function:
  Description:
  Parameters:
  Return value:
*/
int Course::getHwGrade(int num_of_exercise) const{

	if (num_of_exercise < 0 || num_of_exercise >= num_of_exercises_) return 0;
	return p_grades_hw_array_[num_of_exercise];
}

/*
  Function:
  Description:
  Parameters:
  Return value:
*/
int Course::getHwNum() const{
	return num_of_exercises_;
}

/*
  Function:
  Description:
  Parameters:
  Return value:
*/
double Course::getHwWeigh ()const{
	return weight_hw_;
}

/*
  Function:
  Description:
  Parameters:
  Return value:
*/
double Course::getHwAverage ()const{
	double average = 0;
	if(num_of_exercises_==0) return average;
	int i;
	int sum=0;

	for(i=0;i< num_of_exercises_;i++){
		sum += p_grades_hw_array_[i];
	}
	average=sum/ num_of_exercises_;
	return average;
}

/*
  Function:
  Description:
  Parameters:
  Return value:
*/
int Course::getCourseGrade() const{

	double hw_average=getHwAverage();
	double course_grade=0;
	course_grade=(1-weight_hw_)*exam_grade_+ weight_hw_*hw_average +0.5;
	return 	(int)course_grade;
}

/*
  Function:
  Description:
  Parameters:
  Return value:
*/
bool Course::setExamGrade(int exam_grade) {
	if (exam_grade > 100 || exam_grade < 0) return false;
	exam_grade_ = exam_grade;
	return true;
}

/*
  Function:
  Description:
  Parameters:
  Return value:
*/
bool Course::setHwGrade(int exercise_num,int exercise_grade){
if (exercise_num<0 || exercise_num>num_of_exercises_ ) return false;
if (exercise_grade>100 || exercise_grade<0) 		   return false;
p_grades_hw_array_[exercise_num]=exercise_grade;

return true;
}


