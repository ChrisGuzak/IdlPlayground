#include "pch.h"
#include <winrt/Example.h>
#include <wil/filesystem.h>

namespace cpp_unit = Microsoft::VisualStudio::CppUnitTestFramework;

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
        using namespace winrt::Windows::System;
        using namespace winrt::Windows::Foundation;

        auto uri = Uri(L"http://www.msn.com");
        auto r = Launcher::LaunchUriAsync(uri).get();;
    }

    TEST_METHOD(VerifyRunSettingsFileConfiguresMta)
    {
        APTTYPE aptType{};
        APTTYPEQUALIFIER aptTypeQualifier{};
        THROW_IF_FAILED(CoGetApartmentType(&aptType, &aptTypeQualifier));
        // Verify test.runsettings is working
        cpp_unit::Assert::IsTrue(aptType == APTTYPE_MTA);
    }
};
