#include "stdafx.h"

//#include <map>

#include "FilterPointsClass.h"

//////////////////////////////////////////////////
CFilterPoints::CFilterPoints ()
  {
  m_dTolerance = 0;
  }
//////////////////////////////////////////////////
CFilterPoints::CFilterPoints (double dTolerance)
  {
  m_dTolerance = dTolerance;
  }
//////////////////////////////////////////////////
void CFilterPoints::InsPoint (CPoint3D *pPoint3D)
  {
  m_Point3d.push_back (*pPoint3D);
//  m_PointX.insert (pPoint3D->m_dX);
//  m_PointY.insert (pPoint3D->m_dY);
//  m_PointZ.insert (pPoint3D->m_dZ);
  }
//////////////////////////////////////////////////
bool CFilterPoints::InsPoint (CPoint3D *pPoint3D, double dTollerance)
  {
  bool bSuccess (false);

  if (m_Point3d_filtred.empty ())
    {
    m_Point3d_filtred.push_back (*pPoint3D);
    bSuccess = true;
    }
  else
    {
    std::vector<CPoint3D>::iterator iter;
    for (iter = m_Point3d_filtred.begin (); iter != m_Point3d_filtred.end (); iter++)
      {
      if (FindNearestPoint (*pPoint3D, dTollerance))
        {
        m_Point3d_filtred.push_back (*pPoint3D);
        bSuccess = true;
        break;
        }
      }
    }
  return bSuccess;
  }
//////////////////////////////////////////////////
bool CFilterPoints::AddPoint (CPoint3D *pPoint3D, double dTollerance)
  {
  bool bSuccess (false);

  if (m_Point3d_filtred.empty ())
    {
    m_Point3d_filtred.push_back (*pPoint3D);
    bSuccess = true;
    }
  else
    {
    std::vector<CPoint3D>::iterator iter;
    for (iter = m_Point3d_filtred.begin (); iter != m_Point3d_filtred.end (); iter++)
      {
      if (FindNearestPoint (*pPoint3D, dTollerance))
        {
        m_Point3d_filtred.push_back (*pPoint3D);
        bSuccess = true;
        break;
        }
      }
    }
  return bSuccess;
  }
//////////////////////////////////////////////////
//CPoint3D& CFilterPoints::GetPoint (int nPointNum)
//  {
//  return (CPoint3D());
//  }
//////////////////////////////////////////////////
void CFilterPoints::DelAllFilteredPoints ()
  {
  m_Point3d_filtred.clear ();
  }
//////////////////////////////////////////////////
std::vector<CPoint3D>& CFilterPoints::GetFilteredPoints ()
  {
  return (m_Point3d_filtred);
  }
//////////////////////////////////////////////////
//void CFilterPoints::DelPoint (int nPointNum)
//  {
//  if (nPointNum > (Size () - 1))
//    return;
//  else
//    {
//    //std::set<CPoint3D, std::less<CPoint3D> >::iterator iter = nPointNum;
//    std::set<CPoint3D>::iterator iter = m_Point3d_filtred.begin ();
//    iter =+nPointNum;
//    m_Point3d_filtred.erase (iter);
//    }
//  }
//////////////////////////////////////////////////
int CFilterPoints::Size ()
  {
  return (m_Point3d_filtred.size ());
  }
//////////////////////////////////////////////////
bool CFilterPoints::FilterPoints ()
  {
  bool bSuccess (false);

  std::vector<CPoint3D>::iterator iter;
  for (iter = m_Point3d.begin (); iter != m_Point3d.end (); iter++)
    {
    if (m_Point3d_filtred.empty ())
      m_Point3d_filtred.push_back (*m_Point3d.begin ());

    if (FindNearestPoint (*iter, m_dTolerance))
      {
      m_Point3d_filtred.push_back (*iter);
      }
    }
  return bSuccess;
  }
//////////////////////////////////////////////////
bool CFilterPoints::FindNearestPoint (CPoint3D &pPt, double dTolerance)
  {
  bool bSuccess (false);
  CPoint3D Pt2;
  double dX, dY, dZ;
  for (std::vector <CPoint3D>::iterator iter = m_Point3d_filtred.begin (); iter != m_Point3d_filtred.end (); iter++)
    {
    iter->Get (dX, dY, dZ);
    Pt2.Set (dX, dY, dZ);
    if (!CheckSqDistance (&pPt, &Pt2, dTolerance))
      {
      bSuccess = true;
      break;
      }
    }
  return bSuccess;
  }
//////////////////////////////////////////////////
bool CFilterPoints::CheckSqDistance (CPoint3D *pPt1, CPoint3D *pPt2, double dTolerance)
  {
  bool bFound (false);
  if (pPt1->SqDistance (*pPt2) <= dTolerance * dTolerance)
    bFound = true;
  return bFound;
  };
//////////////////////////////////////////////////
void CFilterPoints::GetFilteredPoints (std::vector <CPoint3D> &ptFiltered)
  {
  ptFiltered = m_Point3d_filtred;
  }