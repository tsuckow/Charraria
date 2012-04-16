#include "global.h"
#include <console/console.h>

int main( int argc, char const * argv[] )
{
	#ifdef _DEBUG
		_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF | _CRTDBG_CHECK_ALWAYS_DF);
	#endif
	
	using namespace nitrocorp::console;

	try
	{
		console_w * console = console_w::GetConsole();
		COORD const size = {{30},{30}};
		console->SetConsoleSize(size);

		*console << L"#fWaiting...\n";
		*console << L"#4Waiting...\n";
		*console << L"$2Waiting...\n";
		*console << L"#0#0Waiting...\n";

		while(1)
		{
			*console << L"Waiting...\n";
			console->WaitForInput(1000);
			console->Draw();
		}

	}
	catch(DWORD e)
	{

		wchar_t errorMsg[256];
		FormatMessage(
			FORMAT_MESSAGE_FROM_SYSTEM,
			NULL,
			e,
			0,
			errorMsg,
			256,
			NULL
			);
			throw;
	}

	wchar_t c[2];
	c[1] = 0;
	for(c[0] = 1; c[0] < L'z'; ++c[0] )
	{
		std::cout << wcstoul( c, nullptr, 16) << " " << errno << std::endl;
	}

	system("pause");
	return 0;
}