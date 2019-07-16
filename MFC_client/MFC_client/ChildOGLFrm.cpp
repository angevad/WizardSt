#include "stdafx.h"

#include "ChildOGLFrm.h"
//#include "ShapeFilter.h"

#include "afxwin.h"
#include <windows.h>
#include <gl/gl.h>
#include <gl/glu.h>
#include "glaux.h"

IMPLEMENT_DYNCREATE(CChildOGLFrame, CMDIChildWndEx)

BEGIN_MESSAGE_MAP(CChildOGLFrame, CChildFrame)
	ON_COMMAND(ID_FILE_CLOSE, &CChildOGLFrame::OnFileClose)
	ON_WM_SETFOCUS()
	ON_WM_CREATE()
  ON_WM_PAINT ()
  ON_WM_SIZE ()
  ON_WM_SIZING ()
  ON_WM_TIMER ()
  ON_WM_CLOSE ()
END_MESSAGE_MAP()

CChildOGLFrame::CChildOGLFrame ()
  {
  m_pCDC = NULL;
  }

int CChildOGLFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
  {
  if (CChildFrame::OnCreate (lpCreateStruct) == -1) return -1;

  //Initilize OpenGL
  InitGraphics ();

  return 0;
  }

// Initialize OpenGL graphics
int CChildOGLFrame::InitGraphics()
  {
  int nSucceded (1);

  m_pCDC = new CClientDC (this);
  if (!bSetupPixelFormat ())
    {   
    nSucceded = -1;
    return (nSucceded);
    }

  m_hRC = wglCreateContext (m_pCDC->GetSafeHdc ());
  wglMakeCurrent (m_pCDC->GetSafeHdc (), m_hRC);

  glClearColor(0, 0, 0, 1);
  glShadeModel (GL_SMOOTH);
  glClearDepth(1.0);
  glEnable(GL_DEPTH_TEST);
  glDepthFunc (GL_LEQUAL);

//  glEnable (GL_TEXTURE_2D);
//  glDisable (GL_COLOR);
  glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

  return nSucceded;
  }

bool CChildOGLFrame::bSetupPixelFormat()
  {
  // define a default desired video mode (pixel format)
  	PIXELFORMATDESCRIPTOR pfd = 
  	{
          sizeof(PIXELFORMATDESCRIPTOR),	// size of this pfd
          1,								// version number
          PFD_DRAW_TO_WINDOW |			// support window
          PFD_SUPPORT_OPENGL |			// support OpenGL
          PFD_DOUBLEBUFFER ,				// double buffered
          PFD_TYPE_RGBA,                  // RGBA type
          24,                             // 24-bit color depth
          0, 0, 0, 0, 0, 0,               // color bits ignored
          0,                              // no alpha buffer
          0,                              // shift bit ignored
          0,                              // no accumulation buffer
          0, 0, 0, 0,                     // accum bits ignored
          16,                             // 16-bit z-buffer
          0,                              // no stencil buffer
          0,                              // no auxiliary buffer
          PFD_MAIN_PLANE,                 // main layer
          0,                              // reserved
          0, 0, 0                         // layer masks ignored
      };
  // let the user change some parameters if he wants
  	BOOL bDoublBuf;
  	ColorsNumber cnum;
  	ZAccuracy zdepth;
  	VideoMode(cnum,zdepth,bDoublBuf);
  //set the user changes
  	if(bDoublBuf) pfd.dwFlags=PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL |PFD_DOUBLEBUFFER;
  	else pfd.dwFlags=PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL;
  	switch(cnum)
  	{
  	case INDEXED:
  		pfd.cColorBits=8;
  		pfd.iPixelType=PFD_TYPE_COLORINDEX;
  		break;
  	case THOUSANDS:
  		pfd.cColorBits=16;
  		break;
  	case MILLIONS_WITH_TRANSPARENCY:
  		pfd.cColorBits=32;
  		break;
  	case MILLIONS:
  	default:
  		pfd.cColorBits=24;
  		break;
  	};
  	switch(zdepth)
  	{
  	case NORMAL:
  		pfd.cDepthBits=16;
  		break;
  	case ACCURATE:
  		pfd.cDepthBits=32;
  		break;
  	};
  
  // ask the system for such video mode
      ASSERT(m_pCDC != NULL);
      int pixelformat;
  	if ( (pixelformat = ChoosePixelFormat(m_pCDC->GetSafeHdc(), &pfd)) == 0 )
      {
      AfxMessageBox(_T("ChoosePixelFormat failed"));
          return FALSE;
      }
  // try to set this video mode    
  	if (SetPixelFormat(m_pCDC->GetSafeHdc(), pixelformat, &pfd) == FALSE)
      {
  // the requested video mode is not available so get a default one (the first)
          pixelformat = 1;	
  		if (DescribePixelFormat(m_pCDC->GetSafeHdc(), pixelformat, sizeof(PIXELFORMATDESCRIPTOR), &pfd)==0)
  		{
  // neither the requested nor the default are available: fail
  			AfxMessageBox(_T("SetPixelFormat failed (no OpenGL compatible video mode)"));
  			return FALSE;
  		}
      }
      return TRUE;
  }

void CChildOGLFrame::OnDestroy() 
  {
  wglDeleteContext (m_hRC); 
  // destroy Win Device Context 
  if(m_pCDC) delete m_pCDC;
  
  // finally call the base function
  CChildFrame::OnDestroy();	
  }

void CChildOGLFrame::VideoMode(ColorsNumber &c, ZAccuracy &z, BOOL &dbuf)
  {
  // set default videomode
  	c=MILLIONS;
  	z=NORMAL;
  	dbuf=TRUE;
  }

void CChildOGLFrame::OnSize(UINT nType, int cx, int cy) 
  {
  CChildFrame::OnSize(nType, cx, cy);

  // Get new window size
    RECT rect;
	  int width, height;
	  GLfloat aspect;

    GetClientRect (&rect);
    width = rect.right;
    height = rect.bottom;
    aspect = (GLfloat)width / height;

    // Adjust graphics to window size
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, aspect, 1.0, 1000.0);
    glMatrixMode(GL_MODELVIEW);
  }

//void CChildOGLFrame::OnDrawGL()
//  {
//  DrawGL ();
//  }
//
//void CChildOGLFrame::DrawGL ()
//  {
//  
//  }

void CChildOGLFrame::OnPaint ()
  {
  //CChildFrame::OnPaint ();

  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  // Set location in front of camera
  glLoadIdentity();

  RECT rect;
  GetClientRect (&rect);

  long lWndX = rect.right / 2;
  long lWndY = rect.bottom / 2;
  glTranslated(0, 0, -300);

  if ((rect.right != 0) || (rect.bottom != 0))
    {
    int nXRand = rand () % rect.right;
    int nYRand = rand () % rect.bottom;
    float fScale = (float)(rand () % 10);

    if (m_ShapeFilter.AddPoint (&CPoint3D (nXRand, nYRand, 0), fScale))
      {
      m_Point3dSet = m_ShapeFilter.GetFilteredPoints ();
      }

    int n(0);
    GLfloat glfScale;
    for (std::vector<CPoint3D>::iterator iter = m_Point3dSet.begin (); iter != m_Point3dSet.end (); iter++, n++)
      {
      glfScale = m_ShapeFilter.GetShapeScale (n);
      glPushMatrix ();
        {
        glTranslated (iter->GetX () - (double)lWndX, iter->GetY () - (double)lWndY, 0);
        glScalef (glfScale, glfScale, 0);
        glColor3d (0.0, 1.0, 0.0);
        glBegin (GL_TRIANGLES);
          {
          glVertex3d (0, 0, 0);
          glVertex3d (1,0,0);
          glVertex3d (0,1,0);
          }
        glEnd ();
        }
      glPopMatrix ();
      }
    }
  SwapBuffers(m_pCDC->GetSafeHdc ());
  }

void CChildOGLFrame::OnSizing (UINT fwSide, LPRECT pRect)
  {
  CChildFrame::OnSizing (fwSide, pRect);

  RECT rect;
	int width, height;
	GLfloat aspect;

  GetClientRect (&rect);

  width = rect.right;
  height = rect.bottom;
  aspect = (GLfloat)width / height;

  // Adjust graphics to window size
  glViewport(0, 0, width, height);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(45.0, aspect, 1.0, 1000.0);
  glMatrixMode(GL_MODELVIEW);
  OnPaint ();
  }

void CChildOGLFrame::OnMove (int x, int y)
  {
  CChildFrame::OnMove (x, y);
  OnPaint ();
  }

void CChildOGLFrame::OnClose()
  {
  OnDestroy ();
  }