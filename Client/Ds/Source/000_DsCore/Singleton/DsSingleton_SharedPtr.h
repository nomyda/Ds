#pragma once

/*
* ΩÃ±€≈Ê ∆–≈œ
*/
template<class T>
class DsSingleton_SharedPtr
{
public:
	typedef TSharedPtr<T> SharedSingleton;
	static T& Get();


protected:	
	virtual ~DsSingleton_SharedPtr() {}
	virtual void OnNew() = 0;


private:	
	static SharedSingleton m_Instance;
};

template<class T>
TSharedPtr<T> DsSingleton_SharedPtr<T>::m_Instance;

#include "DsSingleton_SharedPtr.hpp"