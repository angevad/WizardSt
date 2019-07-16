#include "stdafx.h"

#include "ShapeFilter.h"

//CShapeFilter::CShapeFilter ()
//  {
//  }
//std::set<std::pair<CPoint3D, int> >& CShapeFilter::GetFilteredPoints ()
//  {
//  m_Point3dSet[0].first;
//  return (m_Point3d_filtred);
//  }

float CShapeFilter::GetShapeScale (int nIndex)
  {
  if ((UINT)nIndex < m_vfShapeScale.size ())
    return (m_vfShapeScale.operator [](nIndex));
  else
    return 1;
  }

void CShapeFilter::AddShapeScale (float fValue)
  {
  m_vfShapeScale.push_back (fValue);
  }

bool CShapeFilter::InsPoint (CPoint3D *pPoint3D, double dTollerance)
  {
  bool bSuccess (false);
  if (CFilterPoints::InsPoint (pPoint3D, dTollerance))
    {
    m_vfShapeScale.push_back ((float)dTollerance);
//    if (m_vfShapeScale.size () != Size ())
//      assert (false);
    bSuccess = true;
    }
  return (bSuccess);
  }

bool CShapeFilter::AddPoint (CPoint3D *pPoint3D, double dTollerance)
  {
  bool bSuccess (false);
  if (CFilterPoints::AddPoint (pPoint3D, dTollerance))
    {
    m_vfShapeScale.push_back ((float)dTollerance);
//    if (m_vfShapeScale.size () != Size ())
//      assert (false);
    bSuccess = true;
    }
  return (bSuccess);
  }
