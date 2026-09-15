#pragma once
#include "./State/Stroke.h"
class NetworkManager{
private:
protected:
public:
	virtual Stroke* GiveStroke() = 0;
};