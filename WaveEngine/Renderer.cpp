#include "Renderer.h"
#include <GL/glew.h>

#include <stdexcept>
#include <string>

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
}

namespace Wave {
	Renderer::Renderer() : m_shader(VertexShaderSource, FragmentShaderSource)
	{

		const float vertices[] = {
			-0.5f, -0.5f, 0.0f,
			 0.5f, -0.5f, 0.0f,
			 0.0f,  0.5f, 0.0f
		};

		glGenVertexArrays(1, &m_vertexArray);
		glGenBuffers(1, &m_vertexBuffer);

		glBindVertexArray(m_vertexArray);

		glBindBuffer(GL_ARRAY_BUFFER, m_vertexBuffer);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);

		glEnableVertexArrayAttrib(m_vertexArray, 0);

		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindVertexArray(0);
	}

	Renderer::~Renderer()
	{
		glDeleteBuffers(1, &m_vertexBuffer);
		glDeleteVertexArrays(1, &m_vertexArray);
	}

	void Renderer::Render()
	{
		glClearColor(0.1f, 0.15f, 0.2f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		m_shader.Bind();
		glBindVertexArray(m_vertexArray);

		glDrawArrays(GL_TRIANGLES, 0, 3);

		glBindVertexArray(0);
		glUseProgram(0);
	}
}

