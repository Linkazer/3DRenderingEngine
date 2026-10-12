#pragma once

#include <string>
#include <glm\glm.hpp>

class Shader
{
public :
	Shader() = default;
	virtual ~Shader() = default;

	virtual void LoadShader(const std::string vertexShaderPath, const std::string fragmentShaderPath) = 0;

	inline unsigned int GetID() const { return id; }

	virtual void SetBool(const std::string& name, bool value) = 0;
	virtual void SetInt(const std::string& name, int value) = 0;
	virtual void SetFloat(const std::string& name, float value) = 0;
	virtual void SetVec2(const std::string& name, glm::vec2 value) = 0;
	virtual void SetVec3(const std::string& name, glm::vec3 value) = 0;
	virtual void SetVec4(const std::string& name, glm::vec4 value) = 0;
	virtual void SetMat2(const std::string& name, glm::mat2 value) = 0;
	virtual void SetMat3(const std::string& name, glm::mat3 value) = 0;
	virtual void SetMat4(const std::string& name, glm::mat4 value) = 0;

protected :
	unsigned int id;
};