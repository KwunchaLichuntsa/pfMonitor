/**
 * @file INonCopyable.h
 * @author usr.jasper (Jasper Groot)
 * @date 18/08/2015
 * @version concept
 * @brief 
 */

#ifndef INONCOPYABLE_H
#define INONCOPYABLE_H

/**
 * //////////////////////////////////////////////////////////////////
 * @brief 
 * //////////////////////////////////////////////////////////////////
 */
class INonCopyable
{
	protected:
		INonCopyable() {}
		virtual ~INonCopyable() {}

	private:
		INonCopyable(const INonCopyable& rhs);
		INonCopyable& operator=(const INonCopyable& rhs);
};

/**
 * //////////////////////////////////////////////////////////////////
 * @brief 
 * //////////////////////////////////////////////////////////////////
 */
class IManager
{
	protected:
		IManager() {}
		virtual ~IManager() {}

	public:
		virtual void vStartUp() = 0;
		virtual void vShutDown() = 0;
};

#endif // INONCOPYABLE_H
