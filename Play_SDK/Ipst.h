#ifndef ipst_h
#define ipst_h

#include <unknwn.h>

// ----------------------------------------------------------------------------
extern "C" const GUID PST_UID;

// ----------------------------------------------------------------------------
enum F_PST_INFO {
	F_PST_INFO_UID,
	F_PST_INFO_NAME,
};

// ----------------------------------------------------------------------------
typedef struct {
	long	field;
	GUID	uid;
	long	namesize;
	char	*name;
} PST_INFO;

// ----------------------------------------------------------------------------
enum PST_ACCESS {
	PST_ACCESS_READ,
	PST_ACCESS_WRITE,
};

// ----------------------------------------------------------------------------
enum PST_SEEK {
	PST_SEEK_START,
	PST_SEEK_CURRENT,
	PST_SEEK_END,
};

// ----------------------------------------------------------------------------
struct IPST : public IUnknown {
	virtual HRESULT __stdcall Open(long access, char *name)=0;
	virtual HRESULT __stdcall Create(char *name)=0;
	virtual HRESULT __stdcall Close()=0;
	virtual HRESULT __stdcall AssignUID(GUID *uid)=0;
	virtual HRESULT __stdcall Info(PST_INFO *info)=0;

	virtual HRESULT __stdcall OpenFolder(HANDLE *folder, char *name)=0;
	virtual HRESULT __stdcall NewFolder(HANDLE *folder, char *name)=0;
	virtual HRESULT __stdcall SetCurrentFolder(char *name)=0;
	virtual HRESULT __stdcall CloseFolder(HANDLE folder)=0;
	virtual HRESULT __stdcall DeleteFolder(char *name)=0;
	virtual HRESULT __stdcall RenameFolder(HANDLE folder, char *name)=0;

	virtual HRESULT __stdcall OpenFile(HANDLE *file, long access, char *name)=0;
	virtual HRESULT __stdcall NewFile(HANDLE *file, char *name)=0;
	virtual HRESULT __stdcall CloseFile(HANDLE file)=0;
	virtual HRESULT __stdcall DeleteFile(char *name)=0;
	virtual HRESULT __stdcall RenameFile(HANDLE file, char *name)=0;
	virtual HRESULT __stdcall Read(HANDLE file, char *buffer, long *size)=0;
	virtual HRESULT __stdcall Write(HANDLE file, char *buffer, long *size)=0;
	virtual HRESULT __stdcall Seek(HANDLE file, long mode, long *offset)=0;
};

enum HRESULT_IPST {
	HRESULT_IPSA_WARNING = 0x00000000,
	HRESULT_IPSA_WARNING_,
	HR_PST_ERROR = 0xE8240000,
	HR_PST_ERROR_ROOT,
	HR_PST_ERROR_INUSE,
	HR_PST_ERROR_EMPTY,
	HR_PST_ERROR_PARENT,
	HR_PST_ERROR_SEEKING,
	HR_PST_ERROR_ACCESSMODE,
	HR_PST_ERROR_OPENING_DISKFILE,
	HR_PST_ERROR_CURRENT_FOLDER,
	HR_PST_ERROR_FOLDER_EXIST,
	HR_PST_ERROR_FOLDER_INUSE,
	HR_PST_ERROR_FOLDER_MISSING,
	HR_PST_ERROR_FILE_EXIST,
	HR_PST_ERROR_FILE_INUSE,
	HR_PST_ERROR_FILE_MISSING,
	HR_PST_ERROR_ALLOCATING_STRING,
	HR_PST_ERROR_ALLOCATING_STRUCTURE,
	HR_PST_ERROR_LOCATING_FOLDER,
	HR_PST_ERROR_LOCATING_FILE,
	HR_PST_ERROR_READING_HEADER,
	HR_PST_ERROR_READING_CONTENT,
	HR_PST_ERROR_LOADING_FOLDERTREE,
	HR_PST_ERROR_WRITING_HEADER,
	HR_PST_ERROR_WRITING_CONTENT,
	HR_PST_ERROR_WRITING_FOLDERTREE,
	HR_PST_ERROR_WRITING_DATABLOCKS,
	HR_PST_ERROR_INVALID_PST,
};

extern "C" const GUID CLSID_PST;
extern "C" const GUID IID_IPST;

#endif
