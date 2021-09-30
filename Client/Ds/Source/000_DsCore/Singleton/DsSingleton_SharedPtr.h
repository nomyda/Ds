#pragma once
#include "ISingleton.h"

/*
* ΩÃ±€≈Ê ∆–≈œ
*/
template<class T>
class DsSingleton_SharedPtr : public ISingleton
{
public:
	typedef TSharedPtr<T> SharedSingleton;
	static T& Get();


protected:	
	DsSingleton_SharedPtr() {}
	virtual ~DsSingleton_SharedPtr() {}


private:	
	static SharedSingleton m_Instance;
};

template<class T>
TSharedPtr<T> DsSingleton_SharedPtr<T>::m_Instance;

#include "DsSingleton_SharedPtr.hpp"