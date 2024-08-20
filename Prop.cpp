#include "Prop.h"

Prop::Prop(PropType type, GridCoordinates position)
{
	_type = type;
	SetPosition(position);
}

void Prop::SetPosition(GridCoordinates position)
{
	_position = position;
}

GridCoordinates Prop::GetPosition()
{
	return _position;
}