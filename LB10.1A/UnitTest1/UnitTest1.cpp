#include "pch.h"
#include "CppUnitTest.h"
#include "../LB10.1A/main.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
            Students students[5];
            students[0].grade_physics = 5;
            students[1].grade_physics = 5;
            students[2].grade_physics = 4;
            students[3].grade_physics = 4;
            students[4].grade_physics = 3;

            int count_5 = 0, count_4 = 0, count_3 = 0;
            count_physics_grades(students, 5, count_5, count_4, count_3);

            Assert::AreEqual(count_5, 2);
            Assert::AreEqual(count_4, 2);
            Assert::AreEqual(count_3, 1);


		}
	};
}
