#include "Mesh.h"

#include <GL/glew.h>

#include <cstddef>

namespace Wave {
	Mesh::Mesh(const std::vector<Vertex>& vertices): m_vertexCount(static_cast<int>(vertices.size()))
	{
		glGenVertexArrays(1, &m_vertexArray);
		glGenBuffers(1, &m_vertexBuffer);

		glBindVertexArray(m_vertexArray);

		glBindBuffer(GL_ARRAY_BUFFER, m_vertexBuffer);

		glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), vertices.data(), GL_STATIC_DRAW);

		glVertexAttribPointer(
			0,
			3,
			GL_FLOAT,
			GL_FALSE,
			sizeof(Vertex),
			reinterpret_cast<void*>(offsetof(Vertex, position))
		);

		glEnableVertexAttribArray(0);

		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindVertexArray(0);
	}

	Mesh::~Mesh()
	{
		glDeleteBuffers(1, &m_vertexBuffer);
		glDeleteVertexArrays(1, &m_vertexArray);
	}
	void Mesh::Draw() const
	{
		glBindVertexArray(m_vertexArray);
		glDrawArrays(GL_TRIANGLES, 0, m_vertexCount);
		glBindVertexArray(0);
	}
}
