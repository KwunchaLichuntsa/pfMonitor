/**
 * @file ThreadManager.h
 * @author usr.jasper (Jasper Groot)
 * @date 18/08/2015
 * @version concept
 * @brief 
 */

#ifndef THREADMANAGER_H
#define THREADMANAGER_H

#include "Singleton.h"

/**
 * //////////////////////////////////////////////////////////////////
 * @brief 
 * //////////////////////////////////////////////////////////////////
 */
class ThreadManager : public Singleton<ThreadManager>, IManager
{
	friend class Singleton<ThreadManager>;
	
	private:
		ThreadManager();
		virtual ~ThreadManager();
		
	protected:
		
	public:
		void vStartUp() override;
		void vShutDown() override;

};
typedef Singleton<ThreadManager> gThreadManager;
#endif // THREADMANAGER_H
