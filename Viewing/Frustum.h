#pragma once

#include <glm/glm.hpp>

class PersFrustum
{
private:
	float fovy; // angle in the y-direction
	float aspect; // (x/y, width/height);
	float near_;
	float far_;

public:
	PersFrustum(float fovy, float aspect, float near, float far);

public:
	glm::mat4 proj_matrix() const;

	float get_fovy() const;
	float get_aspect() const;
};
