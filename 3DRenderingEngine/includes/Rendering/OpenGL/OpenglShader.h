#pragma once

#include <Rendering\Shader\Shader.h>

#include <string>
#include <glm/glm.hpp>
#include <glad/glad.h>

class OpenglShader : public Shader
{
public :
	OpenglShader() = default;
	~OpenglShader() override = default;

	void LoadShader(const std::string vertexShaderPath, const std::string fragmentShaderPath) override;

	void Use();

	void SetBool(const std::string& name, bool value) override;
	void SetInt(const std::string& name, int value) override;
	void SetFloat(const std::string& name, float value) override;
	void SetVec2(const std::string& name, glm::vec2 value) override;
	void SetVec3(const std::string& name, glm::vec3 value) override;
	void SetVec4(const std::string& name, glm::vec4 value) override;
	void SetMat2(const std::string& name, glm::mat2 value) override;
	void SetMat3(const std::string& name, glm::mat3 value) override;
	void SetMat4(const std::string& name, glm::mat4 value) override;

private :
	void CheckCompileError(GLuint shaderId, std::string type);
};