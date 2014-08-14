#include "stdafx.h"
#include "TextureImporter.h"

namespace NetGL { namespace Toolkit {

TextureImporter::TextureImporter(void)
{
}

TextureImporter::TextureImporter(System::Drawing::Bitmap^ Texture)
{
	this->Bitmap = Texture;
}

void TextureImporter::BindTexture(NetGL::OpenGL^ gl)
{
	int textureint = gl->GenTextures(1);
	this->TextureID = textureint;
	gl->Enable(NetGL::OpenGL::AlphaTest);
	gl->AlphaFunc(NetGL::OpenGL::Greater, 0.1);
	gl->BindTexture(1, textureint);
	gl->TexParameteri(OpenGL::Texture2D, OpenGL::TextureMagFilter, OpenGL::NearestMipMapLinear);
	gl->TexParameteri(OpenGL::Texture2D, OpenGL::TextureMinFilter, OpenGL::NearestMipMapLinear);
	gl->TexParameteri(OpenGL::Texture2D, OpenGL::TextureWrapS, OpenGL::Clamp);
	gl->TexParameteri(OpenGL::Texture2D, OpenGL::TextureWrapT, OpenGL::Clamp);
	gl->Build2DMipmaps(OpenGL::Texture2D, 4, OpenGL::RGBA, OpenGL::UnsignedByte, this->Bitmap); 
}

void NetGL::Toolkit::TextureImporter::DeleteTexture(NetGL::OpenGL^ gl)
{
	gl->DeleteTextures(1, this->TextureID);
	gl->Disable(NetGL::OpenGL::AlphaTest);
}


}}
