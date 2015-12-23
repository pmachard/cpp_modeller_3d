#pragma once

namespace prj {
	namespace modeller {
			
		template <typename T> class Vectice : Vector3D<T>
		{
		private:
			long m_Id;
			static long m_InternalId = 0;
		public:
			Vectice<T>(void) : Vector3D<T> ()
			{
				m_Id = m_InternalId++;
			}
			
			Vectice<T>(const Vectice<T> & paramVertice) : Vector3D<T>(paramVertice)
			{
				m_Id = m_InternalId++;
			}
			
			inline long GetId(void) { return m_Id;};
		};
	}
}
