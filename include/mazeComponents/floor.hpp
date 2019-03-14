#pragma once

#include "fixedComponent.hpp"

class Floor : public FixedComponent
{
    static Texture texture;

public:

    bool init(vec2 position)override;

    // Renders the component
	void draw(const mat3& projection)override;

	vec2 get_position()const;

};