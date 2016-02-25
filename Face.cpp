#include "stdafx.h"
#include <map>
#include <list>

#include "Face.h"

using namespace prj::modeller;

long Face::m_InternalId = 0;
map<long, Face*> Face::m_mapIdToFace;

