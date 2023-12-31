#include "pch.h"
#include <winrt/Example.h>
#include <wil/filesystem.h>

namespace cpp_unit
{
    using namespace Microsoft::VisualStudio::CppUnitTestFramework;
}

winrt::Example::Class make_example();

TEST_CLASS(TestClass)
{
    TEST_METHOD(TestMethod)
    {
        cpp_unit::Assert::IsTrue(true);
    }

    TEST_METHOD(CreateAndCallWinRtObject)
    {
        winrt::Example::Class testClass;
        testClass.Method();
    }

    TEST_METHOD(Fail)
    {
        cpp_unit::Assert::IsTrue(false);
    }

    TEST_METHOD(CallMake)
    {
        auto e = make_example();
        e.Method();
    }

    TEST_METHOD(UseAsyncMethodsSynchronously)
    {
        std::thread([&]()
        {
            using namespace winrt::Windows::System;
            using namespace winrt::Windows::Foundation;

            auto uri = Uri(L"http://www.msn.com");
            auto r = Launcher::LaunchUriAsync(uri).get();;
        }).join();
    }
};
