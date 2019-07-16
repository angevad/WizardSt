

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


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


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __atl_dll_i_h__
#define __atl_dll_i_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IShape_FWD_DEFINED__
#define __IShape_FWD_DEFINED__
typedef interface IShape IShape;
#endif 	/* __IShape_FWD_DEFINED__ */


#ifndef ___IShapeEvents_FWD_DEFINED__
#define ___IShapeEvents_FWD_DEFINED__
typedef interface _IShapeEvents _IShapeEvents;
#endif 	/* ___IShapeEvents_FWD_DEFINED__ */


#ifndef __Shape_FWD_DEFINED__
#define __Shape_FWD_DEFINED__

#ifdef __cplusplus
typedef class Shape Shape;
#else
typedef struct Shape Shape;
#endif /* __cplusplus */

#endif 	/* __Shape_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IShape_INTERFACE_DEFINED__
#define __IShape_INTERFACE_DEFINED__

/* interface IShape */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IShape;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("87DDE61E-1854-4C2D-8025-0EFB4B396213")
    IShape : public IDispatch
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Draw( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IShapeVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IShape * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IShape * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IShape * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IShape * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IShape * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IShape * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IShape * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        HRESULT ( STDMETHODCALLTYPE *Draw )( 
            IShape * This);
        
        END_INTERFACE
    } IShapeVtbl;

    interface IShape
    {
        CONST_VTBL struct IShapeVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IShape_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IShape_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IShape_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IShape_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IShape_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IShape_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IShape_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IShape_Draw(This)	\
    ( (This)->lpVtbl -> Draw(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IShape_INTERFACE_DEFINED__ */



#ifndef __atl_dllLib_LIBRARY_DEFINED__
#define __atl_dllLib_LIBRARY_DEFINED__

/* library atl_dllLib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_atl_dllLib;

#ifndef ___IShapeEvents_DISPINTERFACE_DEFINED__
#define ___IShapeEvents_DISPINTERFACE_DEFINED__

/* dispinterface _IShapeEvents */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID__IShapeEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("C4D0860E-B433-41C6-8874-F545779C94C2")
    _IShapeEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _IShapeEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _IShapeEvents * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _IShapeEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _IShapeEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _IShapeEvents * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _IShapeEvents * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _IShapeEvents * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _IShapeEvents * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } _IShapeEventsVtbl;

    interface _IShapeEvents
    {
        CONST_VTBL struct _IShapeEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _IShapeEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _IShapeEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _IShapeEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _IShapeEvents_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _IShapeEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _IShapeEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _IShapeEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___IShapeEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_Shape;

#ifdef __cplusplus

class DECLSPEC_UUID("C075FFC0-AD98-4B01-A8F1-59281ACD0711")
Shape;
#endif
#endif /* __atl_dllLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


