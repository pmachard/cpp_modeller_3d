#pragma once

#include "stdafx.h"
#include <ostream>
#include <map>
#include <array>
#include <string>

#include "Edge.h"

using namespace prj::math;
using namespace std;

namespace prj {
	namespace modeller {

		class Face
		{
		private:
			static long m_InternalId;
			static map<long, Face*> m_mapIdToFace;

		private:
			long m_Id;
			int m_nbrEdge;
			string m_Label;
			array<Edge *,5> m_ArrayEdge;

		public:
			static long IncId(Face * pFace)
			{
				m_InternalId++;
				m_mapIdToFace.insert(pair<long, Face*>(m_InternalId, pFace));
				return m_InternalId;
			};

			static long Id(void) { return m_InternalId; };

			static const Face & GetWithId(long id)
			{
				map<long, Face*>::iterator itFind = m_mapIdToFace.find(id);
				return *(itFind->second);
			}

			Face(void)
			{
				m_nbrEdge = 0;
				m_Label = "";
				m_Id = IncId(this);
			}

			Face(string label)
			{
				m_nbrEdge = 0;
				m_Label = label;
				m_Id = IncId(this);
			}

			Face(const Face & paramFace)
			{
				m_nbrEdge = 0;
				m_Label = paramFace.m_Label;
				m_Id = IncId(this);
			}

			void Add(Edge * ptEdge)
			{
				m_ArrayEdge[m_nbrEdge] = ptEdge;
				m_nbrEdge++;
			}

			inline long GetId(void) const
			{
				return m_Id;
			};

			inline const string & GetLabel(void) const
			{
				return m_Label;
			};

			inline const Edge & GetEdge(long pos) const
			{
				return (*m_ArrayEdge[pos]);
			}

			inline Edge & GetEdge(long pos)
			{
				return (*m_ArrayEdge[pos]);
			}

			friend std::ostream & operator<< (std::ostream & paramOutput, const Face & paramFace)
			{
				
				paramOutput << "<FACE>";
				paramOutput << "<ID>" << paramFace.GetId() << "</ID>";
				paramOutput << "<LABEL>" << paramFace.GetLabel() << "</LABEL>";
				paramOutput << "<EDGES>";

				long iPos = 0;
				while (iPos < paramFace.m_nbrEdge)
				{
					paramOutput << paramFace.GetEdge(iPos) ;
					iPos++;
				}
				paramOutput << "</EDGES>";

				paramOutput << "</FACE>";
				return paramOutput;
			}

		};
	}
}
