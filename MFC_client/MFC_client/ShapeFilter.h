#include <vector>

#include "FilterPointsClass.h"

class CShapeFilter: public CFilterPoints
  {
  public:
    virtual float GetShapeScale (int nIndex);
    virtual void  AddShapeScale (float fValue);
    virtual bool  InsPoint      (CPoint3D *pPoint3D, double dTollerance);
    virtual bool  AddPoint      (CPoint3D *pPoint3D, double dTollerance);
  //protected:
    //std::set<std::pair<CPoint3D, int> > m_Point3dSet;
    std::vector<float> m_vfShapeScale;
  };