#pragma once
namespace Space {
	class MyShaderImplementation {
	public:
		//~MyShaderImplementation();
		virtual void Bind() = 0;
		virtual void SetUniform3Ints(const std::string& uiformName, int val1, int val2, int val3) =0;
		virtual void SetUniform2Ints(const std::string& uiformName, int val1, int val2) =0;
	};
}