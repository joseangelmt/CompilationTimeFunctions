[![NuGet](https://img.shields.io/nuget/v/CompilationTimeFunctions?style=flat)](https://www.nuget.org/packages/CompilationTimeFunctions/)

# CompilationTimeFunctions

In C++ you can get the compilation time using the \_\_DATE\_\_ and \_\_TIME\_\_ macros, but that macros returns strings representing the date and time and not values we can use to compare.

Sometimes we need to compare this dates and times, maybe because we want to know at runtime whether or not our program's compile date is higher than the maximum date stored in the user's license file.

The constexpr functions provided by this repository helps us to convert the \_\_DATE\_\_ and \_\_TIME\_\_ macros into values that we can try and/or compare in our programs.

To use them we only have to install the NuGet package in your project:

```Nuget
Install-Package CompilationTimeFunctions -Version 1.0.0
```

Then include _<compilationtimefunctions.h>_ and call to any of the next functions:


|Function|Returns|Range|
|------|-------|------|
|CompilationDay()|int|[1,31]|
|CompilationMonth()|int|[1,12]|
|CompilationYear()|int||
|CompilationHour()|int|[0,24]|
|CompilationMinute()|int|[0,59]|
|CompilationSecond()|int|[0,59]|
|GetCompilationTM()|struct tm||
|GetCompilationSystemTime()|SYSTEMTIME|*only if you have defined \_MINWINBASE\_*|

For example

```c++
#include <compilationtimefunctions.h>

void main()
{
    const auto compilationTime = GetCompilationTM();
    std::cout << compilationTime.tm_hour << ":" << compilationTime.tm_min << ":" << compilationTime.tm_sec << std::endl;
}
```
