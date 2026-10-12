#include <Rendering\OpenGL\OpenglShader.h>

#include <glad/glad.h>

#include <fstream>
#include <sstream>
#include <iostream>

#include <filesystem>

#include <Engine\LogSystem\LogSystem.h>
#include <format>

void OpenglShader::LoadShader(const std::string vertexShaderPath, const std::string fragmentShaderPath)
{
    std::string vertexCode;
    std::string fragmentCode;
    std::ifstream vShaderFile;
    std::ifstream fShaderFile;
    // ensure ifstream objects can throw exceptions:
    vShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    fShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    try
    {
        // open files
        vShaderFile.open(vertexShaderPath);
        fShaderFile.open(fragmentShaderPath);
        std::stringstream vShaderStream, fShaderStream;
        // read file's buffer contents into streams
        vShaderStream << vShaderFile.rdbuf();
        fShaderStream << fShaderFile.rdbuf();
        // close file handlers
        vShaderFile.close();
        fShaderFile.close();
        // convert stream into string
        vertexCode = vShaderStream.str();
        fragmentCode = fShaderStream.str();
    }
    catch (std::ifstream::failure& e)
    {
        std::cout << "ERROR::SHADER::FILE_NOT_SUCCESSFULLY_READ: " << e.what() << std::endl;
    }

    //Vertex Shader
    const char* vShaderCode = vertexCode.c_str();
    unsigned int vertexShaderId;

    vertexShaderId = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShaderId, 1, &vShaderCode, NULL);
    glCompileShader(vertexShaderId);
    CheckCompileError(vertexShaderId, "VERTEX");

    //Fragment Shader
    const char* fShaderCode = fragmentCode.c_str();
    unsigned int fragmentShaderId;

    fragmentShaderId = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShaderId, 1, &fShaderCode, NULL);
    glCompileShader(fragmentShaderId);
    CheckCompileError(fragmentShaderId, "FRAGMENT");

    //Shader Program
    id = glCreateProgram();
    glAttachShader(id, vertexShaderId);
    glAttachShader(id, fragmentShaderId);
    glLinkProgram(id);
    CheckCompileError(id, "PROGRAM");

    //Clean
    glDeleteShader(vertexShaderId);
    glDeleteShader(fragmentShaderId);
}

void OpenglShader::Use()
{
    glUseProgram(id);
}

void OpenglShader::SetBool(const std::string& name, bool value)
{
    glUniform1i(glGetUniformLocation(id, name.c_str()), (int)value);
}

void OpenglShader::SetInt(const std::string & name, int value)
{
    glUniform1i(glGetUniformLocation(id, name.c_str()), value);
}

void OpenglShader::SetFloat(const std::string & name, float value)
{
    glUniform1f(glGetUniformLocation(id, name.c_str()), value);
}

void OpenglShader::SetVec2(const std::string & name, glm::vec2 value)
{
    glUniform2fv(glGetUniformLocation(id, name.c_str()), 1, &value[0]);
}

void OpenglShader::SetVec3(const std::string & name, glm::vec3 value)
{
    glUniform3fv(glGetUniformLocation(id, name.c_str()), 1, &value[0]);
}

void OpenglShader::SetVec4(const std::string & name, glm::vec4 value)
{
    glUniform4fv(glGetUniformLocation(id, name.c_str()), 1, &value[0]);
}

void OpenglShader::SetMat2(const std::string & name, glm::mat2 value)
{
    glUniformMatrix2fv(glGetUniformLocation(id, name.c_str()), 1, GL_FALSE, &value[0][0]);
}

void OpenglShader::SetMat3(const std::string & name, glm::mat3 value)
{
    glUniformMatrix3fv(glGetUniformLocation(id, name.c_str()), 1, GL_FALSE, &value[0][0]);
}

void OpenglShader::SetMat4(const std::string & name, glm::mat4 value)
{
    glUniformMatrix4fv(glGetUniformLocation(id, name.c_str()), 1, GL_FALSE, &value[0][0]);
}

void OpenglShader::CheckCompileError(GLuint shaderId, std::string type)
{
    GLint success;
    GLchar infoLog[1024];
    if (type != "PROGRAM")
    {
        glGetShaderiv(shaderId, GL_COMPILE_STATUS, &success);
        if (!success)
        {
            glGetShaderInfoLog(shaderId, 1024, NULL, infoLog);
            std::cout << "ERROR::SHADER_COMPILATION_ERROR of type: " << type << "\n" << infoLog << "\n -- --------------------------------------------------- -- " << std::endl;
        }
    }
    else
    {
        glGetProgramiv(shaderId, GL_LINK_STATUS, &success);
        if (!success)
        {
            glGetProgramInfoLog(shaderId, 1024, NULL, infoLog);
            std::cout << "ERROR::PROGRAM_LINKING_ERROR of type: " << type << "\n" << infoLog << "\n -- --------------------------------------------------- -- " << std::endl;
        }
    }
}
