// Exp10.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <stack>

#include "Matrix.h"
#include "VectorXd.h"
#include "Vertice.h"
#include "Edge.h"
#include "CaoMaker.h"

using namespace prj;
using namespace prj::math;
using namespace prj::modeller;
using namespace prj::cao;

int _tmain(int argc, _TCHAR* argv[])
{

	Vector3d<double> po(0.0,0.0,0.0);
	Vector3d<double> px(1.0, 0.0, 0.0);
	Vector3d<double> py(0.0, 1.0, 0.0);
	Vector3d<double> pz(0.0, 0.0, 1.0);

	cout << "\nValid Create vector\n";
	cout << "po:" << po << "\n";
	cout << "px:" << px << "\n";
	cout << "py:" << py << "\n";
	cout << "pz:" << pz << "\n";

	cout << "\nValid Create vertice\n";
	Vertice vo(po, "Origine");
	Vertice vx(px, "V X");
	Vertice vy(py, "V Y");
	Vertice vz(pz, "V Z");

	cout << vo << "\n";
	cout << vx << "\n";
	cout << vy << "\n";
	cout << vz << "\n";

	cout << "\nValid VerticeMaker::GetWithId \n";
	cout << Vertice::GetWithId(1) << "\n";
	cout << Vertice::GetWithId(2) << "\n";
	cout << Vertice::GetWithId(3) << "\n";
	cout << Vertice::GetWithId(4) << "\n";

	cout << "\nValid Create Edge \n";
	Edge hox(vo.GetId(), vx.GetId(), "Vector O->X");
	Edge hoy(vo.GetId(), vy.GetId(), "Vector O->Y");
	Edge hoz(vo.GetId(), vz.GetId(), "Vector O->Z");
	cout << hox << "\n";
	cout << hoy << "\n";
	cout << hoz << "\n";

	cout << "\nValid CaoMaker::MakeBox \n";
	CaoMaker::MakeBox("Box 01", vo, 1.0, 1.0, 1.0);

	return 0;
}


