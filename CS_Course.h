#include "Course.h"

class CS_Course :public Course {
	private:
		int isTakef_;
		char book_name[MAX_COURSE_NUM];
	public:
		CS_Course();/*constructor*/
		bool setTakef(bool isTakef);
		
		int getCourseGrade() const;/*need todo*/
		
}
	