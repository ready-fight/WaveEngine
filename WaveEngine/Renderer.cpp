#include "Renderer.h"
#include "Camera.h"

#include <GL/glew.h>

#include <glm/gtc/matrix_transform.hpp>

#include <cstdint>
#include <vector>


namespace
{
	const char* VertexShaderSource = R"(
        #version 460 core

        layout(location = 0) in vec3 position;

		uniform mat4 model;
		uniform mat4 view;
		uniform mat4 projection;

        void main()
        {
            gl_Position = projection * view * model * vec4(position, 1.0);
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
	Renderer::Renderer() : m_shader(VertexShaderSource, FragmentShaderSource), m_model("Assets/Models/FinalBaseMesh.obj")
	{
		glEnable(GL_DEPTH_TEST);
	}

	Renderer::~Renderer()
	{
		
	}

	void Renderer::Render(float aspectRatio, Camera& camera)
	{
		glClearColor(0.1f, 0.15f, 0.2f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glm::mat4 model(1.0);

		model = glm::rotate(model, glm::radians(-20.0f), glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::scale(model, glm::vec3(0.05f));

		const glm::mat4 view = camera.GetViewMatrix();

		const glm::mat4 projection = camera.GetProjectMatrix(aspectRatio);

		m_shader.Bind();

		m_shader.SetMatrix4("model", model);
		m_shader.SetMatrix4("view", view);
		m_shader.SetMatrix4("projection", projection);

		m_model.Draw();
		m_shader.Unbind();
	}
}

