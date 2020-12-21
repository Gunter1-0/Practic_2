#include "Unity/src/unity.h"
#include "Trains.h"

void test(){
	Train*el = allocate();
	el->next = allocate();
	el->next->next = NULL;

	TEST_ASSERT_EQUAL_INT(0, count(NULL));
	TEST_ASSERT_EQUAL_INT(1, count(el));
	TEST_ASSERT_EQUAL_INT(2, count(el));	
}

void setUp(){

}

void tearDown(){
	
}

int main(){
	
	UNITY_BEGIN();
	RUN_TEST(test);
	return UNITY_END();
}
