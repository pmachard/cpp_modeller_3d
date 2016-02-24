#include "stdafx.h"

#include <map>

#include "Vertice.h"

using namespace prj::modeller;

long Vertice::m_InternalId = 0;
map<long, Vertice*> Vertice::m_mapIdToVertice;
