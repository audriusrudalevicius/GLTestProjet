#include "Model.h"

Model::Model(const std::vector<GLfloat>& vertexPositions)
{
	// See: https://cognitivewaves.wordpress.com/opengl-terminology-demystified/
	glGenBuffers(1, &m_vertexId);
	glBindBuffer(GL_ARRAY_BUFFER, m_vertexId);

	glBufferData(GL_ARRAY_BUFFER, vertexPositions.size() * sizeof(vertexPositions[0]), vertexPositions.data(), GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (GLvoid *) 0);
}

Model::~Model()
{
	glDeleteBuffers(1, &m_vertexId);
}

void Model::bind()
{
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, m_vertexId);
}

void Model::unbind()
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glDisableVertexAttribArray(0);
}