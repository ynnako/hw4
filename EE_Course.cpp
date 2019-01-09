#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include "EE_Course.h"


/*
  Function	   : EE_Course
  Description  : constructor , initial values for objects in EE_Course class 
  Parameters   : course_number	   - course number
			     p_course_name	   - pointer to course name
			     num_of_exercises  - number of hw exercises
			     weight_hw		   - weight of hw from whole grade
  Return value : None
*/
EE_Course::EE_Course(int course_number, char* p_course_name, int num_of_exercises, double weight_hw) :

	Course(course_number, p_course_name, num_of_exercises, weight_hw), factor_(0) {};


/*
  Function     : getFctor
  Description  : return factor value
  Parameters   : None
  Return value : factor 
*/
	int EE_Course::getFctor()const{
		return factor_;
	}
	
/*
  Function     : setFactor
  Description  : set the factor value
  Parameters   : factor - factor value
  Return value : always 1
*/
	int EE_Course:: setFactor(int factor){
		factor_=factor;
		return 1;
	}
		
/*
  Function      : getCourseGrade
  Description  : return the course grade according to exam grade,hw grades and facor value
  Parameters   : None
  Return value : course grade 
*/	
	int EE_Course::getCourseGrade ()const{
		int grade_before_factor= Course::getCourseGrade();
		int grade_after_factor=grade_before_factor+factor_;
		return grade_after_factor	> MAX_GRADE ? MAX_GRADE : grade_after_factor;
	}
	
