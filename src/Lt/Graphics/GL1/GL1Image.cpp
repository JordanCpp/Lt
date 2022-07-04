#include <Lt/Graphics/GL1/GL1Image.hpp>
#include <Lt/Graphics/OpenGL.hpp>
#include <Lt/Core/Assert.hpp>

Lt::Graphics::GL1Image::GL1Image(Lt::Graphics::CpuImage* cpuImage):
	_Id(0)
{
	LT_ASSERT(cpuImage != nullptr);
	LT_ASSERT(cpuImage->Pixels() != nullptr);
	LT_ASSERT(cpuImage->Size().PosX() > 0);
	LT_ASSERT(cpuImage->Size().PosY() > 0);

	_Size = cpuImage->Size();

	glGenTextures(1, (GLuint*)&_Id);

	glBindTexture(GL_TEXTURE_2D, _Id);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	int format = 0;

	if (cpuImage->Channels() == 3)
		format = GL_RGB;
	else
		format = GL_RGBA;

	glTexImage2D(GL_TEXTURE_2D, 0, format, _Size.PosX(), _Size.PosY(), 0, format, GL_UNSIGNED_BYTE, cpuImage->Pixels());
}

Lt::Graphics::GL1Image::~GL1Image()
{
	glDeleteTextures(0, (GLuint*)&_Id);
}

const Lt::Graphics::Point2u& Lt::Graphics::GL1Image::Size()
{
	return _Size;
}