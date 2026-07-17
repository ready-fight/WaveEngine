#pragma once

#include "Shader.h"
#include "Mesh.h"

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
		Mesh m_mesh;
	};
}

