#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include "Course.h"

/*
  Function	   : Course
  Description  : constructor for Course class, initial values for objects in at Course class
  Parameters   : course_number	    - course number
				 p_course_name	    - pointer to course name
			     num_of_exercises	- number of hw exercises
			     weight_hw		    - weight of hw from whole grade
  Return value : None
*/

Course :: Course(int course_number,char* p_course_name,int num_of_exercises,double weight_hw):
	course_number_(course_number) , num_of_exercises_(num_of_exercises) , weight_hw_(weight_hw) , exam_grade_(0)
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
  Function	   : ~Course
  Description  : destructor for Course class
  Parameters   : None
  Return value : None
*/
Course::~Course() {
	if (p_course_name_ != NULL) delete[] p_course_name_;
	if (p_grades_hw_array_ != NULL) delete[] p_grades_hw_array_;
}

/*
  Function     : getNum
  Description  : get the course number
  Parameters   : None
  Return value : course number
*/
int Course::getNum() const {

	return course_number_;
}

/*
  Function    : getName
  Description : returns a pointer to a clone of the course's name
  Parameters  : None
  Return value: char * pointer for course name
*/
char* Course::getName() const  {
	int len_course_name = strlen(p_course_name_);
	char* p_2_course_name = new char[len_course_name + 1];
	strcpy(p_2_course_name, p_course_name_);
	return p_2_course_name;
	
}

/*
  Function     : getExamGrade
  Description  : return exam grade
  Parameters   : None
  Return value : exam grade , value between 0-100
*/
int Course::getExamGrade()const{
	return exam_grade_;
}

/*
  Function     : getHwGrade
  Description  : return the grade for specific hw exercise   
  Parameters   : num_of_exercise
  Return value : grade of hw num_of_exercise, value between 0-100
*/
int Course::getHwGrade(int num_of_exercise) const{

	if (num_of_exercise < 0 || num_of_exercise >= num_of_exercises_) return 0;
	return p_grades_hw_array_[num_of_exercise];
}

/*
  Function     : getHwNum
  Description  : return the number of hw exercise
  Parameters   : None
  Return value : number of hw exercises
*/
int Course::getHwNum() const{
	return num_of_exercises_;
}

/*
  Function     : getHwWeigh
  Description  : return the weigth of hw from the whole grade
  Parameters   : None
  Return value : weight of the hw , value between 0-1
*/
double Course::getHwWeigh ()const{
	return weight_hw_;
}

/*
  Function     : getHwAverage
  Description  : return thr average of the hw exercise
  Parameters   : None
  Return value : if no hw return 0 else the average , value between 0-100
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
  Function     : getCourseGrade
  Description  : calculate the course grade according the exam and he grades
  Parameters   : None
  Return value : course grade , value between 0-100
*/
int Course::getCourseGrade() const{

	double hw_average=getHwAverage();
	double course_grade=0;
	course_grade=(1-weight_hw_)*exam_grade_+ weight_hw_*hw_average +0.5;
	return 	(int)course_grade;
}

/*
  Function     : setExamGrade
  Description  : set the exam grade 
  Parameters   : exam grade
  Return value : 1 if succses else 0
*/
bool Course::setExamGrade(int exam_grade) {
	if (exam_grade > 100 || exam_grade < 0) return false;
	exam_grade_ = exam_grade;
	return true;
}

/*
  Function     : setExamGrade
  Description  : set a grade for specific hw exercise
  Parameters   : exercise_num   - number of exercise
			     exercise_grade - grade of the exercise
  Return value : 1 if succses else 0
*/
bool Course::setHwGrade(int exercise_num,int exercise_grade){
if (exercise_num<0 || exercise_num>=num_of_exercises_ ) return false;
if (exercise_grade>100 || exercise_grade<0) 		   return false;
p_grades_hw_array_[exercise_num]=exercise_grade;

return true;
}


