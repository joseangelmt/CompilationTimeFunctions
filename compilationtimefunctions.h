#pragma once

constexpr int AsciiByteToInt(char value)
{
	if (value <= 0x30)
		return 0;
	return value - 0x30;
}

constexpr int CompilationDay()
{
	return AsciiByteToInt(__DATE__[4]) * 10 + AsciiByteToInt(__DATE__[5]);
}

constexpr int CompilationMonth()
{
	switch (__DATE__[0])
	{
	case 'A':
		if (__DATE__[1] == 'p')
			return 4;
		return 8;
	case 'D':
		return 12;
	case 'F':
		return 2;
	case 'J':
		if (__DATE__[1] == 'a')
			return 1;

		if (__DATE__[2] == 'n')
			return 6;

		return 7;
	case 'O':
		return 10;
	case 'M':
		if (__DATE__[2] == 'r')
			return 3;
		return 5;
	case 'N':
		return 11;
	default:
		return 9;
	}
}

constexpr int CompilationYear()
{
	return AsciiByteToInt(__DATE__[7]) * 1000 + AsciiByteToInt(__DATE__[8]) * 100 + AsciiByteToInt(__DATE__[9]) * 10 + AsciiByteToInt(__DATE__[10]);
}

constexpr int CompilationHour()
{
	return AsciiByteToInt(__TIME__[0]) * 10 + AsciiByteToInt(__TIME__[1]);
}

constexpr int CompilationMinute()
{
	return AsciiByteToInt(__TIME__[3]) * 10 + AsciiByteToInt(__TIME__[4]);
}

constexpr int CompilationSecond()
{
	return AsciiByteToInt(__TIME__[6]) * 10 + AsciiByteToInt(__TIME__[8]);
}

constexpr struct tm GetCompilationTM()
{
	return {
		CompilationSecond(),
		CompilationMinute(),
		CompilationHour(),
		CompilationDay(),
		CompilationMonth(),
		CompilationYear() - 1900,
		0,
		0,
		0 };
}

#ifdef _MINWINBASE_
constexpr SYSTEMTIME GetCompilationSystemTime()
{
	return {
		static_cast<WORD>(CompilationYear()),
		static_cast<WORD>(CompilationMonth()),
		0,
		static_cast<WORD>(CompilationDay()),
		static_cast<WORD>(CompilationHour()),
		static_cast<WORD>(CompilationMinute()),
		static_cast<WORD>(CompilationSecond()),
		0};
}
#endif
