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
		void SetUniform3Ints(const std::string &uiformName, int val1, int val2, int val3);
		void SetUniform2Ints(const std::string& uiformName, int val1, int val2);
		void Bind();
	private:
		MyShaderImplementation* mImplementation;
	};

}

