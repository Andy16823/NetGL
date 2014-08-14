#include "stdafx.h"
#include "BitmapFormatConverter.h"

namespace NetGL { namespace Toolkit {

BitmapFormatConverter::BitmapFormatConverter(void)
{
}

// Convert ARGB to ABGR
System::Drawing::Bitmap^ NetGL::Toolkit::BitmapFormatConverter::CONVERT_ARGB_TO_ABGR(System::Drawing::Bitmap^ Image)
{
	System::Drawing::Bitmap^ newbmp = gcnew System::Drawing::Bitmap(Image);
	for(int i = 0; i < Image->Height; i++)
	{
		for(int ii = 0 ; ii < Image->Width; ii++)
		{
			System::Drawing::Color Color = Image->GetPixel(ii,i);
			System::Drawing::Color PCOL = System::Drawing::Color::FromArgb(Color.A, Color.B, Color.G, Color.R);
			newbmp->SetPixel(ii, i, PCOL);
		}
	}

	return newbmp;
}

}}
