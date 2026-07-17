#pragma once

#include "Shader.h"

namespace Wave {
	class Renderer
	{
	public:
		Renderer();
		~Renderer();

		Renderer(const Renderer&) = delete;
		Renderer& operator=(const Renderer&) = delete;

		void Render();

	private:
		Shader m_shader;

		unsigned int m_vertexArray = 0;
		unsigned int m_vertexBuffer = 0;
	};
}

