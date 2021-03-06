#pragma once

#include <glm/glm.hpp>

class ViewPoint
{
private:
	glm::vec3 position;

	// Right-handed Orthonormal basis
	glm::vec3 u; // 右手方向
	glm::vec3 v; // 上方向
	glm::vec3 w; // 視線と反対方向

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
};
