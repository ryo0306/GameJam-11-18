#pragma once

#include <memory>
#include <iostream>
#include <string>

#include "../../lib/framework.hpp"
#include "envSingleton.hpp"
#include "../Utility/Collision/collision.hpp"
#include "Resource Manager\resourceManager.hpp"

struct Box{
	Vec2f pos;
	Vec2f size;
};