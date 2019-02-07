#pragma once

#include "character.hpp"
#include "enemy.hpp"
#include "../mazeComponents/fixedComponent.hpp"

class Enemy;
class FixedComponent;

class Player : public Character
{
	static Texture fish_texture;
public:
	// Creates all the associated render resources and default transform
	bool init(vec2 initialPosition);
	
	// Update player position based on velocity vector
	// ms represents the number of milliseconds elapsed from the previous update() call
	void update(float ms);
	
	// Renders the player
	void draw(const mat3& projection)override;

	// Collision routines for enemies and fixed maze components
	//bool collides_with(const Turtle& turtle);
	//bool collides_with(const Fish& fish);

	// Returns the local bounding coordinates scaled by the current size of the fish 
	vec2 get_bounding_box()const;

	// Set the player's acceleration vector
	void set_acceleration(vec2 acc);

	// Update player's velocity based on acceleration
	void update_velocity();

	// Moves the player's position by the specified offset
	void move();

	// Let character know it's currently on a platform (and its position)
	void set_on_platform(double yPos);

	// Let character know it's currently in freefall
	void set_in_free_fall();

	// Change player's movement direction
	void set_direction(int key, int action);

	// Set player's rotation in radians
	void set_rotation(float radians);

	// True if the player is alive
	bool is_alive()const;

	// Kills the player, changing its alive state and triggering on death events
	void kill();

	bool isBelowPlatform;
	bool isLeftOfPlatform;
	bool isRightOfPlatform;
	double width;
	double height;

private:
	double tolerance = 0.000001;
	double maxVelocity = 12;
	double accStep = 2.f;
	double drag = 0.8;
	vec2 currentVelocity;
	vec2 currentAcceleration;
	bool isOnPlatform;
	double fakeFloorPos = 750.f;
	double currentFloorPos = fakeFloorPos;
	double gravityAcc = 9.81 * 0.2;
	double jumpVel = -25.f;
};