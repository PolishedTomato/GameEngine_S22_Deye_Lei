#pragma once
#include "SpaceUtil.h"
#include "MyShaderImplementation.h"
#include "MyShaderImplementation.h"
namespace Space
{
	class GAME_API MyShader
	{
	public:
		MyShader(const std::string& vertexFile, const std::string& fragmentFile);
		void Bind();
	private:
		MyShaderImplementation* mImplementation;
	};

}

