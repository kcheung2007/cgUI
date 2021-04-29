#ifndef COMM_RECIEVER_H
#define COMM_RECIEVER_H


#include <windows.h>
#include <windowsx.h>

#define		WSA_ACCEPT				(WM_USER + 101)
#define		WSA_READ				(WM_USER + 102)
#define		MAX_PENDING_CONNECTS	4
#define		NO_FLAGS_SET			0  // Used with recv()/send()
#define		NAME_LEN				80	// max. length of text
#define		MSG_LENGTH				80

static		WSADATA					g_wsaData;
static		PHOSTENT				g_pHostEnt;
static		SOCKET					g_Sock;
static		char					g_szBuff[ 80 ];

BOOL AcceptConnection( HWND hDlg, LPARAM lParam );
BOOL ConnectToHost( HWND hDlg );
BOOL CreateCommReciverDlg(HINSTANCE HInst, HWND ParentHwnd);
BOOL CreateCommSenderDlg(HINSTANCE HInst, HWND ParentHwnd);
BOOL CreateCommFinderDlg(HINSTANCE HInst, HWND ParentHwnd);
BOOL CreateCommDownloadDlg(HINSTANCE HInst, HWND ParentHwnd);
BOOL CreateCommModemDlg(HINSTANCE HInst, HWND ParentHwnd);

VOID AsynListen( HWND hDlg );
VOID DisplayWSAError( );
VOID ReadSocketData( HWND, WPARAM, LPARAM );
VOID SendSocketMessage( HWND hDlg, DWORD ctrlID );

#endif // COMM_RECIEVER_H
