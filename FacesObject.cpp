#include "stdafx.h"
#include <map>
#include <list>

#include "FacesObject.h"

using namespace prj::modeller;

long FacesObject::m_InternalId = 0;
map<long, FacesObject*> FacesObject::m_mapIdToFacesObject;

