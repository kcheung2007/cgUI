/*+----------------------------------------------------------------------------
FILE:       RegUnreg.H

PURPOSE:    Declaration of Ole/Com server registration library functions

FUNCTIONS:  
            RegisterInprocServer- Create a registry entry for an inproc server.
            RegisterLocalServer - Create a registry entry for a local server.
            RegisterProxyDll    - Create a registry entry for a proxy DLL.
            UnregisterInprocServer- Remove a registry entry for an inproc server.
            UnregisterLocalServer - Remove a registry entry for a local server.
            UnregisterProxyDll  - Remove a registry entry for a proxy DLL.
-----------------------------------------------------------------------------*/
#define THREAD_MODEL_ONE        0
#define THREAD_MODEL_APARTMENT  1
#define THREAD_MODEL_BOTH       2

HRESULT RegisterInprocServer(const char *szServerName,REFCLSID rclsid,int threadModel);
HRESULT RegisterLocalServer(REFCLSID rclsid,int threadModel);
HRESULT RegisterProxyDll(const char *pszProxyDll);
HRESULT UnregisterInprocServer(REFCLSID rclsid);
HRESULT UnregisterLocalServer(REFCLSID rclsid);
HRESULT UnregisterProxyDll(const char *pszProxyDll);

// End of Regunreg.cpp
