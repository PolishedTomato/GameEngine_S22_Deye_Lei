#include "PCHeader.h"
#include "MyShader.h"
#include "OpenGLWrapper/MOpenGLShader.h"
namespace Space {
	MyShader::MyShader(const std::string& vertexFile, const std::string& fragmentFile)
	{
#ifdef OpenGL
		mImplementation = new MOpenGLShader{ vertexFile, fragmentFile };
#else
		#only_OpenGL_is_supported_for_now
#endif
	}
	void MyShader::Bind()
	{
		mImplementaiton->Bind();
	}
}
