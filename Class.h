#pragma once
#include "Example.Class.g.h"

namespace winrt::Example::implementation
{
    struct Class : ClassT<Class>
    {
        Class() = default;

        void Method();
    };
}
namespace winrt::Example::factory_implementation
{
    struct Class : ClassT<Class, implementation::Class>
    {
    };
}
