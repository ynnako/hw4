#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include "EE_Course.h"

EE_Course :: EE_Course(int course_number,char* p_course_name,int num_of_hw,float miashkal_hw){
	Course(course_number,p_course_name,num_of_hw,miashkal_hw),factor_(0);
	
}

	int EE_Cours::getFctor()const{
		return factor_;
	}
	
		int EE_Course:: setFactor(int factor){
			factor_=factor;
			return 1;
		}
		
	
	
	int EE_Course::getCourseGrade const(){
		int grade_before_factor= Course::getCourseGrade();
		int grade_after_factor=grade_before_factor+factor_;
		return grade_after_factor	> MAX_GRADE ? MAX_GRADE : grade_after_factor;
	}
	
	/*int EE_Course::getCourseGrade const(){
	
	float hw_average=getHwAverage();
	int grade_before_factor=0;
	int grade_after_factor=0;
	
	
	grade_before_factor=round((1-miashkal_hw_)*exam_grade_+ miashkal_hw_*hw_average);
	grade_after_factor=grade_before_factor+factor_;
	if (grade_after_factor>100) return 100;
	return 	grade_after_factor;	
	}
*/