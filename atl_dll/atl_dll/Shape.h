// Shape.h : Declaration of the CShape

#pragma once
#include "resource.h"       // main symbols

#include "atl_dll_i.h"
#include "_IShapeEvents_CP.h"




// CShape

class ATL_NO_VTABLE CShape :
	public CComObjectRootEx<CComMultiThreadModel>,
	public CComCoClass<CShape, &CLSID_Shape>,
	public ISupportErrorInfo,
	public IConnectionPointContainerImpl<CShape>,
	public CProxy_IShapeEvents<CShape>,
	public IDispatchImpl<IShape, &IID_IShape, &LIBID_atl_dllLib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	CShape()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_SHAPE)

DECLARE_NOT_AGGREGATABLE(CShape)

BEGIN_COM_MAP(CShape)
	COM_INTERFACE_ENTRY(IShape)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(ISupportErrorInfo)
	COM_INTERFACE_ENTRY(IConnectionPointContainer)
END_COM_MAP()

BEGIN_CONNECTION_POINT_MAP(CShape)
	CONNECTION_POINT_ENTRY(__uuidof(_IShapeEvents))
END_CONNECTION_POINT_MAP()
// ISupportsErrorInfo
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid);


	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease()
	{
	}

public:
  HRESULT _stdcall Draw ();
};

OBJECT_ENTRY_AUTO(__uuidof(Shape), CShape)
