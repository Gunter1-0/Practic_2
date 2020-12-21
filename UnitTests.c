#include"Unity/src/unity.h"
#include "Testing.h"

void test(){

	TEST_ASSERT_EQUAL_INT(0, countOfElements(NULL));
	TEST_ASSERT_EQUAL_INT64(1, countOfElements(allocate()->next=NULL));
	TEST_ASSERT_EQUAL_INT64(2, countOfElements(allocate()->next=allocate()->next=NULL));	
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
