#pragma once

template<class T>
T& DsSingleton_SharedPtr<T>::Get()
{
	if (false == m_Instance.IsValid())
	{
		m_Instance = SharedSingleton(new T);
		m_Instance->OnNew();
	}

	return *m_Instance.Get();
}