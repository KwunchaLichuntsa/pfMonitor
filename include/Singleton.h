/**
 * @file Singleton.h
 * @author usr.jasper (Jasper Groot)
 * @date 18/08/2015
 * @version concept
 * @brief 
 */

#ifndef SINGLETON_H
#define SINGLETON_H
#include "INonCopyable.h"

/**
 * //////////////////////////////////////////////////////////////////
 * @brief 
 * //////////////////////////////////////////////////////////////////
 */
template <typename T>
class Singleton : INonCopyable
{
	public:
		static T& sGetInstance()
		{
			//static T m_Instance;
			//return m_Instance;
			return *Pointer();
		}
		static T* Pointer()
		{
			static T t;
			return &t;
		}

	protected:
		explicit Singleton<T>() {}

};

#endif // SINGLETON_H
