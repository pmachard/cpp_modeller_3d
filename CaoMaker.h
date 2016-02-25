#pragma once

#include "stdafx.h"
#include "Edge.h"
#include "FacesObject.h"
#include <ostream>
#include <string>
#include <array>

using namespace prj::math;
using namespace prj::modeller;
using namespace std;

namespace prj {
	namespace cao {

		class CaoMaker
		{
		public :
			static FacesObject * MakeBox(string label, Vertice origine, double wide, double length, double height)
			{
				FacesObject * result = new FacesObject(label);

				Vector3d<double> p000(0.0, 0.0, 0.0);
				Vector3d<double> p100(wide, 0.0, 0.0);
				Vector3d<double> p110(wide, length, 0.0);
				Vector3d<double> p010(0, length, 0.0);
				Vector3d<double> p001(0.0, 0.0, height);
				Vector3d<double> p101(wide, 0.0, height);
				Vector3d<double> p111(wide, length, height);
				Vector3d<double> p011(0, length, height);

				Vertice * v000 = new Vertice(p000, "V 0 0 0");
				Vertice * v100 = new Vertice(p100, "V 1 0 0");
				Vertice * v110 = new Vertice(p110, "V 1 1 0");
				Vertice * v010 = new Vertice(p010, "V 0 1 0");
				Vertice * v001 = new Vertice(p001, "V 0 0 0");
				Vertice * v101 = new Vertice(p101, "V 1 0 0");
				Vertice * v111 = new Vertice(p111, "V 1 1 0");
				Vertice * v011 = new Vertice(p011, "V 0 1 0");

				Face * ptFace1 = new Face("Face below");
				ptFace1->Add(new Edge(v000, v100, "000-100"));
				ptFace1->Add(new Edge(v100, v110, "100-110"));
				ptFace1->Add(new Edge(v110, v010, "110-010"));
				ptFace1->Add(new Edge(v010, v000, "010-000"));
				result->Add(ptFace1);

				Face * ptFace2 = new Face("Face above");
				ptFace2->Add(new Edge(v001, v101, "001-101"));
				ptFace2->Add(new Edge(v101, v111, "101-111"));
				ptFace2->Add(new Edge(v111, v011, "111-011"));
				ptFace2->Add(new Edge(v011, v001, "011-001"));
				result->Add(ptFace2);

				return result;
			}
		};
	}
}		
