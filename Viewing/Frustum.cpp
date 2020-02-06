#include "Frustum.h"

#include <glm/gtc/matrix_transform.hpp>

PersFrustum::PersFrustum(float fovy, float aspect, float near, float far)
	: fovy{ fovy }, aspect{ aspect }, near_{ near }, far_{ far }
{
}

glm::mat4 PersFrustum::proj_matrix() const
{
	return glm::perspective(glm::radians(this->fovy), this->aspect, this->near_, this->far_);
}

float PersFrustum::get_fovy() const
{
	return this->fovy;
}

float PersFrustum::get_aspect() const
{
	return this->aspect;
}
