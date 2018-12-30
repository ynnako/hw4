#include "Course.h"

class CS_Course :public Course {
	private:
		int isTakef_;
		char book_name[MAX_COURSE_NUM];
	public:
		CS_Course();/*constructor*/
		int getFctor(int course_number,char* p_course_name,int num_of_hw,float miashkal_hw,bool isTakef,char* p_book_name)const;
		int setFactor(int factor);
		int getCourseGrade const();/*need todo*/
		
}	