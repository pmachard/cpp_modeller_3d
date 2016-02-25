#pragma once

#include "stdafx.h"
#include <ostream>
#include <map>
#include <array>
#include <string>

#include "Face.h"

using namespace prj::math;
using namespace std;

namespace prj {
	namespace modeller {

		class FacesObject
		{
		private:
			static long m_InternalId;
			static map<long, FacesObject*> m_mapIdToFacesObject;

		private:
			long m_Id;
			int m_nbrFace;
			string m_Label;
			array<Face *, 6> m_ArrayFace;

		public:
			static long IncId(FacesObject * pFaceObject)
			{
				m_InternalId++;
				m_mapIdToFacesObject.insert(pair<long, FacesObject*>(m_InternalId, pFaceObject));
				return m_InternalId;
			};

			static long Id(void) { return m_InternalId; };

			static const FacesObject & GetWithId(long id)
			{
				map<long, FacesObject*>::iterator itFind = m_mapIdToFacesObject.find(id);
				return *(itFind->second);
			}

			FacesObject(void)
			{
				m_nbrFace = 0;
				m_Label = "";
				m_Id = IncId(this);
			}

			FacesObject(string label)
			{
				m_nbrFace = 0;
				m_Label = label;
				m_Id = IncId(this);
			}

			FacesObject(const FacesObject & paramFacesObject)
			{
				m_nbrFace = 0;
				m_Label = paramFacesObject.m_Label;
				m_Id = IncId(this);
			}

			void Add(Face * ptFace)
			{
				m_ArrayFace[m_nbrFace] = ptFace;
				m_nbrFace++;
			}

			inline long GetId(void) const
			{
				return m_Id;
			};

			inline const string & GetLabel(void) const
			{
				return m_Label;
			};

			inline const Face & GetFace(long pos) const
			{
				return (*m_ArrayFace[pos]);
			}

			inline Face & GetFace(long pos)
			{
				return (*m_ArrayFace[pos]);
			}

			friend std::ostream & operator<< (std::ostream & paramOutput, const FacesObject & paramFacesObject)
			{
				paramOutput << "<FACESOBJECT>";
				paramOutput << "<ID>" << paramFacesObject.GetId() << "</ID>";
				paramOutput << "<LABEL>" << paramFacesObject.GetLabel() << "</LABEL>";
				paramOutput << "<FACES>";

				long iPos = 0;
				while (iPos < paramFacesObject.m_nbrFace)
				{
					paramOutput << paramFacesObject.GetFace(iPos);
					iPos++;
				}
				paramOutput << "</FACES>";

				paramOutput << "</FACESOBJECT>";
				return paramOutput;
			}

		};
	}
}
