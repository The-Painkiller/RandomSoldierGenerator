#pragma once
#include "Object.h"

class Prop : public Object
{
public:
	Prop() = delete;
	Prop(PropType type, GridCoordinates position);
	virtual ~Prop(){}

	virtual PropType GetPropType() = 0;
	GridCoordinates GetPosition() override;

protected:
	PropType _type;
	void SetPosition(GridCoordinates position) override;
};