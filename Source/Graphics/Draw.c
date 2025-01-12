#include "Graphics/Draw.h"
#include <GL/gl.h>

void DrawRectangle(const int* width,const int* height,const struct Transform* transform)
{
	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(transform->position.x, transform->position.y);
	glVertex2f(transform->position.x, transform->position.y + *height);
	glVertex2f(transform->position.x + *width, transform->position.y + *height);
	glVertex2f(transform->position.x + *width, transform->position.y);
	glEnd();
}
