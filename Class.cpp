#include "pch.h"
#include "Class.h"
#include "Example.Class.g.cpp"

namespace winrt::Example::implementation
{
    void Class::Method()
    {
        // do nothing
    }
}

winrt::Example::Class make_example()
{
    return winrt::make<winrt::Example::implementation::Class>();
}
