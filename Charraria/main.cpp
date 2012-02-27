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

		while(1)
		{
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

	return 0;
}