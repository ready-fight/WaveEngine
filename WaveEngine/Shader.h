#pragma once

namespace Wave
{
	class Shader
	{
	public:
		Shader(
			const char* vertexSource,
			const char* fragmentSource
		);

		~Shader();

		Shader(const Shader&) = delete;
		Shader& operator=(const Shader&) = delete;

		void Bind() const;
		void Unbind() const;

	private:
		unsigned int Compile(unsigned int type, const char* source);
		unsigned int m_program = 0;
	};

}


