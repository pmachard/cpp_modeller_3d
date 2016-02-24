#pragma once

#include "stdafx.h"

#include <ostream>
#include <map>
#include <string>

#include "Vertice.h"

using namespace prj::math;
using namespace std;

namespace prj {
	namespace modeller {

		class Edge
		{
		private:
			static long m_InternalId;
			static map<long, Edge*> m_mapIdToEdge;

			long m_Id;
			long m_Va;
			long m_Vb;
			string m_Label;

		public:
			static long IncId(Edge * pEdge)
			{
				m_InternalId++;
				m_mapIdToEdge.insert(pair<long, Edge*>(m_InternalId, pEdge));
				return m_InternalId;
			};

			static long Id(void) { return m_InternalId; };

			static const Edge & GetWithId(long id)
			{
				map<long, Edge*>::iterator itFind = m_mapIdToEdge.find(id);
				return *(itFind->second);
			}

			Edge(void) 
			{
				m_Label = "";
				m_Id = IncId(this);
			}

			Edge(long vaId, long vbId,string label)
			{
				m_Va = vaId;
				m_Vb = vbId;
				m_Label = label;
				m_Id = IncId(this);
			}

			Edge(const Edge & paramEdge)
			{
				m_Va = paramEdge.m_Va;
				m_Va = paramEdge.m_Vb;
				m_Label = paramEdge.m_Label;
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

			inline const Vertice & GetA(void) const 
			{ 
				return Vertice::GetWithId(m_Va); 
			};

			inline const Vertice & GetB(void) const 
			{ 
				return Vertice::GetWithId(m_Vb); 
			};

			inline Vertice & GetA(void) 
			{ 
				return Vertice::GetWithId(m_Va); 
			};

			inline Vertice & GetB(void) 
			{ 
				return Vertice::GetWithId(m_Vb); 
			};

			friend std::ostream & operator<< (std::ostream & paramOutput, const Edge & paramEdge)
			{
				paramOutput << "(Id:" << paramEdge.GetId() << ";";
				paramOutput << "(label:(" << paramEdge.GetLabel() << ");";
				paramOutput << "(A:(" << paramEdge.GetA() << ");B:(" << paramEdge.GetB() << ");";
				paramOutput << ")";
				return paramOutput;
			}

		};
	}
}
