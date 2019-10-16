// Vapp1.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

#include "pch.h"
#include <iostream>
#include <windows.h>
#include <winhttp.h>
#include <string>

int GetDataFromWeb(const LPCWSTR& url, std::string& websitecontents )
{
	DWORD dwSize = 0;
	DWORD dwDownloaded = 0;
	LPSTR pszOutBuffer;
	BOOL  bResults = FALSE;
	HINTERNET			hSession = nullptr,
						hConnect = nullptr,
						hRequest = nullptr;

	// Use WinHttpOpen to obtain a session handle.
	hSession = WinHttpOpen(	L"WinHTTP Example/1.0",
							WINHTTP_ACCESS_TYPE_DEFAULT_PROXY,
							WINHTTP_NO_PROXY_NAME,
							WINHTTP_NO_PROXY_BYPASS, 0);

	// Specify an HTTP server.
	if (hSession)
	{ 
		hConnect = WinHttpConnect(hSession, url, INTERNET_DEFAULT_HTTPS_PORT, 0);
	}
	else
	{
		return -1;
	}

	// Create an HTTP request handle.
	if (hConnect)
	{
		hRequest = WinHttpOpenRequest(	hConnect, L"GET", NULL,
										NULL, WINHTTP_NO_REFERER,
										WINHTTP_DEFAULT_ACCEPT_TYPES,
										WINHTTP_FLAG_SECURE);
	}

	// Send a request.
	if (hRequest)
	{
		bResults = WinHttpSendRequest(hRequest,
			WINHTTP_NO_ADDITIONAL_HEADERS, 0,
			WINHTTP_NO_REQUEST_DATA, 0,
			0, 0);
	}

	// End the request.
	if (bResults)
	{
		bResults = WinHttpReceiveResponse(hRequest, NULL);
	}

	// Keep checking for data until there is nothing left.
	if (bResults)
	{
		do
		{
			// Check for available data.
			dwSize = 0;
			if (!WinHttpQueryDataAvailable(hRequest, &dwSize))
			{
				std::cerr << GetLastError() << std::endl;
			}

			// Allocate space for the buffer.
			pszOutBuffer = new char[dwSize + 1];
			if (!pszOutBuffer)
			{
				std::cerr << "Out of memory \n";
				dwSize = 0;
			}
			else
			{
				// Read the data.
				ZeroMemory(pszOutBuffer, dwSize + 1);

				if (!WinHttpReadData(hRequest, (LPVOID)pszOutBuffer, dwSize, &dwDownloaded))
				{
					std::cerr << GetLastError() << std::endl;
				}
				else
				{
					websitecontents = websitecontents + pszOutBuffer;
				}

				// Free the memory allocated to the buffer.
				delete[] pszOutBuffer;
			}
		} while (dwSize > 0);
	}

	// Report any errors.
	if (!bResults)
	{
		std::cerr << "Error " << GetLastError() << " has occurred.\n" << std::endl;
		return -1;
	}
		
	// Close any open handles.
	if (hRequest) WinHttpCloseHandle(hRequest);
	if (hConnect) WinHttpCloseHandle(hConnect);
	if (hSession) WinHttpCloseHandle(hSession);

	return 0;
}

int main()
{
	std::string s;
	if ( GetDataFromWeb(L"www.microsoft.com", s) == 0 )
	{
		std::cout << s << std::endl;
	}
	else
	{
		std::cerr << "Error " << std::endl;
	}

}