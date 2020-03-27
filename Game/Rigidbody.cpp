#include "Rigidbody.h"

Rigidbody::Rigidbody()
{
	transform = &Entity->GetComponent<Transform>();
}
