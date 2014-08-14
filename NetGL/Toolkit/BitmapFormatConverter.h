#pragma once
namespace NetGL { namespace Toolkit {
	
	public ref class BitmapFormatConverter
	{
	public:
		BitmapFormatConverter(void);
		System::Drawing::Bitmap^ CONVERT_ARGB_TO_ABGR(System::Drawing::Bitmap^ Bitmap);
	};

}}
