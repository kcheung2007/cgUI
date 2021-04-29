// ----------------------------------------------------------------------------
// Play Incorporated Security Provider
// Copyright 1988, Play Incorporated, All rights Reserved
// 
// File: CryptErr.mc (.h)
//
// Contents:  
//	Error definitions for Play Cryptography
//
// History:
//    May 1998    cpdaniel  created      
// ----------------------------------------------------------------------------
// CryptErr.H
// automatically generated from CryptErr.mc - DO NOT EDIT

#ifndef __crypterr_h__
#define __crypterr_h__
//
//  Values are 32 bit values layed out as follows:
//
//   3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1 1 1
//   1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0
//  +-+-+-+-+-+---------------------+-------------------------------+
//  |S|R|C|N|r|    Facility         |               Code            |
//  +-+-+-+-+-+---------------------+-------------------------------+
//
//  where
//
//      S - Severity - indicates success/fail
//
//          0 - Success
//          1 - Fail (COERROR)
//
//      R - reserved portion of the facility code, corresponds to NT's
//              second severity bit.
//
//      C - reserved portion of the facility code, corresponds to NT's
//              C field.
//
//      N - reserved portion of the facility code. Used to indicate a
//              mapped NT status value.
//
//      r - reserved portion of the facility code. Reserved for internal
//              use. Used to indicate HRESULT values that are not status
//              values, but are instead message ids for display strings.
//
//      Facility - is the facility code
//
//      Code - is the facility's status code
//
//
// Define the facility codes
//
#define FACILITY_Crypto                  0x807


//
// Define the severity codes
//
#define STATUS_SEVERITY_WARNING          0x2
#define STATUS_SEVERITY_SUCCESS          0x0
#define STATUS_SEVERITY_INFORMATIONAL    0x1
#define STATUS_SEVERITY_ERROR            0x3


//
// MessageId: CRYPT_ERR_UNIMPL
//
// MessageText:
//
//  (Internal Error) an unimplemented command was called
//
#define CRYPT_ERR_UNIMPL                 ((ULONG)0xE8070001L)

//
// MessageId: CRYPT_ERR_BADBLOCKSIZE
//
// MessageText:
//
//  The specified blocksize is not supported by this implementation.
//
#define CRYPT_ERR_BADBLOCKSIZE           ((ULONG)0xE8070002L)

//
// MessageId: CRYPT_ERR_KEY_TOO_SMALL
//
// MessageText:
//
//  The specified key is too small.
//
#define CRYPT_ERR_KEY_TOO_SMALL          ((ULONG)0xE8070003L)

//
// MessageId: CRYPT_ERR_KEY_TOO_LARGE
//
// MessageText:
//
//  The specified key is too large.
//
#define CRYPT_ERR_KEY_TOO_LARGE          ((ULONG)0xE8070004L)

//
// MessageId: CRYPT_ERR_KEY_NOT_SET
//
// MessageText:
//
//  No session key has been set on this block cipher object.
//
#define CRYPT_ERR_KEY_NOT_SET            ((ULONG)0xE8070005L)

//
// MessageId: CRYPT_ERR_DATA_WRITE_ERROR
//
// MessageText:
//
//  A write request to flush a buffer wrote less data than was supplied.
//
#define CRYPT_ERR_DATA_WRITE_ERROR       ((ULONG)0xE8070006L)

//
// MessageId: CRYPT_ERR_DEFLATE_ERROR
//
// MessageText:
//
//  An error occurred while compressing a buffer.
//
#define CRYPT_ERR_DEFLATE_ERROR          ((ULONG)0xE8070007L)

//
// MessageId: CRYPT_ERR_INFLATE_ERROR
//
// MessageText:
//
//  An error occurred while decompressing a buffer.
//
#define CRYPT_ERR_INFLATE_ERROR          ((ULONG)0xE8070008L)

//
// MessageId: CRYPT_ERR_DIGEST_DOESNT_MATCH
//
// MessageText:
//
//  The hash supplied did not match the hash of the decrypted file.
//
#define CRYPT_ERR_DIGEST_DOESNT_MATCH    ((ULONG)0xE8070009L)

//
// MessageId: CRYPT_ERR_BAD_HEADER
//
// MessageText:
//
//  The specified file is not a vaild vault file.
//
#define CRYPT_ERR_BAD_HEADER             ((ULONG)0xE807000AL)

//
// MessageId: CRYPT_ERR_BAD_SIZE
//
// MessageText:
//
//  The size of the supplied vault file is inconsistent with the file's header.
//
#define CRYPT_ERR_BAD_SIZE               ((ULONG)0xE807000BL)

//
// MessageId: CRYPT_ERR_SIZE_ERROR
//
// MessageText:
//
//  The size of the decrypted (and decompressed) file doesn't match the size in the header.
//
#define CRYPT_ERR_SIZE_ERROR             ((ULONG)0xE807000CL)

//
// MessageId: CRYPT_ERR_FILE_IS_DIRECTORY
//
// MessageText:
//
//  The file specified is a directory.
//
#define CRYPT_ERR_FILE_IS_DIRECTORY      ((ULONG)0xE807000DL)

//
// MessageId: CRYPT_ERR_DATA_READ_ERROR
//
// MessageText:
//
//  A read request to load a buffer read less data than was supplied.
//
#define CRYPT_ERR_DATA_READ_ERROR        ((ULONG)0xE807000EL)

//
// MessageId: CRYPT_ERR_IN_TRANSITION
//
// MessageText:
//
//  Unable to load archive - marked as in-transition.
//
#define CRYPT_ERR_IN_TRANSITION          ((ULONG)0xE807000FL)

//
// MessageId: CRYPT_ERR_ITEM_NOT_FOUND
//
// MessageText:
//
//  A requested item could not be found.
//
#define CRYPT_ERR_ITEM_NOT_FOUND         ((ULONG)0xE8070010L)

//
// MessageId: CRYPT_ERR_UNSUPPORTED_DRIVE
//
// MessageText:
//
//  File repository is supported only on local, fixed disk drive.
//
#define CRYPT_ERR_UNSUPPORTED_DRIVE      ((ULONG)0xE8070011L)

//
// MessageId: CRYPT_ERR_DIRECTORY_IS_FILE
//
// MessageText:
//
//  Unable to create/open file respository because a file exists with the required directory name.
//
#define CRYPT_ERR_DIRECTORY_IS_FILE      ((ULONG)0xE8070012L)

//
// MessageId: CRYPT_ERR_INVALID_STREAM_VERSION
//
// MessageText:
//
//  Unable to load a file repository index because the file version is not compatible with this software.
//
#define CRYPT_ERR_INVALID_STREAM_VERSION ((ULONG)0xE8070013L)

//
// MessageId: CRYPT_ERR_VAULT_LOCKED
//
// MessageText:
//
//  The vault is locked!  You must unlock the vault before this operation can succeed.
//
#define CRYPT_ERR_VAULT_LOCKED           ((ULONG)0xE8070014L)

//
// MessageId: CRYPT_ERR_WRONG_PASSPHRASE
//
// MessageText:
//
//  The vault is still locked - the pass-phrase supplied was not correct.
//
#define CRYPT_ERR_WRONG_PASSPHRASE       ((ULONG)0xE8070015L)

//
// MessageId: CRYPT_ERR_NO_VAULT_PASSWORD
//
// MessageText:
//
//  The vault cannot be locked - the pass-phrase has not been set.
//
#define CRYPT_ERR_NO_VAULT_PASSWORD      ((ULONG)0xE8070016L)

//
// MessageId: CRYPT_ERR_CANCELLED
//
// MessageText:
//
//  The operation was cancelled by the user.
//
#define CRYPT_ERR_CANCELLED              ((ULONG)0xE8070017L)

#endif
// End of CryptErr.h
