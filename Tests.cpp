#include "pch.h"
#include <CppUnitTest.h>
#include <winrt/Example.h>

namespace cpp_unit
{
	using namespace Microsoft::VisualStudio::CppUnitTestFramework;
}

namespace UnitTest2
{
	TEST_CLASS(UnitTest2)
	{
		TEST_METHOD(TestMethod1)
		{
			cpp_unit::Assert::IsTrue(true);

			winrt::Example::Class testClass;
			testClass.Method();
		}
	};
}
