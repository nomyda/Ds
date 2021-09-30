#pragma once

class ISingleton
{
public:
	virtual ~ISingleton() {}
	virtual void OnSingleton() = 0;
};
