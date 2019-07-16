#pragma once

#include "ChildFrm.h"
#include "ShapeFilter.h"

// Global type definitions
  	enum ColorsNumber{INDEXED,THOUSANDS,MILLIONS,MILLIONS_WITH_TRANSPARENCY};
  	enum ZAccuracy{NORMAL,ACCURATE};

class CChildOGLFrame: public CChildFrame //CChildView
  {
  DECLARE_DYNCREATE(CChildOGLFrame);
  public:
    CChildOGLFrame ();
    virtual bool bSetupPixelFormat ();
//    virtual void OnDrawGL(); // override to issue drawing functions
  	virtual void VideoMode(ColorsNumber &c,ZAccuracy &z,BOOL &dbuf); // override to specify some video mode parameters
//    virtual void DrawGL ();
    virtual int InitGraphics ();

  private:
    CDC* m_pCDC;	// WinGDI Device Context
    HGLRC m_hRC;	// OpenGL Rendering Context

    CShapeFilter m_ShapeFilter;
    std::vector<CPoint3D> m_Point3dSet;
    //intm_ShapeFilter.Scale (nScale);

  private:
  	//{{AFX_MSG(CGLEnabledView)
  		afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
      afx_msg void OnPaint ();
  		afx_msg void OnDestroy();
  		afx_msg void OnSize(UINT nType, int cx, int cy);
      afx_msg void OnActivate (UINT nState, CWnd* pWndOther, BOOL bMinimized);
      afx_msg void OnSizing (UINT fwSide, LPRECT pRect);
      afx_msg void OnMove (int x, int y);
      afx_msg void OnClose ();
  	//}}AFX_MSG
    DECLARE_MESSAGE_MAP()
  };