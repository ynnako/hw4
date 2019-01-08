#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include "EE_Course.h"

EE_Course::EE_Course(int course_number, char* p_course_name, int num_of_exercises, double weight_hw) :

	Course(course_number, p_course_name, num_of_exercises, weight_hw), factor_(0) {};



	int EE_Course::getFctor()const{
		return factor_;
	}
	
	int EE_Course:: setFactor(int factor){
		factor_=factor;
		return 1;
	}
		
	
	int EE_Course::getCourseGrade ()const{
		int grade_before_factor= Course::getCourseGrade();
		int grade_after_factor=grade_before_factor+factor_;
		return grade_after_factor	> MAX_GRADE ? MAX_GRADE : grade_after_factor;
	}
	
