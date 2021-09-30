#pragma once
#include "ISingleton.h"

/*
* ΩÃ±€≈Ê ∆–≈œ
*/
template<class T>
class DsSingleton_Static : public ISingleton
{
public:
	typedef T SingletonType;
	static T& Get();


protected:	
	DsSingleton_Static() {}
	virtual ~DsSingleton_Static() {}


private:	
	static SingletonType m_Instance;
	static bool m_bInit;
};

template<class T>
T DsSingleton_Static<T>::m_Instance;

template<class T>
bool DsSingleton_Static<T>::m_bInit = false;

#include "DsSingleton_Static.hpp"