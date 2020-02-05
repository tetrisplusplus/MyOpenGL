#include "ViewPoint.h"

#include <glm/gtc/matrix_transform.hpp>

ViewPoint::ViewPoint(glm::vec3 position, glm::vec3 lookat, glm::vec3 viewup)
	: position{ position }
{
	this->w = glm::normalize(position - lookat);
	this->u = glm::normalize(glm::cross(viewup, this->w));
	this->v = glm::normalize(glm::cross(this->w, this->u));
}

glm::vec3 ViewPoint::get_position() const
{
	return this->position;
}

glm::vec3 ViewPoint::get_u() const
{
	return this->u;
}

glm::vec3 ViewPoint::get_v() const
{
	return this->v;
}

glm::vec3 ViewPoint::get_w() const
{
	return this->w;
}

glm::mat4 ViewPoint::view_matrix() const
{
	return glm::lookAt(this->position, this->position - this->w, this->v);
}

void ViewPoint::translate(glm::vec3 moved)
{
	this->position += moved;
}

void ViewPoint::rotate(float angle_in_degrees, glm::vec3 axis_in_global)
{
	const glm::mat4 rot4 = glm::rotate(glm::identity<glm::mat4>(), glm::radians(angle_in_degrees), axis_in_global);
	const glm::mat3 rot3 = glm::mat3(rot4);

	// 基底ベクトルを回転させる。
	this->u = rot3 * this->u;
	this->v = rot3 * this->v;
	this->w = rot3 * this->w;
}

void ViewPoint::move_longitudinal(float distance)
{
	this->translate(-distance * this->w);
}

void ViewPoint::move_vertical(float distance)
{
	this->translate(distance * this->v);
}

void ViewPoint::move_horizontal(float distance)
{
	this->translate(distance * this->u);
}

void ViewPoint::rotate_pitch(float angle_in_degrees)
{
	this->rotate(angle_in_degrees, this->u);
}

void ViewPoint::rotate_yaw(float angle_in_degrees)
{
	this->rotate(angle_in_degrees, this->v);
}

void ViewPoint::rotate_roll(float angle_in_degrees)
{
	this->rotate(angle_in_degrees, this->w);
}
