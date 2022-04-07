#include "PCHeader.h"
#include "Pic.h"
#include "OpenGLWrapper/OpenGLWrapper.h"

Space::Pic::Pic(const std::string& filename)
{
#ifdef OpenGL
	P_Imp = new OpenGLWrapper{ filename };
#else
	#Only_OpenGL_is_supported_for_now
#endif
}

int Space::Pic::GetWidth() const
{
	
	return P_Imp->GetWidth();
}

int Space::Pic::GetHeight() const
{
	return P_Imp->GetHeight();
}

void Space::Pic::Bind()
{
	P_Imp->Bind();
}
