#pragma once

#include <glm/vec3.hpp>

#include <vector>

namespace Wave {

	struct Vertex
	{
		glm::vec3 position;
	};

	class Mesh
	{
	public:
		explicit Mesh(const std::vector<Vertex>& vertices);
		~Mesh();

		Mesh(const Mesh&) = delete;
		Mesh& operator=(const Mesh&) = delete;

		void Draw() const;

	private:
		unsigned int m_vertexArray = 0;
		unsigned int m_vertexBuffer = 0;
		int m_vertexCount = 0;
	};
}


