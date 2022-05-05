#include "PCHeader.h"
#include "MOpenGLShader.h"
#include "glad/glad.h"
#include "SpaceUtil.h"
namespace Space {
    MOpenGLShader::MOpenGLShader(const std::string& vertexFile, const std::string& fragmentFile)
    {
        //this code avoid exception
        gladLoadGL();
        //

        unsigned int VertexShader;
        VertexShader = glCreateShader(GL_VERTEX_SHADER);
        //FILE READING//
        std::string sourceCode;
        std::ifstream vertexInput{vertexFile};

        while (vertexInput)
        {
            std::string line;
            std::getline(vertexInput, line);
            
            line.append("\n");
            sourceCode += line;
            
        }
        vertexInput.close();

        const char* cSource = sourceCode.c_str();
        glShaderSource(VertexShader, 1, &cSource, NULL);
        glCompileShader(VertexShader);

        //error checking
        int success;
        char infoLog[512];
        glGetShaderiv(VertexShader, GL_COMPILE_STATUS, &success);
        if (!success)
        {
            glGetShaderInfoLog(VertexShader, 512, NULL, infoLog);
            std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog<<std::endl;
        }

        //fragment shader

        unsigned int fragmentShader;
        fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

        //file reading
        sourceCode.clear();
        std::ifstream fragmentInput{ fragmentFile };

        while (fragmentInput)
        {
            std::string line;
            std::getline(fragmentInput, line);
            line.append("\n");
            sourceCode += line;
        }
        //GAME_LOG(sourceCode);
        fragmentInput.close();

        const char* fragSource = sourceCode.c_str();
        glShaderSource(fragmentShader, 1, &fragSource, NULL);
        glCompileShader(fragmentShader);

        glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
        if (!success)
        {
            glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
            std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog<<std::endl;
        }

        //link shaders
        mShaderProgram = glCreateProgram();
        glAttachShader(mShaderProgram, VertexShader);
        glAttachShader(mShaderProgram, fragmentShader);
        glLinkProgram(mShaderProgram);

        glGetProgramiv(mShaderProgram, GL_LINK_STATUS, &success);
        if (!success)
        {
            glGetShaderInfoLog(mShaderProgram, 512, NULL, infoLog);
            std::cout << "ERROR::SHADER::PROGRAM::COMPILATION_FAILED\n" << infoLog<<std::endl;
        }

        glDeleteShader(VertexShader);
        glDeleteShader(fragmentShader);

    }
    void MOpenGLShader::Bind()
    {
        glUseProgram(mShaderProgram);
    }

    void MOpenGLShader::SetUniform3Ints(const std::string& uniformName, int val1, int val2, int val3)
    {
        int uniformLocation{ glGetUniformLocation(mShaderProgram, uniformName.c_str()) };
        glUseProgram(mShaderProgram);
        glUniform3i(uniformLocation, val1, val2, val3);
    }

    void MOpenGLShader::SetUniform2Ints(const std::string& uniformName, int val1, int val2)
    {
        int uniformLocation{ glGetUniformLocation(mShaderProgram, uniformName.c_str()) };
        glUseProgram(mShaderProgram);
        glUniform2i(uniformLocation, val1, val2);
    }
}
