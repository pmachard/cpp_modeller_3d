#pragma once

namespace prj {
	namespace modeller {
			
		template <typename T> class Edge
		{
		private:
			long m_Id;
			static long m_InternalId = 0;
			Vectice m_Va;
			Vectice m_Vb;
		public:
			Edge<T>(void) : Edge<T> ()
			{
				m_Id = m_InternalId++;
			}
			
			Edge<T>(const Edge<T> & paramEdge) 
			{
				m_Id = m_InternalId++;
				m_Va = paramEdge.m_Va;
				m_Va = paramEdge.m_Vb;
			}
			
			inline long GetId(void) { return m_Id;};
			
			inline Vectice & GetVecticeA(void) { return m_Va;};
			inline Vectice & GetVecticeB(void) { return m_Vb;};
			inline const Vectice & GetVecticeA(void) const { return m_Va;};
			inline const Vectice & GetVecticeB(void) const { return m_Vb;};
			inline void SetVecticeA(const Vectice & paramVectice)  { m_Va = paramVectice;};
			inline void SetVecticeB(const Vectice & paramVectice)  { m_Vb = paramVectice;};

			Vectice m_Vb;
		};
	}
}
