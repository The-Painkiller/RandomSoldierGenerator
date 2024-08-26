#pragma once
#include "Object.h"

class Prop : public Object
{
public:
	Prop() = delete;
	Prop(PropType type, GridCoordinates position);
	virtual ~Prop() { _type = DudProp; }

	virtual PropType GetPropType() = 0;
	GridCoordinates GetPosition() override;

protected:
	PropType _type = DudProp;
	void SetPosition(GridCoordinates position) override;
};