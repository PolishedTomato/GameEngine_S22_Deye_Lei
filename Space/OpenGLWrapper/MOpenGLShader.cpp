#include "PCHeader.h"
#include "MOpenGLShader.h"
#include "glad/glad.h"

namespace Space {
    MOpenGLShader::MOpenGLShader(const std::string& vertexFile, const std::string& fragmentFile)
    {
        unsigned int VertexShader;
        glCreateShader(GL_VERTEX_SHADER);
        //FILE READING//

    }
    void MOpenGLShader::Bind()
    {
        glUseProgram(mShaderProgram);
    }
}
