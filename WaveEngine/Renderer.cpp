#include "Renderer.h"

#include <GL/glew.h>

#include <vector>

#include <cstdint>

namespace
{
	const char* VertexShaderSource = R"(
        #version 460 core

        layout(location = 0) in vec3 position;

        void main()
        {
            gl_Position = vec4(position, 1.0);
        }
    )";

	const char* FragmentShaderSource = R"(
        #version 460 core

        out vec4 fragmentColor;

        void main()
        {
            fragmentColor = vec4(0.9, 0.4, 0.2, 1.0);
        }
    )";

	std::vector<Wave::Vertex> CreateTriangleVertices()
	{
		return
		{
			{{-0.5f, -0.5f, 0.0f}},
			{{ 0.5f, -0.5f, 0.0f}},
			{{ 0.0f,  0.5f, 0.0f}}
		};
	}

	std::vector<std::uint32_t> CreateTriangleIndices()
	{
		return
		{
			0, 1, 2
		};
	}
}

namespace Wave {
	Renderer::Renderer() : m_shader(VertexShaderSource, FragmentShaderSource), m_mesh(CreateTriangleVertices(), CreateTriangleIndices())
	{
	}

	Renderer::~Renderer()
	{
		
	}

	void Renderer::Render(float aspectRatio)
	{
		glClearColor(0.1f, 0.15f, 0.2f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		m_shader.Bind();
		m_mesh.Draw();
		m_shader.Unbind();
	}
}

