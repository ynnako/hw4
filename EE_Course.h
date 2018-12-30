
#include "Course.h"
#define MAX_GRADE 100
class EE_Course :public Course {
	private:
		int factor_;
	public:
		EE_Course(int course_number,char* p_course_name,int num_of_exercises,double miashkal_hw);
		int getFctor()const;
		int setFactor(int factor);
		int getCourseGrade() const;
		
}	