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

		private:
			long m_Id;
			Vertice * m_ptVa;
			Vertice * m_ptVb;
			string m_Label;

		public:
			static long IncId(Edge * pEdge)
			{
				m_InternalId++;
				m_mapIdToEdge.insert(pair<long, Edge*>(m_InternalId, pEdge));
				return m_InternalId;
			};

			static long Id(void) 
			{ 
				return m_InternalId; 
			};

			static const Edge & GetWithId(long id)
			{
				map<long, Edge*>::iterator itFind = m_mapIdToEdge.find(id);
				return *(itFind->second);
			}

			inline Edge(void) 
			{
				m_Label = "";
				m_Id = IncId(this);
			}

			inline Edge(Vertice * ptVa, Vertice * ptVb, string label)
			{
				m_ptVa = ptVa;
				m_ptVb = ptVb;
				m_Label = label;
				m_Id = IncId(this);
			}

			inline Edge(const Edge & paramEdge)
			{
				m_ptVa = paramEdge.m_ptVa;
				m_ptVb = paramEdge.m_ptVb;
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
				return *m_ptVa; 
			};

			inline const Vertice & GetB(void) const 
			{ 
				return *m_ptVb;
			};

			inline Vertice & GetA(void) 
			{ 
				return *m_ptVa;
			};

			inline Vertice & GetB(void) 
			{ 
				return *m_ptVb;
			};

			friend std::ostream & operator<< (std::ostream & paramOutput, const Edge & paramEdge)
			{
				paramOutput << "<EDGE>";
				paramOutput << "<ID>" << paramEdge.GetId() << "</ID>";
				paramOutput << "<LABEL>" << paramEdge.GetLabel() << "</LABEL>";
				paramOutput << "<A>" << paramEdge.GetA() << "</A><B>" << paramEdge.GetB() << "</B>";
				paramOutput << "</EDGE>";
				return paramOutput;
			}
		};
	}
}
