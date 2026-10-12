#include <Rendering\Camera\Viewport.h>

//TEST
#include <iostream>
Viewport::Viewport()
	: transform(Transform())
	, camera(&transform)
{
	std::cout << "Pos X " << transform.GetPosition().x << std::endl;
}
