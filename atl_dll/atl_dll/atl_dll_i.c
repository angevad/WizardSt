

/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


 /* File created by MIDL compiler version 7.00.0500 */
/* at Mon Aug 08 03:34:38 2011
 */
/* Compiler settings for .\atl_dll.idl:
    Oicf, W1, Zp8, env=Win32 (32b run)
    protocol : dce , ms_ext, c_ext, robust
    error checks: stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
//@@MIDL_FILE_HEADING(  )

#pragma warning( disable: 4049 )  /* more than 64k source lines */


#ifdef __cplusplus
extern "C"{
#endif 


#include <rpc.h>
#include <rpcndr.h>

#ifdef _MIDL_USE_GUIDDEF_

#ifndef INITGUID
#define INITGUID
#include <guiddef.h>
#undef INITGUID
#else
#include <guiddef.h>
#endif

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        DEFINE_GUID(name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8)

#else // !_MIDL_USE_GUIDDEF_

#ifndef __IID_DEFINED__
#define __IID_DEFINED__

typedef struct _IID
{
    unsigned long x;
    unsigned short s1;
    unsigned short s2;
    unsigned char  c[8];
} IID;

#endif // __IID_DEFINED__

#ifndef CLSID_DEFINED
#define CLSID_DEFINED
typedef IID CLSID;
#endif // CLSID_DEFINED

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        const type name = {l,w1,w2,{b1,b2,b3,b4,b5,b6,b7,b8}}

#endif !_MIDL_USE_GUIDDEF_

MIDL_DEFINE_GUID(IID, IID_IShape,0x87DDE61E,0x1854,0x4C2D,0x80,0x25,0x0E,0xFB,0x4B,0x39,0x62,0x13);


MIDL_DEFINE_GUID(IID, LIBID_atl_dllLib,0xE87B1BBC,0x63DB,0x472A,0x81,0xE5,0x62,0x22,0x60,0xCF,0x33,0x94);


MIDL_DEFINE_GUID(IID, DIID__IShapeEvents,0xC4D0860E,0xB433,0x41C6,0x88,0x74,0xF5,0x45,0x77,0x9C,0x94,0xC2);


MIDL_DEFINE_GUID(CLSID, CLSID_Shape,0xC075FFC0,0xAD98,0x4B01,0xA8,0xF1,0x59,0x28,0x1A,0xCD,0x07,0x11);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif



