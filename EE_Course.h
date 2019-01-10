
#ifndef _EE_COURSE_H_
#define _EE_COURSE_H_

#include "Course.h"
#define MAX_GRADE 100

class EE_Course :public Course {
	private:
		int factor_;
	public:
		EE_Course(int course_number,char* p_course_name,int num_of_exercises,double weight_hw);
		int getFctor()const;
		int setFactor(int factor);
		int getCourseGrade() const;
		
};
#endif