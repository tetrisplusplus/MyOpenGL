#pragma once

#include <glm/glm.hpp>

class ViewPoint
{
private:
	glm::vec3 position;

	// Right-handed Orthonormal basis
	glm::vec3 u; // ‰Eè•ûŒü
	glm::vec3 v; // ã•ûŒü
	glm::vec3 w; // ‹ü‚Æ”½‘Î•ûŒü

public:
	ViewPoint(glm::vec3 position, glm::vec3 lookat, glm::vec3 viewup);

public:
	glm::vec3 get_position() const;
	glm::vec3 get_u() const;
	glm::vec3 get_v() const;
	glm::vec3 get_w() const;

public:
	glm::mat4 view_matrix() const;

public:
	void translate(glm::vec3 moved);

	void rotate(float angle_in_degrees, glm::vec3 axis_in_global);


public:
	void move_longitudinal(float distance);
	void move_vertical(float distance);
	void move_horizontal(float distance);

public:
	void rotate_pitch(float angle_in_degrees);
	void rotate_yaw(float angle_in_degrees);
	void rotate_roll(float angle_in_degrees);
};

