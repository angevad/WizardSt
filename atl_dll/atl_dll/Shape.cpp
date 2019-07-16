// Shape.cpp : Implementation of CShape

#include "stdafx.h"
#include "Shape.h"


// CShape

STDMETHODIMP CShape::InterfaceSupportsErrorInfo(REFIID riid)
{
	static const IID* arr[] = 
	{
		&IID_IShape
	};

	for (int i=0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		if (InlineIsEqualGUID(*arr[i],riid))
			return S_OK;
	}
	return S_FALSE;
}

HRESULT _stdcall CShape::Draw ()
  {
  return S_OK;
  }