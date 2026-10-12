#pragma once

#include <Rendering\Data\MeshData.h>

class OpenglMeshData : public MeshData
{
public :
	OpenglMeshData();
	~OpenglMeshData() override = default;

	inline unsigned int GetVao() const { return vao; }
	inline unsigned int GetVab() const { return vbo; }
	inline unsigned int GetEbo() const { return ebo; }

private :
	unsigned int vao = 0;
	unsigned int vbo = 0;
	unsigned int ebo = 0;
};