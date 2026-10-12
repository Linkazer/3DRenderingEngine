#pragma once

#include <Rendering\Data\ModelData.h>
#include <Rendering\OpenGL\Data\OpenglMeshData.h>

#include <vector>

class OpenglModelData : public ModelData
{
public :
	OpenglModelData();
	~OpenglModelData() override = default;

	inline const std::vector<OpenglMeshData>& GetMeshes() const { return meshes; }

private :
	std::vector<OpenglMeshData> meshes;
};