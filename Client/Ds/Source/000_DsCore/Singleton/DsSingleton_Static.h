#pragma once

/*
* ΩÃ±€≈Ê ∆–≈œ
*/
template<class T>
class DsSingleton_Static
{
public:
	typedef T SingletonType;
	static T& Get() { return m_Instance; }


protected:	
	virtual ~DsSingleton_Static() {}


private:	
	static SingletonType m_Instance;
};

template<class T>
T DsSingleton_Static<T>::m_Instance;