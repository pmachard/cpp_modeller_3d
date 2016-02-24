#include "stdafx.h"
#include <map>

#include "Edge.h"

using namespace prj::modeller;

long Edge::m_InternalId = 0;
map<long, Edge*> Edge::m_mapIdToEdge;
