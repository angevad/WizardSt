// dllmain.h : Declaration of module class.

class Catl_dllModule : public CAtlDllModuleT< Catl_dllModule >
{
public :
	DECLARE_LIBID(LIBID_atl_dllLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_ATL_DLL, "{3CD0F8E4-C658-4C42-AD21-F176734E3BC8}")
};

extern class Catl_dllModule _AtlModule;
