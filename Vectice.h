#pragma once
#include "stdafx.h"

#include <ostream>
#include <string>
#include <map>

#include "VectorXd.h"

using namespace prj::math;
using namespace std;

namespace prj {
	namespace modeller {

		class Vertice : public Vector3d<double>
		{
		private:
			static long m_InternalId;
			static map<long, Vertice*> m_mapIdToVertice;

			long m_Id;
			string m_Label;
		public:

			static long IncId(Vertice * pVertice)
			{
				m_InternalId++;
				m_mapIdToVertice.insert(pair<long, Vertice*>(m_InternalId, pVertice));
				return m_InternalId;
			};
			static long Id(void) { return m_InternalId; };

			static Vertice & GetWithId(long id)
			{
				map<long, Vertice*>::iterator itFind = m_mapIdToVertice.find(id);
				return *(itFind->second);
			}

			Vertice(void) : Vector3d<double>()
			{
				m_Id = IncId(this);
			}

			Vertice(const Vertice & paramVertice) : Vector3d<double>(paramVertice)
			{
				m_Label = paramVertice.m_Label;
				m_Id = IncId(this);
			}

			Vertice(const Vector3d & paramVector3D,const string label) : Vector3d<double>(paramVector3D)
			{
				m_Label = label;
				m_Id = IncId(this);
			}

			inline long GetId(void) const
			{ 
				return m_Id; 
			};

			inline const string & GetLabel(void) const
			{
				return m_Label;
			};

			friend std::ostream & operator<< (std::ostream & paramOutput, const Vertice & paramVectice)
			{
				paramOutput << "(Id:" << paramVectice.GetId() << ";";
				paramOutput << "(label:(" << paramVectice.GetLabel() << ");";
				paramOutput << "(Vector:" << (const Vector3d<double> &)paramVectice;
				paramOutput << ")";
				return paramOutput;
			}
		};
	}
}
