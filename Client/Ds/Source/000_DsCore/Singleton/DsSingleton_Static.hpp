#pragma once

template<class T>
T& DsSingleton_Static<T>::Get()
{
	if (false == m_bInit)
	{
		m_bInit = true;
		m_Instance.OnSingleton();
	}

	return m_Instance;
}