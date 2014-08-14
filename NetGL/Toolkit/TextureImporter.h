#pragma once
#include "NetGL.h"

namespace NetGL{ namespace Toolkit{

	

public ref class TextureImporter
{
public:
	TextureImporter(void);
	TextureImporter(System::Drawing::Bitmap^ Texture);
	void BindTexture(OpenGL^ opengl);
	void DeleteTexture(OpenGL^ opengl);
	int TextureID;
private:
	
	System::Drawing::Bitmap^ Bitmap;


};
}}
